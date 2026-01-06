# AI Lesson 0Xc: Databases + Decision Trees (AI Integration)

## Learning Objectives
- Combine databases with decision tree logic
- Use database queries to inform decisions
- Track decisions and outcomes in a database
- Build intelligent systems that learn from stored data
- Understand how real-world AI systems use both databases and decision logic

## Remember: These Two Worlds

### Week 1: Decision Trees
```python
if age >= 13:
    if has_violence == "yes":
        print("Approved")
```
**Problem:** No memory. Doesn't learn from past decisions.

### Week 2: Databases
```python
cursor.execute('SELECT * FROM movies WHERE rating > 8.5')
```
**Problem:** Just stores data. Doesn't make intelligent decisions.

### This Lesson: Combining Them! 🚀

```python
# Query database for user preferences
cursor.execute('SELECT favorite_genre FROM users WHERE id = ?', (user_id,))
preference = cursor.fetchone()

# Make decision based on database data
if preference == "Action":
    recommend_action_movies()
```

**This is how real AI systems work!**

## Real-World Example: Movie Recommender

Let's build a Netflix-style recommender system.

### Phase 1: The Database

First, we need to store information:

```python
import sqlite3

connection = sqlite3.connect('movie_recommender.db')
cursor = connection.cursor()

# Create users table
cursor.execute('''
    CREATE TABLE IF NOT EXISTS users (
        user_id INTEGER,
        username TEXT,
        favorite_genre TEXT,
        preferred_rating REAL
    )
''')

# Create movies table
cursor.execute('''
    CREATE TABLE IF NOT EXISTS movies (
        movie_id INTEGER,
        title TEXT,
        genre TEXT,
        rating REAL
    )
''')

# Create watch_history table (tracks what users have watched)
cursor.execute('''
    CREATE TABLE IF NOT EXISTS watch_history (
        history_id INTEGER,
        user_id INTEGER,
        movie_id INTEGER,
        user_rating REAL
    )
''')

connection.commit()
```

### Phase 2: Add Sample Data

```python
# Add users
users = [
    (1, 'alice', 'Sci-Fi', 8.0),
    (2, 'bob', 'Action', 7.5),
    (3, 'charlie', 'Drama', 8.5)
]

for user in users:
    cursor.execute('''
        INSERT INTO users (user_id, username, favorite_genre, preferred_rating)
        VALUES (?, ?, ?, ?)
    ''', user)

# Add movies
movies = [
    (1, 'The Matrix', 'Sci-Fi', 8.7),
    (2, 'Inception', 'Sci-Fi', 8.8),
    (3, 'The Dark Knight', 'Action', 9.0),
    (4, 'Die Hard', 'Action', 8.5),
    (5, 'Shawshank Redemption', 'Drama', 9.3),
    (6, 'The Godfather', 'Drama', 9.2)
]

for movie in movies:
    cursor.execute('''
        INSERT INTO movies (movie_id, title, genre, rating)
        VALUES (?, ?, ?, ?)
    ''', movie)

connection.commit()
```

### Phase 3: The Decision Tree + Database Query

Now let's make smart recommendations:

```python
def recommend_movie(user_id):
    """
    Make a movie recommendation for a specific user
    by combining database queries with decision logic
    """
    
    # Step 1: Query the database for user preferences
    cursor.execute('''
        SELECT favorite_genre, preferred_rating FROM users
        WHERE user_id = ?
    ''', (user_id,))
    
    user_data = cursor.fetchone()
    
    if user_data is None:
        print("❌ User not found!")
        return
    
    favorite_genre, preferred_rating = user_data
    
    # Step 2: Decision logic based on the data
    if favorite_genre == "Sci-Fi":
        # Find highly-rated sci-fi movies
        cursor.execute('''
            SELECT title, rating FROM movies
            WHERE genre = ? AND rating >= ?
            ORDER BY rating DESC
        ''', (favorite_genre, preferred_rating))
        
        recommendation = cursor.fetchone()
        
        if recommendation:
            title, rating = recommendation
            print(f"🎯 Recommendation for {user_id}: {title} ({rating}/10)")
        else:
            print(f"No {favorite_genre} movies match your preferences")
    
    elif favorite_genre == "Action":
        # Find action movies matching preferences
        cursor.execute('''
            SELECT title, rating FROM movies
            WHERE genre = ? AND rating >= ?
            ORDER BY rating DESC
        ''', (favorite_genre, preferred_rating))
        
        recommendation = cursor.fetchone()
        
        if recommendation:
            title, rating = recommendation
            print(f"💥 Recommendation for {user_id}: {title} ({rating}/10)")
        else:
            print(f"No {favorite_genre} movies match your preferences")
    
    else:
        # Drama or other genres
        cursor.execute('''
            SELECT title, rating FROM movies
            WHERE genre = ? AND rating >= ?
            ORDER BY rating DESC
        ''', (favorite_genre, preferred_rating))
        
        recommendation = cursor.fetchone()
        
        if recommendation:
            title, rating = recommendation
            print(f"🎭 Recommendation for {user_id}: {title} ({rating}/10)")

# Test the recommender
recommend_movie(1)  # Alice (Sci-Fi fan)
recommend_movie(2)  # Bob (Action fan)
recommend_movie(3)  # Charlie (Drama fan)
```

**Output:**
```
🎯 Recommendation for 1: Inception (8.8/10)
💥 Recommendation for 2: The Dark Knight (9.0/10)
🎭 Recommendation for 3: Shawshank Redemption (9.3/10)
```

## Pattern: Query → Decide → Store

This is the core pattern for AI systems:

```python
# Step 1: QUERY - Get data from database
cursor.execute('SELECT * FROM users WHERE ...')
data = cursor.fetchone()

# Step 2: DECIDE - Make decision based on data
if data[0] > some_threshold:
    action = "A"
else:
    action = "B"

# Step 3: STORE - Save the decision result
cursor.execute('INSERT INTO history (action, timestamp) VALUES (?, ?)')
connection.commit()
```

## Real Example: Study Recommendation System

Let's build something you can actually use!

```python
import sqlite3
from datetime import datetime

connection = sqlite3.connect('study_tracker.db')
cursor = connection.cursor()

# Create tables
cursor.execute('''
    CREATE TABLE IF NOT EXISTS students (
        student_id INTEGER,
        name TEXT,
        grade REAL,
        major TEXT
    )
''')

cursor.execute('''
    CREATE TABLE IF NOT EXISTS study_records (
        record_id INTEGER,
        student_id INTEGER,
        subject TEXT,
        hours_studied REAL,
        test_score REAL,
        date TEXT
    )
''')

# Add students
students = [
    (1, "Alice", 3.8, "Engineering"),
    (2, "Bob", 2.1, "Business")
]

for student in students:
    cursor.execute('''
        INSERT INTO students (student_id, name, grade, major)
        VALUES (?, ?, ?, ?)
    ''', student)

# Add study