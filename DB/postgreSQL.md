# what is database?
A database is an organized collection of data that is stored and accessed electronically. It allows for efficient retrieval, management, and manipulation of data. Databases can be managed using Database Management Systems (DBMS) such as PostgreSQL, MySQL, Oracle, and SQL Server. They are used in various applications, from simple data storage to complex data analysis and transaction processing.

# PostgreSQL
PostgreSQL, often referred to as Postgres, is an open-source relational database management system (RDBMS) that emphasizes extensibility and SQL compliance. It is known for its robustness, scalability, and support for advanced data types and performance optimization features.


# SQL (Structured Query Language)
SQL is a standard programming language used to manage and manipulate relational databases.
Easy to learn and widely used for querying, updating, and managing data in databases.

# How data is stored?

Stored in tables, which consist of rows and columns.
Table - person
            | ID | Name   | Age |      (attributes/columns)
            |----|--------|-----|----------------
            | 1  | Alice  | 30  |       (rows/records/ entities)
            | 2  | Bob    | 25  |
            | 3  | Charlie| 35  |

# what is relational database?
A relational database is a type of database that stores data in tables with rows and columns. It uses relationships between tables to organize and retrieve data efficiently. Each table has a unique key (primary key) to identify records, and relationships can be established using foreign keys.

# how to install postgreSQL in ubuntu?
1. Update the package list:
    ```bash
    sudo apt update
    ```
2. Install PostgreSQL:
    ```bash
    sudo apt install postgresql postgresql-contrib
    ```
3. Start the PostgreSQL service:
    ```bash
    sudo systemctl start postgresql
    ```
4. Enable PostgreSQL to start on boot:
    ```bash
    sudo systemctl enable postgresql
    ```
5. Verify the installation:
    ```bash
    psql --version
    ```

# how to access postgreSQL?
To access PostgreSQL, you can use the `psql` command-line tool. Here are the steps to access PostgreSQL:
1. Switch to the PostgreSQL user:
    ```bash
    sudo -i -u postgres
    ``` 
2. Access the PostgreSQL prompt:
    ```bash
    psql
    ```
3. You can now execute SQL commands at the PostgreSQL prompt. To exit, type:
    ```sql
    \q
    ```

# How to connect to postgreSQL database ?

1. Connect using client
2. GUI Client (like pgAdmin)
3. Terminal/Command Line
4. Application Code (using libraries like psycopg2 for Python, pg for Node.js, etc.)

# Basic SQL commands in PostgreSQL
1. \l - List all databases
2. CREATE DATABASE DB_NAME (Prefer Captial to identify SQL Syntax) - Create a new database
    Output: CREATE DATABASE
3. Connect to a database

For local database (without password):
    # Method 1: Switch to postgres user first
    sudo -i -u postgres
    psql -d test

    # Method 2: Direct connection
    sudo -u postgres psql -d test

    using \c command inside psql prompt:
    \c DB_NAME

4. Delete Database
    DROP DATABASE DB_NAME;
    Output: DROP DATABASE
5. How to 



# Step by step guide to create a table and