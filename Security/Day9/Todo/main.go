package main

import (
	"fmt"
	"net/http"
	"os"
	"strconv"
	"strings"
	"time"

	"github.com/gin-gonic/gin"
	"github.com/go-playground/validator/v10"
	"github.com/golang-jwt/jwt/v5"

	"github.com/ulule/limiter/v3"
	mgin "github.com/ulule/limiter/v3/drivers/middleware/gin"
	"github.com/ulule/limiter/v3/drivers/store/memory"

	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

var db *gorm.DB
var jwtSecret string

type Todo struct {
	ID   uint   `json:"id" gorm:"primaryKey"`
	Task string `json:"task" validate:"required,min=3,max=100" gorm:"not null"`
}

type User struct {
	Username string
	Password string
	Role     string
}

var dummyUsers = map[string]User{
	"abhay": {Username: "abhay", Password: "password123", Role: "admin"},
	"guest": {Username: "guest", Password: "guestpass", Role: "user"},
}

type LoginRequest struct {
	Username string `json:"username"`
	Password string `json:"password"`
}

func initDB() {
	var err error
	db, err = gorm.Open(sqlite.Open("todos.db"), &gorm.Config{})
	if err != nil {
		panic("Failed to connect to database: " + err.Error())
	}

	// Auto migrate the schema
	err = db.AutoMigrate(&Todo{})
	if err != nil {
		panic("Failed to migrate database: " + err.Error())
	}

	fmt.Println("Database initialized successfully")
}

func authMiddleware() gin.HandlerFunc {
	return func(c *gin.Context) {
		authHeader := c.GetHeader("Authorization")
		if authHeader == "" {
			c.JSON(http.StatusUnauthorized, gin.H{"error": "Authorization header required"})
			c.Abort()
			return
		}
		tokenStr := authHeader
		if strings.HasPrefix(authHeader, "Bearer ") {
			tokenStr = strings.TrimPrefix(authHeader, "Bearer ")
		}
		claims := jwt.MapClaims{}
		token, err := jwt.ParseWithClaims(tokenStr, &claims, func(token *jwt.Token) (interface{}, error) {
			if _, ok := token.Method.(*jwt.SigningMethodHMAC); !ok {
				return nil, fmt.Errorf("unexpected signing method: %v", token.Header["alg"])
			}
			return []byte(jwtSecret), nil
		})
		if err != nil || !token.Valid {
			c.JSON(http.StatusUnauthorized, gin.H{"error": "Invalid or expired token"})
			c.Abort()
			return
		}
		c.Set("username", claims["username"])
		c.Set("role", claims["role"])
		c.Next()
	}
}

func main() {
	jwtSecret = os.Getenv("JWT_SECRET")
	if jwtSecret == "" {
		panic("JWT_SECRET environment variable not set or empty")
	}

	// Initialize database
	initDB()

	r := gin.Default()

	// Apply rate limiter
	rate, _ := limiter.NewRateFromFormatted("10-M")
	store := memory.NewStore()
	rateLimiter := limiter.New(store, rate)
	r.Use(mgin.NewMiddleware(rateLimiter))

	// Login endpoint (public)
	r.POST("/login", func(c *gin.Context) {
		var req LoginRequest
		if err := c.BindJSON(&req); err != nil {
			c.JSON(http.StatusBadRequest, gin.H{"error": "Invalid JSON"})
			return
		}
		user, exists := dummyUsers[req.Username]
		if !exists || user.Password != req.Password {
			c.JSON(http.StatusUnauthorized, gin.H{"error": "Invalid credentials"})
			return
		}
		token := jwt.NewWithClaims(jwt.SigningMethodHS256, jwt.MapClaims{
			"username": user.Username,
			"role":     user.Role,
			"exp":      time.Now().Add(time.Minute * 15).Unix(),
		})
		tokenString, err := token.SignedString([]byte(jwtSecret))
		if err != nil {
			c.JSON(http.StatusInternalServerError, gin.H{"error": "Failed to generate token"})
			return
		}
		c.JSON(http.StatusOK, gin.H{"token": tokenString})
	})

	// Public routes: GETs
	r.GET("/todos", func(c *gin.Context) {
		var todos []Todo
		result := db.Find(&todos)
		if result.Error != nil {
			c.JSON(http.StatusInternalServerError, gin.H{"error": "Database error"})
			return
		}
		c.JSON(http.StatusOK, todos)
	})

	r.GET("/todos/:id", func(c *gin.Context) {
		idStr := c.Param("id")
		id, err := strconv.Atoi(idStr)
		if err != nil {
			c.JSON(http.StatusBadRequest, gin.H{"error": "Invalid ID"})
			return
		}

		var todo Todo
		result := db.First(&todo, id)
		if result.Error != nil {
			if result.Error == gorm.ErrRecordNotFound {
				c.JSON(http.StatusNotFound, gin.H{"error": "Todo not found"})
				return
			}
			c.JSON(http.StatusInternalServerError, gin.H{"error": "Database error"})
			return
		}
		c.JSON(http.StatusOK, todo)
	})

	// Protected group: POST, PUT, DELETE
	protected := r.Group("/todos")
	protected.Use(authMiddleware())
	{
		protected.POST("", func(c *gin.Context) {
			var newTodo Todo
			if err := c.BindJSON(&newTodo); err != nil {
				c.JSON(http.StatusBadRequest, gin.H{"error": "Invalid JSON"})
				return
			}

			validate := validator.New()
			if err := validate.Struct(&newTodo); err != nil {
				if validationErrs, ok := err.(validator.ValidationErrors); ok {
					errorMessages := make(map[string]string)
					for _, e := range validationErrs {
						errorMessages[e.Field()] = "Constraint failed: " + e.Tag()
					}
					c.JSON(http.StatusBadRequest, gin.H{"errors": errorMessages})
					return
				}
			}

			result := db.Create(&newTodo)
			if result.Error != nil {
				c.JSON(http.StatusInternalServerError, gin.H{"error": "Failed to create todo"})
				return
			}

			c.JSON(http.StatusCreated, newTodo)
		})

		protected.PUT("/:id", func(c *gin.Context) {
			idStr := c.Param("id")
			id, err := strconv.Atoi(idStr)
			if err != nil {
				c.JSON(http.StatusBadRequest, gin.H{"error": "Invalid ID"})
				return
			}

			var updatedTodo Todo
			if err := c.BindJSON(&updatedTodo); err != nil {
				c.JSON(http.StatusBadRequest, gin.H{"error": "Invalid JSON"})
				return
			}

			validate := validator.New()
			if err := validate.Struct(&updatedTodo); err != nil {
				if validationErrs, ok := err.(validator.ValidationErrors); ok {
					errorMessages := make(map[string]string)
					for _, e := range validationErrs {
						errorMessages[e.Field()] = "Constraint failed: " + e.Tag()
					}
					c.JSON(http.StatusBadRequest, gin.H{"errors": errorMessages})
					return
				}
			}

			var todo Todo
			result := db.First(&todo, id)
			if result.Error != nil {
				if result.Error == gorm.ErrRecordNotFound {
					c.JSON(http.StatusNotFound, gin.H{"error": "Todo not found"})
					return
				}
				c.JSON(http.StatusInternalServerError, gin.H{"error": "Database error"})
				return
			}

			todo.Task = updatedTodo.Task
			db.Save(&todo)

			c.JSON(http.StatusOK, todo)
		})

		protected.DELETE("/:id", func(c *gin.Context) {
			idStr := c.Param("id")
			id, err := strconv.Atoi(idStr)
			if err != nil {
				c.JSON(http.StatusBadRequest, gin.H{"error": "Invalid ID"})
				return
			}

			result := db.Delete(&Todo{}, id)
			if result.Error != nil {
				c.JSON(http.StatusInternalServerError, gin.H{"error": "Failed to delete todo"})
				return
			}

			if result.RowsAffected == 0 {
				c.JSON(http.StatusNotFound, gin.H{"error": "Todo not found"})
				return
			}

			c.Status(http.StatusNoContent)
		})
	}

	r.Run(":8080")
}
