# SQL Reference Guide - NBA Database

**Quick reference for SQL aggregate functions, GROUP BY, and Excel exports**

---

## Table of Contents
1. [Database Schema](#database-schema)
2. [Aggregate Functions](#aggregate-functions)
3. [GROUP BY](#group-by)
4. [HAVING](#having)
5. [Complete Query Structure](#complete-query-structure)
6. [Excel Export](#excel-export)
7. [Common Patterns](#common-patterns)

---

## Database Schema

### Tables in nba_5seasons.db

**teams** - Team information
- `team_id` (TEXT) - Team abbreviation (e.g., 'LAL', 'GSW')
- `full_name` (TEXT) - Full team name
- `abbreviation` (TEXT) - Short code
- `nickname` (TEXT) - Team nickname
- `city` (TEXT) - Home city
- `state` (TEXT) - Home state
- `year_founded` (INTEGER) - Year established

**team_game_stats** - Individual game performance
- `team_id` (TEXT) - Team abbreviation
- `game_id` (TEXT) - Unique game identifier
- `game_date` (TEXT) - Date of game
- `season` (TEXT) - Season (e.g., '2021-22')
- `wl` (TEXT) - Win/Loss ('W' or 'L')
- `pts` (INTEGER) - Points scored
- `fgm`, `fga`, `fg_pct` - Field goals made/attempted/percentage
- `fg3m`, `fg3a`, `fg3_pct` - Three-pointers made/attempted/percentage
- `ftm`, `fta`, `ft_pct` - Free throws made/attempted/percentage
- `reb` (INTEGER) - Rebounds
- `ast` (INTEGER) - Assists
- `stl` (INTEGER) - Steals
- `blk` (INTEGER) - Blocks
- `tov` (INTEGER) - Turnovers
- `pf` (INTEGER) - Personal fouls

**player_season_stats** - Player averages per season
- `player_id` (INTEGER) - Unique player ID
- `player_name` (TEXT) - Player name
- `team_id` (TEXT) - Team abbreviation
- `season` (TEXT) - Season
- `gp` (INTEGER) - Games played
- `pts` (REAL) - Points per game
- `reb` (REAL) - Rebounds per game
- `ast` (REAL) - Assists per game
- *(Note: pts, reb, ast are already AVERAGES in this table)*

**players** - Player information
- `player_id` (INTEGER) - Unique player ID
- `full_name` (TEXT) - Full name
- `first_name` (TEXT) - First name
- `last_name` (TEXT) - Last name

---

## Aggregate Functions

### COUNT - Count Rows

**Syntax:**
```sql
SELECT COUNT(*) FROM table_name
SELECT COUNT(column_name) FROM table_name
```

**Examples:**

```sql
-- Count all teams
SELECT COUNT(*) FROM teams
-- Result: 30

-- Count all games in 2021-22
SELECT COUNT(*) 
FROM team_game_stats 
WHERE season = '2021-22'
-- Result: 2460 (30 teams × 82 games)

-- Count wins
SELECT COUNT(*) 
FROM team_game_stats 
WHERE season = '2021-22' AND wl = 'W'
-- Result: 1230
```

**Key Points:**
- `COUNT(*)` counts all rows
- `COUNT(column_name)` counts non-null values in that column
- Use with WHERE to count filtered results

---

### SUM - Add Values

**Syntax:**
```sql
SELECT SUM(column_name) FROM table_name
```

**Examples:**

```sql
-- Total points scored in 2021-22
SELECT SUM(pts) 
FROM team_game_stats 
WHERE season = '2021-22'
-- Result: ~270,000

-- Total assists in wins
SELECT SUM(ast)
FROM team_game_stats
WHERE season = '2021-22' AND wl = 'W'
```

**Key Points:**
- Only works on numeric columns
- Ignores NULL values
- Returns total sum across all selected rows

---

### AVG - Calculate Average

**Syntax:**
```sql
SELECT AVG(column_name) FROM table_name
```

**Examples:**

```sql
-- Average points per game in 2021-22
SELECT AVG(pts)
FROM team_game_stats
WHERE season = '2021-22'
-- Result: ~109-110

-- Average in wins vs losses
SELECT AVG(pts)
FROM team_game_stats
WHERE season = '2021-22' AND wl = 'W'
-- Result: ~115

SELECT AVG(pts)
FROM team_game_stats
WHERE season = '2021-22' AND wl = 'L'
-- Result: ~103
```

**Key Points:**
- Calculates mean (sum divided by count)
- Ignores NULL values
- Returns decimal value

---

### MAX and MIN - Find Extremes

**Syntax:**
```sql
SELECT MAX(column_name), MIN(column_name) FROM table_name
```

**Examples:**

```sql
-- Highest and lowest scores in 2021-22
SELECT 
    MAX(pts) as highest_score,
    MIN(pts) as lowest_score
FROM team_game_stats
WHERE season = '2021-22'
-- Results: highest ~150, lowest ~70

-- Find scoring range
SELECT 
    MAX(pts) - MIN(pts) as score_range
FROM team_game_stats
WHERE season = '2021-22'
```

**Key Points:**
- Works on numeric, date, and text columns
- Returns single highest/lowest value
- Useful for outlier detection

---

## GROUP BY

**Purpose:** Split data into groups and aggregate each group separately

**Syntax:**
```sql
SELECT category_column, aggregate_function(column)
FROM table_name
GROUP BY category_column
```

### Single Column Grouping

**Examples:**

```sql
-- Count games per season
SELECT season, COUNT(*) as game_count
FROM team_game_stats
GROUP BY season
-- Result: One row per season with its count

-- Average points per season
SELECT 
    season, 
    AVG(pts) as avg_points
FROM team_game_stats
GROUP BY season
ORDER BY season

-- Top scoring teams in 2021-22
SELECT 
    team_id,
    AVG(pts) as avg_points
FROM team_game_stats
WHERE season = '2021-22'
GROUP BY team_id
ORDER BY avg_points DESC
```

### Multiple Column Grouping

**Examples:**

```sql
-- Stats by team AND outcome (W/L)
SELECT 
    team_id,
    wl,
    COUNT(*) as games,
    AVG(pts) as avg_points,
    AVG(ast) as avg_assists
FROM team_game_stats
WHERE season = '2021-22'
GROUP BY team_id, wl
ORDER BY team_id, wl DESC

-- Result: Each team appears twice (W and L)
```

**Key Points:**
- Columns in SELECT must be either:
  - In the GROUP BY clause, OR
  - Inside an aggregate function
- Can group by multiple columns
- ORDER BY can reference aggregated columns

---

## HAVING

**Purpose:** Filter groups AFTER aggregation

**Difference from WHERE:**
- `WHERE` filters rows BEFORE grouping
- `HAVING` filters groups AFTER aggregating

**Syntax:**
```sql
SELECT column, aggregate_function(column)
FROM table
WHERE condition          -- Filter rows FIRST
GROUP BY column
HAVING aggregate_condition    -- Filter groups AFTER
ORDER BY column
```

**Examples:**

```sql
-- Teams with 50+ wins
SELECT 
    team_id,
    COUNT(*) as wins
FROM team_game_stats
WHERE season = '2021-22' AND wl = 'W'
GROUP BY team_id
HAVING COUNT(*) >= 50
ORDER BY wins DESC

-- High-scoring teams (110+ PPG)
SELECT 
    team_id,
    AVG(pts) as avg_points
FROM team_game_stats
WHERE season = '2021-22'
GROUP BY team_id
HAVING AVG(pts) >= 110
ORDER BY avg_points DESC

-- Seasons with high average scoring
SELECT 
    season,
    AVG(pts) as avg_points
FROM team_game_stats
GROUP BY season
HAVING AVG(pts) > 108
```

**Key Points:**
- Can use aggregate functions in HAVING
- Can combine WHERE and HAVING
- HAVING comes after GROUP BY

---

## Complete Query Structure

**Proper clause order:**
```sql
SELECT column_list
FROM table_name
WHERE row_filter            -- Filter individual rows
GROUP BY grouping_columns   -- Create groups
HAVING group_filter         -- Filter groups
ORDER BY sort_columns       -- Sort results
LIMIT number               -- Limit results
```

**Example combining everything:**

```sql
SELECT 
    team_id,
    COUNT(*) as wins,
    AVG(pts) as avg_points,
    MAX(pts) as best_game
FROM team_game_stats
WHERE season = '2021-22'      -- Only 2021-22 season
  AND wl = 'W'                -- Only wins
GROUP BY team_id              -- One row per team
HAVING COUNT(*) >= 45         -- At least 45 wins
ORDER BY wins DESC            -- Best teams first
LIMIT 10                      -- Top 10 only
```

---

## Excel Export

### Basic Export

**Pattern:**
```python
import pandas as pd
import sqlite3

# Connect to database
conn = sqlite3.connect('nba_5seasons.db')

# Query data
query = "SELECT * FROM table_name"
df = pd.read_sql(query, conn)

# Export to Excel
df.to_excel('filename.xlsx', 
            index=False,              # Don't include row numbers
            sheet_name='Sheet Name')  # Name the worksheet

conn.close()
```

### Full Example

```python
# Team performance summary
query = """
SELECT 
    team_id,
    COUNT(*) as games,
    SUM(CASE WHEN wl = 'W' THEN 1 ELSE 0 END) as wins,
    AVG(pts) as avg_points,
    AVG(reb) as avg_rebounds,
    AVG(ast) as avg_assists
FROM team_game_stats
WHERE season = '2021-22'
GROUP BY team_id
ORDER BY wins DESC
"""

df = pd.read_sql(query, conn)

# Export
df.to_excel('team_stats_2021-22.xlsx', 
            index=False, 
            sheet_name='Team Performance')

print(f"Exported {len(df)} teams to Excel")
```

### Export Multiple Sheets

```python
with pd.ExcelWriter('nba_analysis.xlsx') as writer:
    # Sheet 1: Team stats
    team_df.to_excel(writer, sheet_name='Teams', index=False)
    
    # Sheet 2: Season trends
    season_df.to_excel(writer, sheet_name='Seasons', index=False)
    
    # Sheet 3: Player stats
    player_df.to_excel(writer, sheet_name='Players', index=False)
```

### Export with Formatting

```python
# Round numbers for cleaner display
query = """
SELECT 
    team_id,
    ROUND(AVG(pts), 1) as avg_points,
    ROUND(AVG(reb), 1) as avg_rebounds,
    ROUND(AVG(fg_pct), 3) as fg_percentage
FROM team_game_stats
WHERE season = '2021-22'
GROUP BY team_id
"""
```

**Key Points:**
- `index=False` prevents row numbers from appearing
- Sheet names cannot exceed 31 characters
- Use ROUND in SQL for cleaner numbers
- CSV export: `df.to_csv('filename.csv', index=False)`

---

## Common Patterns

### Pattern 1: Top N with LIMIT

```sql
-- Top 10 scoring performances
SELECT team_id, game_date, pts
FROM team_game_stats
WHERE season = '2021-22'
ORDER BY pts DESC
LIMIT 10
```

### Pattern 2: Win Percentage Calculation

```sql
-- Team win percentages
SELECT 
    team_id,
    COUNT(*) as total_games,
    SUM(CASE WHEN wl = 'W' THEN 1 ELSE 0 END) as wins,
    ROUND(
        SUM(CASE WHEN wl = 'W' THEN 1 ELSE 0 END) * 100.0 / COUNT(*), 
        1
    ) as win_pct
FROM team_game_stats
WHERE season = '2021-22'
GROUP BY team_id
ORDER BY win_pct DESC
```

### Pattern 3: Comparison Queries

```sql
-- Compare stats in wins vs losses
SELECT 
    'Wins' as outcome,
    AVG(pts) as avg_points,
    AVG(ast) as avg_assists,
    AVG(tov) as avg_turnovers
FROM team_game_stats
WHERE season = '2021-22' AND wl = 'W'

UNION ALL

SELECT 
    'Losses' as outcome,
    AVG(pts),
    AVG(ast),
    AVG(tov)
FROM team_game_stats
WHERE season = '2021-22' AND wl = 'L'
```

### Pattern 4: Feature Engineering

```sql
-- Create high/low categories
SELECT 
    team_id,
    CASE 
        WHEN AVG(pts) >= 115 THEN 'High Scoring'
        WHEN AVG(pts) >= 105 THEN 'Average Scoring'
        ELSE 'Low Scoring'
    END as scoring_category,
    AVG(pts) as avg_points
FROM team_game_stats
WHERE season = '2021-22'
GROUP BY team_id
```

---

## Tips for Success

### Do's ✅
- Always use `GROUP BY` with non-aggregated columns in SELECT
- Use descriptive aliases with `AS`
- Filter with WHERE before grouping (faster)
- Use HAVING only for aggregate conditions
- Round numbers with ROUND() for cleaner output
- Test queries on small datasets first

### Don'ts ❌
- Don't put non-aggregated columns in SELECT without GROUP BY
- Don't use aggregate functions in WHERE (use HAVING instead)
- Don't forget to ORDER BY when you want sorted results
- Don't use `SELECT *` when you only need specific columns
- Don't export without checking data first

---

## Quick Reference Cheat Sheet

```sql
-- Count rows
SELECT COUNT(*) FROM table_name

-- Sum values
SELECT SUM(column_name) FROM table_name

-- Calculate average
SELECT AVG(column_name) FROM table_name

-- Find max/min
SELECT MAX(column_name), MIN(column_name) FROM table_name

-- Group by category
SELECT category, COUNT(*) 
FROM table_name 
GROUP BY category

-- Filter groups
SELECT category, AVG(column)
FROM table_name
GROUP BY category
HAVING AVG(column) > value

-- Complete query
SELECT category, COUNT(*) as count
FROM table_name
WHERE condition
GROUP BY category
HAVING COUNT(*) > value
ORDER BY count DESC
LIMIT 10
```

---

## Additional Resources

**Practice Queries:**
- Start with simple COUNT and SUM
- Add WHERE conditions
- Progress to GROUP BY
- Finally combine with HAVING

**For Help:**
- SQLite documentation: https://www.sqlite.org/lang.html
- Pandas documentation: https://pandas.pydata.org/docs/
- Ask instructor for clarification

**Common Errors:**
- "column must appear in GROUP BY" → Add column to GROUP BY clause
- "aggregate function in WHERE" → Use HAVING instead
- "no such column" → Check spelling and table name

---

*This guide uses the NBA database from ai04 lessons*
