# Variables
CXX = g++
CXXFLAGS = -Wall -g
OBJ = main.o helper.o
TARGET = app

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile main.cpp to main.o
main.o: main.cpp main.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile helper.cpp to helper.o
helper.o: helper.cpp helper.h
	$(CXX) $(CXXFLAGS) -c helper.cpp

# Clean target to remove build artifacts
clean:
	rm -f *.o $(TARGET)
