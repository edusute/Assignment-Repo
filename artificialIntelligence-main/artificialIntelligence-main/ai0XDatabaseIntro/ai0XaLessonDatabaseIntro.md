# AI Lesson 0Xa: What Are Databases?

## Learning Objectives
- Understand what databases are and why they're important for AI
- Learn the difference between storing data in files vs. databases
- Recognize SQLite as a beginner-friendly database system
- Understand basic database structure (tables, rows, columns)
- See how databases connect to the AI systems you learned last week

## Why Should You Care About Databases?

Remember from Week 1? We learned that AI learns from **data**.

**The Problem:** All that data has to go somewhere!

### Example: Netflix Recommendation System

Last week you learned: "AI learns from thousands of movies and user preferences"

**But where does that data live?**
- Movies: titles, genres, ratings, descriptions
- Users: watch history, preferences, ratings
- Interactions: when they watched, how long they watched, if they liked it

If Netflix just saved all this to random text files, they'd have chaos. They need a **database**.

### What is a Database?

A **database** is an organized system for storing and retrieving data.

Think of it like the difference between:

**No Database (chaos):**
```
movies.txt (10,000 lines jumbled together)
users.txt (incomplete information)
watch_history.txt (no way to connect to movies or users)
```

**Database (organized):**
```
Database: netflix.db
├─ Movies Table
│  ├─ id | title | genre | rating
│  └─ [All movies, organized]
├─ Users Table
│  ├─ id | name | email | preferences
│  └─ [All users, organized]
└─ Interactions Table
   ├─ user_id | movie_id | date_watched | rating
   └─ [All interactions, organized]
```

## Key Benefits of Databases

### 1. Organization
Data is stored in a logical structure (tables with columns)

### 2. Speed
Databases can find specific data in milliseconds from millions of records

### 3. Relationships
Connect data together (which user watched which movie?)

### 4. Protection
Data doesn't get accidentally overwritten

### 5. Scalability
Can handle billions of records without slowing down

## Database Structure: Tables

A **database table** is like a spreadsheet with rows and columns.

### Example: Movie Database

```
MOVIES TABLE
┌────┬──────────────────────┬──────────┬────────┐
│ id │ title                │ genre    │ rating │
├────┼──────────────────────┼──────────┼────────┤
│ 1  │ The Matrix           │ Sci-Fi   │ 8.7    │
│ 2  │ Inception            │ Sci-Fi   │ 8.8    │
│ 3  │ Avatar               │ Sci-Fi   │ 7.8    │
│ 4  │ The Dark Knight      │ Action   │ 9.0    │
│ 5  │ Pulp Fiction         │ Crime    │ 8.9    │
└────┴──────────────────────┴──────────┴────────┘
```

**Columns** (vertical): Properties of each movie
- id: unique identifier
- title: movie name
- genre: type of movie
- rating: how good it is

**Rows** (horizontal): Individual movies
- Row 1: The Matrix data
- Row 2: Inception data
- etc.

### Example: Users Database

```
USERS TABLE
┌────┬─────────────┬──────────────────────┬─────────────────┐
│ id │ username    │ email                │ favorite_genre  │
├────┼─────────────┼──────────────────────┼─────────────────┤
│ 1  │ alex_123    │ alex@email.com       │ Sci-Fi          │
│ 2  │ jordan_92   │ jordan@email.com     │ Action          │
│ 3  │ sam_lee     │ sam.lee@email.com    │ Romance         │
└────┴─────────────┴──────────────────────┴─────────────────┘
```

## Data Types

Just like Python, databases require you to specify what **type** of data goes in each column.

### Common Data Types

| Type | Example | Use Case |
|------|---------|----------|
| **INTEGER** | 42, 1000, -5 | Ages, counts, IDs |
| **TEXT** | "Hello", "Movie Title" | Names, descriptions |
| **REAL** | 3.14, 9.8, 7.5 | Ratings, decimals, percentages |
| **BOOLEAN** | True/False (0/1) | Yes/No questions |

### Example: Movie Table with Data Types

```
CREATE TABLE movies (
    id INTEGER,           -- Unique movie number
    title TEXT,           -- Movie name
    genre TEXT,           -- Type of movie
    rating REAL,          -- Quality score (like 8.7)
    release_year INTEGER  -- What year it came out
)
```

## SQLite: A Beginner's Database

### What is SQLite?

**SQLite** is a lightweight, file-based database system. It's perfect for learning because:

✅ **Easy to set up** - Just one file, no server needed
✅ **Built into Python** - No installation required
✅ **Portable** - One `.db` file contains everything
✅ **Fast** - Great for small to medium projects
✅ **Perfect for learning** - Simpler than enterprise databases

### Why SQLite vs. Other Databases?

| Database | Best For | Drawback |
|----------|----------|----------|
| **SQLite** | Learning, small projects, single users | Not ideal for massive scales |
| **MySQL** | Medium projects, websites | Needs server setup |
| **PostgreSQL** | Large projects, complex queries | Steeper learning curve |
| **MongoDB** | Flexible/unstructured data | Different concepts |

**For this class:** SQLite is perfect! We'll use it for everything.

## Database vs. Decision Trees from Week 1

Remember last week's movie rating system?

```python
if age >= 13:
    if has_violence == "yes":
        if age >= 17:
            print("Approved")
```

**The Problem:** Every time you restart the program, it forgets everything!

**With a Database:**
- Store which movies users have watched
- Track ratings they gave
- Remember their preferences
- Use that data to make better recommendations

**Next week:** We'll combine decision trees + databases for a powerful system!

## Real-World Examples

### Spotify
- **Database tables:** Songs, Artists, Users, Playlists, Listening_History
- **How it works:** Stores your listening history, learns patterns, recommends new songs

### Instagram
- **Database tables:** Users, Posts, Comments, Likes, Followers
- **How it works:** Stores your activity, shows relevant content

### YouTube
- **Database tables:** Videos, Channels, Users, Watch_History, Comments
- **How it works:** Tracks what you watch, recommends related videos

### Game High Scores
- **Database tables:** Players, Scores, Achievements, Games
- **How it works:** Saves your progress, compares to others, unlocks achievements

## AI Connection: Data is Fuel

**The more data AI has access to, the better it can learn!**

Without databases: AI can only work with data given to it once
With databases: AI can access years of historical data

### Example: Netflix AI

**Without database:** 
"Here are today's movies. Pick one."

**With database:**
"Here are movies similar to the 500 you've watched. Here are movies liked by people with your preferences. Here's what's trending. Here's what you rated highly..."

## Putting It Together

**Week 1 (Decision Trees):**
- AI makes decisions based on rules or patterns

**Week 2 (Databases):**
- Store data permanently
- Organize information
- Retrieve data efficiently

**Future (Combining them):**
- AI uses database data to make better decisions
- Learn patterns from stored data
- Build smarter systems

## Key Terms

Make sure you understand:

- **Database:** Organized system for storing data
- **Table:** Like a spreadsheet with rows and columns
- **Row:** One complete record (one movie, one user)
- **Column:** One type of data (all titles, all ages)
- **Schema:** The structure of a table (column names and types)
- **SQLite:** A file-based database system
- **Query:** A request to get data from a database

## Quick Check

Before moving on, make sure you can answer:

- [ ] What's the difference between storing data in text files vs. a database?
- [ ] Name 3 real-world apps that definitely use databases
- [ ] Explain rows vs. columns in a table
- [ ] Why is SQLite good for beginners?
- [ ] How does a database connect to AI?

## Looking Ahead

**Next lesson:** We'll write Python code to create and use databases!

You'll learn:
- How to create tables
- How to add data
- How to retrieve data
- How to ask questions of your database

---

**Reflection Question:** Think about an app you use daily. What data do you think it stores in its database? What tables might it have?