# AI Lesson 0Xd Team Project: Movie Database & Recommendation System

## Overview

Build a movie database and recommendation system that combines SQLite with decision-making logic. This project reinforces database concepts while showing how real systems (like Netflix) work.

**Note about AI:**
This project **feels like AI** because it makes decisions using data — like recommending a movie based on your favorite genre. But it's **not real AI yet** because the rules are written by us, not learned by the computer.  We will get there ("real AI") soon though. 


**Team Size:** 2-3 students per team

---

## Project Requirements

Your project must include:

### Technical Requirements
- [ ] Create a SQLite database with **at least 3 tables**
- [ ] Use **at least 3 different data types** (INTEGER, TEXT, REAL)
- [ ] **Insert at least 10 records** total across all tables
- [ ] Implement **at least 5 different queries** (SELECT statements)
- [ ] Use **WHERE clauses** to filter data (in at least 2 queries)
- [ ] Include **at least one decision tree** that uses database data
- [ ] Store results/decisions back to the database
- [ ] Write code with clear comments
- [ ] Handle basic error checking (check if results exist before using them)

### Code Quality Requirements
- [ ] Professional code structure with functions
- [ ] Clear variable names
- [ ] Organized layout with headers/sections
- [ ] Input validation where appropriate (e.g., `.lower()` for text)
- [ ] Proper database management (`commit()`, `close()`)

### Documentation Requirements
- [ ] Database schema diagram (tables, columns, data types)
- [ ] Sample data showing what's in each table
- [ ] Test plan with at least 5 test cases
- [ ] Explanation of how your system works (2-3 paragraphs)

---

## Project Options

Choose ONE project (or propose your own with teacher approval):

### Option 1: Movie Recommendation System (Recommended)

**What it does:**
- Store movies in a database (title, genre, rating, year, director)
- Store users with preferences (username, age, favorite_genre)
- Make personalized recommendations based on user preferences
- Track recommendations given to each user

**Requirements:**
- Movies table: id, title, genre, rating, year, director
- Users table: id, username, age, favorite_genre
- Recommendations table: id, user_id, movie_id, recommendation_date

**Features:**
- Add new movies and users
- Query high-rated movies by genre
- Decision tree: recommend movies matching user preferences
- Track which movies were recommended to which users

**Sample program flow:**
```
1. Display all users
2. Show user preferences
3. Query database for matching movies
4. Use decision logic to pick best recommendation
5. Store recommendation in database
6. Display recommendation with explanation
```

---

### Option 2: Game High Score Tracker 

**What it does:**
- Store games with difficulty levels and genres
- Track player high scores and achievements
- Recommend games based on player skill and interests
- Analyze player progress over time

**Requirements:**
- Games table: id, title, genre, difficulty, release_year
- Players table: id, username, skill_level, favorite_genre
- Scores table: id, player_id, game_id, score, date

**Features:**
- Query top scores across all players
- Query player's personal bests
- Decision tree: recommend games for player skill level
- Track progression (comparing scores over time)

---

### Option 3: Restaurant Recommendation System 🍽️

**What it does:**
- Store restaurants (name, cuisine, rating, price_range, location)
- Store customers with preferences
- Make personalized recommendations
- Track customer visits

**Requirements:**
- Restaurants table: id, name, cuisine, rating, price_range
- Customers table: id, name, budget, favorite_cuisine, location
- Visit_history table: id, customer_id, restaurant_id, date, rating_given

**Features:**
- Query restaurants by cuisine and price
- Decision tree: recommend restaurants matching customer budget and preferences
- Show customer history
- Update customer rating after visit

---

### Option 4: Book Library System 

**What it does:**
- Store books with genres, ratings, and difficulty levels
- Store readers with preferences
- Recommend books based on reading level and interests
- Track reading history

**Requirements:**
- Books table: id, title, genre, rating, difficulty_level, author
- Readers table: id, username, reading_level, favorite_genre
- Reading_history table: id, reader_id, book_id, date_read, user_rating

**Features:**
- Query books by genre and difficulty
- Decision tree: recommend books matching reader level and interests
- Show reading history
- Track progress through the library

---

### Option 5: Course Registration & Advisor System 

**What it does:**
- Store courses (name, subject, difficulty, prerequisites)
- Store students with majors and skill levels
- Recommend course schedules
- Track student progress

**Requirements:**
- Courses table: id, name, subject, difficulty, max_students
- Students table: id, name, major, completed_courses, gpa
- Enrollments table: id, student_id, course_id, semester, grade

**Features:**
- Query courses by difficulty or subject
- Decision tree: recommend courses based on major and completed courses
- Show student progress toward degree
- List available courses for next semester

---

### Option 6: Pet Adoption Matcher 

**What it does:**
- Store available pets with characteristics
- Store potential adopters with lifestyle info
- Match pets to adopters using decision logic
- Track adoptions

**Requirements:**
- Pets table: id, name, species, breed, age, energy_level
- Adopters table: id, name, lifestyle, space, time_available
- Adoptions table: id, pet_id, adopter_id, adoption_date

**Features:**
- Query pets by type or energy level
- Decision tree: match adopters to suitable pets
- Query adoption history
- Show available pets

---

### Option 7: Your Own Idea! 

**Get teacher approval first!**

Your system must:
- Use at least 3 tables
- Include at least 10 records
- Implement queries with WHERE clauses
- Use decision logic based on database data
- Be school-appropriate

---

## Code Template

```python
"""
Movie Recommendation System (or your project name)
Team Members: [Names]
Date: [Date]
Purpose: [Brief description]
"""

import sqlite3
from datetime import datetime

# ==================================================
# DATABASE SETUP
# ==================================================

def setup_database():
    """Create database and tables if they don't exist"""
    connection = sqlite3.connect('movies.db')
    cursor = connection.cursor()
    
    # Create movies table
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS movies (
            id INTEGER,
            title TEXT,
            genre TEXT,
            rating REAL,
            year INTEGER,
            director TEXT
        )
    ''')
    
    # Create users table
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER,
            username TEXT,
            age INTEGER,
            favorite_genre TEXT
        )
    ''')
    
    # Create recommendations table
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS recommendations (
            id INTEGER,
            user_id INTEGER,
            movie_id INTEGER,
            recommendation_date TEXT
        )
    ''')
    
    connection.commit()
    return connection, cursor

# ==================================================
# DATA INSERTION FUNCTIONS
# ==================================================

def add_sample_data(cursor, connection):
    """Add sample data to database"""
    
    # Add movies
    movies = [
        (1, 'The Matrix', 'Sci-Fi', 8.7, 1999, 'Lana Wachowski'),
        (2, 'Inception', 'Sci-Fi', 8.8, 2010, 'Christopher Nolan'),
        (3, 'The Dark Knight', 'Action', 9.0, 2008, 'Christopher Nolan'),
        (4, 'Pulp Fiction', 'Crime', 8.9, 1994, 'Quentin Tarantino'),
        (5, 'Forrest Gump', 'Drama', 8.8, 1994, 'Robert Zemeckis')
    ]
    
    for movie in movies:
        cursor.execute('''
            INSERT INTO movies (id, title, genre, rating, year, director)
            VALUES (?, ?, ?, ?, ?, ?)
        ''', movie)
    
    # Add users
    users = [
        (1, 'alice_movie', 16, 'Sci-Fi'),
        (2, 'bob_action', 14, 'Action'),
        (3, 'charlie_films', 18, 'Drama')
    ]
    
    for user in users:
        cursor.execute('''
            INSERT INTO users (id, username, age, favorite_genre)
            VALUES (?, ?, ?, ?)
        ''', user)
    
    connection.commit()

# ==================================================
# QUERY FUNCTIONS
# ==================================================

def query_all_movies(cursor):
    """Display all movies"""
    cursor.execute('SELECT * FROM movies')
    return cursor.fetchall()

def query_movies_by_genre(cursor, genre):
    """Get all movies of a specific genre"""
    cursor.execute('SELECT * FROM movies WHERE genre = ?', (genre,))
    return cursor.fetchall()

def query_high_rated_movies(cursor, min_rating):
    """Get movies above a certain rating"""
    cursor.execute('SELECT * FROM movies WHERE rating >= ?', (min_rating,))
    return cursor.fetchall()

def query_user_info(cursor, user_id):
    """Get user preferences"""
    cursor.execute('SELECT * FROM users WHERE id = ?', (user_id,))
    return cursor.fetchone()

# ==================================================
# DECISION TREE & RECOMMENDATION
# ==================================================

def recommend_movie(cursor, connection, user_id):
    """
    Query database for user preferences,
    use decision tree to pick best recommendation,
    store result in database
    """
    
    # Query user data
    user = query_user_info(cursor, user_id)
    
    if user is None:
        print("❌ User not found!")
        return
    
    user_id, username, age, favorite_genre = user
    
    # Decision tree: Find best recommendation
    if favorite_genre == "Sci-Fi":
        cursor.execute('''
            SELECT id, title, rating FROM movies
            WHERE genre = 'Sci-Fi'
            ORDER BY rating DESC
            LIMIT 1
        ''')
    elif favorite_genre == "Action":
        cursor.execute('''
            SELECT id, title, rating FROM movies
            WHERE genre = 'Action'
            ORDER BY rating DESC
            LIMIT 1
        ''')
    else:
        cursor.execute('''
            SELECT id, title, rating FROM movies
            WHERE genre = ?
            ORDER BY rating DESC
            LIMIT 1
        ''', (favorite_genre,))
    
    result = cursor.fetchone()
    
    if result:
        movie_id, title, rating = result
        print(f"\n🎬 Recommendation for {username}:")
        print(f"   Movie: {title}")
        print(f"   Rating: {rating}/10")
        print(f"   Genre: {favorite_genre}")
        
        # Store recommendation in database
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        cursor.execute('''
            INSERT INTO recommendations (user_id, movie_id, recommendation_date)
            VALUES (?, ?, ?)
        ''', (user_id, movie_id, timestamp))
        connection.commit()
        
        print("   ✅ Recommendation saved!")
    else:
        print(f"❌ No {favorite_genre} movies found!")

# ==================================================
# MAIN PROGRAM
# ==================================================

def main():
    print("="*50)
    print("MOVIE RECOMMENDATION SYSTEM")
    print("="*50)
    
    # Setup database
    connection, cursor = setup_database()
    add_sample_data(cursor, connection)
    
    # Display all movies
    print("\n📽️ Available Movies:")
    print("-"*50)
    movies = query_all_movies(cursor)
    for movie in movies:
        id, title, genre, rating, year, director = movie
        print(f"{id}. {title} ({year}) - {genre} - {rating}/10")
    
    # Get recommendations for each user
    print("\n" + "="*50)
    print("GENERATING RECOMMENDATIONS")
    print("="*50)
    
    recommend_movie(cursor, connection, 1)
    recommend_movie(cursor, connection, 2)
    recommend_movie(cursor, connection, 3)
    
    # Display all recommendations
    print("\n" + "="*50)
    print("RECOMMENDATION HISTORY")
    print("="*50)
    cursor.execute('''
        SELECT u.username, m.title, r.recommendation_date
        FROM recommendations r
        JOIN users u ON r.user_id = u.id
        JOIN movies m ON r.movie_id = m.id
    ''')
    
    for username, movie_title, date in cursor.fetchall():
        print(f"• {username} was recommended: {movie_title} ({date})")
    
    connection.close()
    print("\n✅ Program complete!")

if __name__ == '__main__':
    main()
```

---

## Database Schema Diagram Template

Create a visual showing your tables. Example:

```
MOVIES TABLE
┌────┬──────────────┬────────┬────────┬──────┬──────────┐
│ id │ title (TEXT) │ genre  │ rating │ year │ director │
│ INTEGER (PK) │ TEXT   │ TEXT   │ REAL   │ INTEGER│ TEXT     │
└────┴──────────────┴────────┴────────┴──────┴──────────┘

USERS TABLE
┌────┬──────────┬─────┬─────────────┐
│ id │ username │ age │ favorite_   │
│    │          │     │ genre       │
└────┴──────────┴─────┴─────────────┘

RECOMMENDATIONS TABLE
┌────┬─────────┬──────────┬────────────────┐
│ id │ user_id │ movie_id │ recommendation │
│    │         │          │ _date          │
└────┴─────────┴──────────┴────────────────┘
```

---

## Test Plan Template

```
TEST CASE 1: Create database and add sample data
Expected: Database file created, 5+ records added
Result: [Your result]
Pass/Fail: [Circle one]

TEST CASE 2: Query all movies
Expected: All movies display with correct format
Result: [Your result]
Pass/Fail: [Circle one]

TEST CASE 3: Query movies by genre
Expected: Only movies matching genre are returned
Result: [Your result]
Pass/Fail: [Circle one]

TEST CASE 4: Get user recommendations
Expected: Recommendation matches user's favorite genre
Result: [Your result]
Pass/Fail: [Circle one]

TEST CASE 5: Store recommendation in database
Expected: Recommendation appears in recommendation history
Result: [Your result]
Pass/Fail: [Circle one]
```

---

## Documentation Template

### Program Overview

[Write 2-3 paragraphs explaining]:
- What your program does
- How it uses databases
- How it uses decision logic
- Real-world application

### Database Structure

[Describe each table]:
- What data it stores
- Why it's important
- How it connects to other tables

### How It Works

[Explain the process]:
- How data is added
- How queries work
- How recommendations are made
- How results are stored

---

## Grading Rubric

| Category | Points | Criteria |
|----------|--------|----------|
| **Database Design** | 10 | 3+ tables, appropriate data types, logical structure |
| **Data & Queries** | 10 | 10+ records, 5+ queries, proper WHERE clauses |
| **Decision Logic** | 5 | Clear decision tree, uses database data, stores results |
| **Code Quality** | 5 | Comments, functions, clean code, error handling |
| **Schema Documentation** | 5 | Clear diagram showing tables and relationships |
| **Teamwork** | 5 | Both partners contributed equally |
| **TOTAL** | 40 | |

---

## Common Mistakes to Avoid

❌ **Only 1-2 tables** - Not enough complexity
✅ **Use 3-5 tables** - Shows understanding of relationships

❌ **No WHERE clauses** - Just getting all data
✅ **Filter data with WHERE** - Shows query skill

❌ **Decision tree doesn't use database data**
✅ **Query first, then decide** - Proper pattern

❌ **Forget to commit()** - Changes not saved
✅ **Always commit after changes** - Data persists

❌ **No error handling** - Crashes if data missing
✅ **Check if results exist** - Graceful handling

❌ **All one big function** - Hard to follow
✅ **Use multiple functions** - Organized, reusable

---

## Helpful Tips

### Planning
1. Choose your project
2. Sketch your tables on paper
3. Decide what data each table stores
4. Plan what queries you'll need
5. Think about your decision logic

### Building
1. Start with setup_database() function
2. Add sample data
3. Test queries one by one
4. Add decision tree logic
5. Test the whole flow

### Testing
1. Run through test plan
2. Try edge cases (empty results, missing users)
3. Check database file to verify data
4. Make sure decisions are correct
5. Verify recommendations are stored

### Finishing
1. Clean up code - add comments
2. Create schema diagram
3. Document test results
4. Write program explanation
5. Review with partner

---
