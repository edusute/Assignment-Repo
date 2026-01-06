# AI Lesson 0Xb: SQLite Basics and Python

## Learning Objectives
- Create SQLite databases with Python
- Create tables with specific columns and data types
- Insert data into tables
- Query (retrieve) data from databases
- Understand basic SQL commands
- Connect Python to SQLite

## The Connection: Python + SQLite

You already know Python. SQLite works right inside Python!

**How it works:**
```
Python Program ←→ SQLite Database File
```

Python has a built-in library called `sqlite3` that lets you talk to databases.

## SQL: The Language of Databases

**SQL** (Structured Query Language) is how you talk to databases. It's simple English-like commands.

### The Big Four SQL Commands

Most database work uses just 4 commands:

| Command | What It Does | Example |
|---------|-------------|---------|
| **CREATE** | Build a new table | `CREATE TABLE movies ...` |
| **INSERT** | Add data | `INSERT INTO movies ...` |
| **SELECT** | Get/retrieve data | `SELECT * FROM movies` |
| **UPDATE** | Change existing data | `UPDATE movies SET ...` |

We'll focus on CREATE, INSERT, and SELECT first.

## Setting Up: Your First Database

### Step 1: Import the Library

```python
import sqlite3
```

That's it! SQLite is built into Python.

### Step 2: Connect to (or Create) a Database

```python
import sqlite3

# This creates a new file called movies.db
# If it already exists, it just opens it
connection = sqlite3.connect('movies.db')
cursor = connection.cursor()
```

**What's happening:**
- `sqlite3.connect('movies.db')` → Opens/creates the database file
- `connection.cursor()` → Creates a "cursor" (like a pen to write with)

### Step 3: Close When Done

```python
connection.commit()  # Save changes
connection.close()   # Close the connection
```

## Creating Tables

### The Template

```python
import sqlite3

connection = sqlite3.connect('movies.db')
cursor = connection.cursor()

# Create a table
cursor.execute('''
    CREATE TABLE movies (
        id INTEGER,
        title TEXT,
        genre TEXT,
        rating REAL
    )
''')

connection.commit()
connection.close()
```

**Breaking it down:**
- `cursor.execute()` → Runs a SQL command
- `CREATE TABLE movies` → Create a new table called "movies"
- `(id INTEGER, title TEXT, ...)` → Define the columns and types

### Example: Movie Table

```python
import sqlite3

connection = sqlite3.connect('movie_database.db')
cursor = connection.cursor()

cursor.execute('''
    CREATE TABLE movies (
        id INTEGER,
        title TEXT,
        genre TEXT,
        rating REAL,
        release_year INTEGER
    )
''')

print("✅ Movie table created!")

connection.commit()
connection.close()
```

**Output:**
```
✅ Movie table created!
```

Now you have a `movie_database.db` file with an empty movies table!

### Example: Game Scores Table

```python
cursor.execute('''
    CREATE TABLE high_scores (
        id INTEGER,
        player_name TEXT,
        score INTEGER,
        date_achieved TEXT
    )
''')
```

## Inserting Data

Once you have a table, you need to add data to it.

### The Template

```python
cursor.execute('''
    INSERT INTO table_name (column1, column2, column3)
    VALUES (value1, value2, value3)
''')
```

### Example: Adding Movies

```python
import sqlite3

connection = sqlite3.connect('movie_database.db')
cursor = connection.cursor()

# Add one movie
cursor.execute('''
    INSERT INTO movies (id, title, genre, rating, release_year)
    VALUES (1, 'The Matrix', 'Sci-Fi', 8.7, 1999)
''')

# Add another movie
cursor.execute('''
    INSERT INTO movies (id, title, genre, rating, release_year)
    VALUES (2, 'Inception', 'Sci-Fi', 8.8, 2010)
''')

connection.commit()
connection.close()

print("✅ Movies added!")
```

**Important:** `connection.commit()` saves the changes to the file!

### Adding Multiple Records at Once

```python
movies_list = [
    (1, 'The Matrix', 'Sci-Fi', 8.7, 1999),
    (2, 'Inception', 'Sci-Fi', 8.8, 2010),
    (3, 'The Dark Knight', 'Action', 9.0, 2008),
    (4, 'Avatar', 'Sci-Fi', 7.8, 2009)
]

for movie in movies_list:
    cursor.execute('''
        INSERT INTO movies (id, title, genre, rating, release_year)
        VALUES (?, ?, ?, ?, ?)
    ''', movie)

connection.commit()
```

**Note:** The `?` placeholders are filled in from the tuple. This is safer than putting values directly in the SQL!

## Querying Data: SELECT

Now for the fun part - getting data back out!

### The Template

```python
cursor.execute('SELECT * FROM table_name')
results = cursor.fetchall()
```

### Example 1: Get All Movies

```python
import sqlite3

connection = sqlite3.connect('movie_database.db')
cursor = connection.cursor()

# Get all movies
cursor.execute('SELECT * FROM movies')
all_movies = cursor.fetchall()

print("All movies:")
for movie in all_movies:
    print(movie)

connection.close()
```

**Output:**
```
All movies:
(1, 'The Matrix', 'Sci-Fi', 8.7, 1999)
(2, 'Inception', 'Sci-Fi', 8.8, 2010)
(3, 'The Dark Knight', 'Action', 9.0, 2008)
(4, 'Avatar', 'Sci-Fi', 7.8, 2009)
```

### Making Output Prettier

```python
cursor.execute('SELECT * FROM movies')
movies = cursor.fetchall()

print("-" * 60)
print(f"{'ID':<4} {'Title':<20} {'Genre':<10} {'Rating':<8} {'Year':<6}")
print("-" * 60)

for movie in movies:
    id, title, genre, rating, year = movie
    print(f"{id:<4} {title:<20} {genre:<10} {rating:<8} {year:<6}")

print("-" * 60)
```

**Output:**
```
------------------------------------------------------------
ID   Title                Genre      Rating   Year
------------------------------------------------------------
1    The Matrix           Sci-Fi     8.7      1999
2    Inception            Sci-Fi     8.8      2010
3    The Dark Knight      Action     9.0      2008
4    Avatar               Sci-Fi     7.8      2009
------------------------------------------------------------
```

### Selecting Specific Columns

You don't always need all columns!

```python
# Get only titles and ratings
cursor.execute('SELECT title, rating FROM movies')
results = cursor.fetchall()

for title, rating in results:
    print(f"{title}: {rating}/10")
```

**Output:**
```
The Matrix: 8.7/10
Inception: 8.8/10
The Dark Knight: 9.0/10
Avatar: 7.8/10
```

## Filtering Data: WHERE

The **WHERE** clause lets you get only specific records.

### Template

```python
cursor.execute('SELECT * FROM table_name WHERE condition')
```

### Example 1: Find Movies with High Ratings

```python
# Get movies with rating >= 9.0
cursor.execute('SELECT * FROM movies WHERE rating >= 9.0')
top_movies = cursor.fetchall()

print("Top-rated movies:")
for movie in top_movies:
    print(movie)
```

**Output:**
```
Top-rated movies:
(3, 'The Dark Knight', 'Action', 9.0, 2008)
```

### Example 2: Find Movies by Genre

```python
# Get all Sci-Fi movies
cursor.execute('SELECT * FROM movies WHERE genre = ?', ('Sci-Fi',))
scifi_movies = cursor.fetchall()

for movie in scifi_movies:
    print(movie)
```

**Output:**
```
(1, 'The Matrix', 'Sci-Fi', 8.7, 1999)
(2, 'Inception', 'Sci-Fi', 8.8, 2010)
(4, 'Avatar', 'Sci-Fi', 7.8, 2009)
```

### Common WHERE Conditions

```python
# Greater than
cursor.execute('SELECT * FROM movies WHERE rating > 8.5')

# Less than
cursor.execute('SELECT * FROM movies WHERE release_year < 2000')

# Equal to
cursor.execute('SELECT * FROM movies WHERE genre = ?', ('Action',))

# Not equal to
cursor.execute('SELECT * FROM movies WHERE genre != ?', ('Horror',))

# AND (both conditions must be true)
cursor.execute('SELECT * FROM movies WHERE genre = ? AND rating > 8.5', ('Sci-Fi',))

# OR (either condition can be true)
cursor.execute('SELECT * FROM movies WHERE genre = ? OR genre = ?', ('Action', 'Sci-Fi'))
```

## Putting It Together: Complete Program

Here's a working example that creates, adds data, and queries:

```python
import sqlite3

# Connect to database (creates if doesn't exist)
connection = sqlite3.connect('movies.db')
cursor = connection.cursor()

# Create table
print("📊 Creating movies table...")
cursor.execute('''
    CREATE TABLE IF NOT EXISTS movies (
        id INTEGER,
        title TEXT,
        genre TEXT,
        rating REAL
    )
''')

# Add some movies
print("🎬 Adding movies...")
movies = [
    (1, 'The Matrix', 'Sci-Fi', 8.7),
    (2, 'Inception', 'Sci-Fi', 8.8),
    (3, 'The Dark Knight', 'Action', 9.0),
    (4, 'Pulp Fiction', 'Crime', 8.9)
]

for movie in movies:
    cursor.execute('''
        INSERT INTO movies (id, title, genre, rating)
        VALUES (?, ?, ?, ?)
    ''', movie)

# Display all movies
print("\n" + "="*50)
print("ALL MOVIES")
print("="*50)

cursor.execute('SELECT * FROM movies')
for movie in cursor.fetchall():
    id, title, genre, rating = movie
    print(f"{id}. {title} ({genre}) - Rating: {rating}")

# Find high-rated movies
print("\n" + "="*50)
print("HIGH-RATED MOVIES (> 8.7)")
print("="*50)

cursor.execute('SELECT * FROM movies WHERE rating > 8.7')
for movie in cursor.fetchall():
    id, title, genre, rating = movie
    print(f"{title}: {rating}/10")

# Save and close
connection.commit()
connection.close()

print("\n✅ Done!")
```

**Output:**
```
📊 Creating movies table...
🎬 Adding movies...

==================================================
ALL MOVIES
==================================================
1. The Matrix (Sci-Fi) - Rating: 8.7
2. Inception (Sci-Fi) - Rating: 8.8
3. The Dark Knight (Action) - Rating: 9.0
4. Pulp Fiction (Crime) - Rating: 8.9

==================================================
HIGH-RATED MOVIES (> 8.7)
==================================================
Inception: 8.8/10
The Dark Knight: 9.0/10
Pulp Fiction: 8.9/10

✅ Done!
```

## Important: CREATE TABLE IF NOT EXISTS

Notice the `IF NOT EXISTS` part?

```python
cursor.execute('''
    CREATE TABLE IF NOT EXISTS movies (
        ...
    )
''')
```

This prevents an error if the table already exists. Good practice!

## Common Mistakes

### Mistake 1: Forgetting to Commit

```python
# WRONG - Changes not saved!
cursor.execute('INSERT INTO movies ...')
connection.close()

# RIGHT
cursor.execute('INSERT INTO movies ...')
connection.commit()
connection.close()
```

### Mistake 2: Forgetting to Fetch Results

```python
# WRONG - Query runs but you don't get the data
cursor.execute('SELECT * FROM movies')

# RIGHT
cursor.execute('SELECT * FROM movies')
results = cursor.fetchall()
```

### Mistake 3: Using Direct Values Instead of ?

```python
# WRONG - Can cause errors or security issues
user_input = "Action"
cursor.execute(f"SELECT * FROM movies WHERE genre = '{user_input}'")

# RIGHT - Use placeholders
cursor.execute("SELECT * FROM movies WHERE genre = ?", (user_input,))
```

## Key Points

1. **Import sqlite3** - Built into Python
2. **connect()** - Open/create database file
3. **cursor()** - Tool to run commands
4. **CREATE TABLE** - Define table structure
5. **INSERT** - Add data
6. **SELECT** - Get data back
7. **WHERE** - Filter results
8. **commit()** - Save changes
9. **close()** - Close connection

## Vocabulary

- **Database:** File storing organized data
- **Table:** Collection of related records
- **Row:** One complete record
- **Column:** One type of data
- **SQL:** Language for talking to databases
- **Cursor:** Tool to run SQL commands
- **Query:** Request for data from database
- **Schema:** Table structure (columns and types)

## Practice

Try this yourself:

1. Create a `students.db` database
2. Create a `students` table with columns: id, name, grade, gpa
3. Add 5 students
4. Query all students
5. Find students with GPA > 3.5

## Looking Ahead

Next lesson: We'll combine databases with the decision trees from Week 1!

You'll create programs that:
- Store data in databases
- Query that data
- Make decisions based on the data
- Update the database based on decisions

---

**Brain Break:** A database is just organized storage. Think of it like organizing your photos by folder vs. having them all scattered on your desktop!