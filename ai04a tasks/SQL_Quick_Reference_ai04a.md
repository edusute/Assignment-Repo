# SQL Quick Reference Guide - AI Course
## Keep This Open While Working!

**Applications of Artificial Intelligence | Medina County Career Center**

---

## 📌 Basic Query Structure

```sql
SELECT column1, column2       -- What columns to show
FROM table_name              -- Which table
WHERE condition              -- Filter rows (optional)
ORDER BY column              -- Sort results (optional)
LIMIT number                 -- Limit rows (optional)
```

**⚠️ ORDER MATTERS!** Always write clauses in this order.

---

## 🎯 SELECT - Choosing Columns

```sql
-- Get all columns
SELECT * FROM teams;

-- Get specific columns
SELECT full_name, city FROM teams;

-- Multiple columns (use commas!)
SELECT full_name, city, state, year_founded FROM teams;
```

**✅ Commas between columns**  
**❌ NO comma after last column**

---

## 🔍 WHERE - Filtering Rows

### Numbers (no quotes)

```sql
WHERE year_founded > 1990
WHERE pts >= 120
WHERE gp < 50
WHERE team_id = 1610612739
```

### Text (needs single quotes!)

```sql
WHERE state = 'California'
WHERE season = '2021-22'
WHERE wl = 'W'
WHERE matchup = 'CLE vs. BOS'
```

**⚠️ CRITICAL:** Text needs `'single quotes'`

---

## 🔢 Comparison Operators

| Operator | Meaning | Example |
|----------|---------|---------|
| `=` | Equal | `WHERE state = 'Texas'` |
| `!=` | Not equal | `WHERE state != 'California'` |
| `>` | Greater than | `WHERE pts > 100` |
| `<` | Less than | `WHERE gp < 50` |
| `>=` | Greater or equal | `WHERE pts >= 120` |
| `<=` | Less or equal | `WHERE gp <= 40` |

**Note:** Use `=` (not `==` like Python!)

---

## 🔗 Combining Conditions

### AND - Both must be true

```sql
WHERE season = '2021-22' AND pts > 120

WHERE state = 'California' AND year_founded < 1970

WHERE wl = 'W' AND pts >= 110 AND ast > 25
```

**Pro Tip:** Use AND when you want players/teams that meet ALL criteria

### OR - At least one must be true

```sql
WHERE state = 'California' OR state = 'Texas'

WHERE pts > 130 OR ast > 30
```

**Pro Tip:** Use OR when you want players/teams that meet ANY criteria

### BETWEEN - Range

```sql
WHERE pts BETWEEN 100 AND 110
-- Same as: WHERE pts >= 100 AND pts <= 110

WHERE year_founded BETWEEN 1990 AND 2000

WHERE gp BETWEEN 40 AND 60
```

---

## 📊 ORDER BY - Sorting

```sql
-- Ascending (smallest to largest) - DEFAULT
ORDER BY year_founded
ORDER BY year_founded ASC  -- ASC is optional

-- Descending (largest to smallest)
ORDER BY pts DESC
ORDER BY gp DESC

-- Multiple columns (primary then secondary)
ORDER BY state, city
ORDER BY state, full_name
ORDER BY pts DESC, ast DESC
```

**Tip:** Think "alphabetically" for ASC, "reverse" for DESC

---

## 🎯 LIMIT - Controlling Output

```sql
-- First 10 rows
LIMIT 10

-- First 5 rows
LIMIT 5

-- Combine with ORDER BY for "Top N"
ORDER BY pts DESC
LIMIT 10  -- Top 10 highest scores
```

**⚠️ LIMIT always goes last!**

---

## 🏀 NBA Database Tables

### players
- `player_id` - Unique player identifier
- `full_name` - Player's full name

**Use for:** Getting player names, joining with player_season_stats

---

### teams
- `team_id` - Unique team identifier
- `full_name` - Team full name (e.g., "Cleveland Cavaliers")
- `abbreviation` - Team abbreviation (e.g., "CLE")
- `nickname` - Team nickname (e.g., "Cavaliers")
- `city` - Team city
- `state` - Team state
- `year_founded` - Year team was founded

**Use for:** Finding teams by location, analyzing team history

---

### player_season_stats
**One row per player per season**

- `season` - Season (e.g., "2021-22")
- `player_id` - Player ID (links to players table)
- `team_id` - Team ID (links to teams table)
- `gp` - **Games played** (important for filtering!)
- `min` - Minutes per game
- `pts` - **Points per game** ⭐
- `reb` - **Rebounds per game** ⭐
- `ast` - **Assists per game** ⭐
- `stl` - Steals per game
- `blk` - Blocks per game
- `tov` - Turnovers per game
- `fg_pct` - Field goal percentage (0-100)
- `fg3_pct` - **3-point percentage** (0-100) ⭐
- `ft_pct` - Free throw percentage (0-100)

**Common Filters:**
```sql
WHERE gp >= 40  -- Players who played most of season
WHERE pts >= 20  -- Star scorers
WHERE fg3_pct >= 40  -- Elite shooters
```

---

### team_game_stats
**One row per team per game**

- `season` - Season (e.g., "2021-22")
- `game_id` - Unique game identifier
- `team_id` - Team ID (links to teams table)
- `game_date` - Game date
- `matchup` - Matchup string (e.g., "CLE vs. BOS" or "CLE @ BOS")
- `wl` - **Win/Loss** ('W' or 'L') ⭐
- `pts` - **Points scored** ⭐
- `fgm` - Field goals made
- `fga` - Field goals attempted
- `fg3m` - 3-pointers made
- `fg3a` - 3-pointers attempted
- `ftm` - Free throws made
- `fta` - Free throws attempted
- `oreb` - Offensive rebounds
- `dreb` - Defensive rebounds
- `reb` - **Total rebounds** ⭐
- `ast` - **Assists** ⭐
- `stl` - **Steals**
- `blk` - **Blocks**
- `tov` - **Turnovers** ⭐
- `plus_minus` - Point differential

**Common Filters:**
```sql
WHERE wl = 'W'  -- Wins only
WHERE wl = 'L'  -- Losses only
WHERE pts >= 120  -- High-scoring games
WHERE season = '2021-22'  -- Specific season
```

---

## 💻 Python Workflow

### Basic Query

```python
import pandas as pd
import sqlite3

# 1. Connect to database
conn = sqlite3.connect('nba_5seasons.db')

# 2. Write SQL query
query = """
SELECT column1, column2
FROM table_name
WHERE condition
ORDER BY column
LIMIT n
"""

# 3. Run query and get DataFrame
df = pd.read_sql(query, conn)

# 4. Display results
display(df)

# 5. Close connection when done
conn.close()
```

---

### 📊 Exporting to Excel

```python
# After running your query and getting a DataFrame:
df = pd.read_sql(query, conn)

# Export to Excel
df.to_excel('filename.xlsx', index=False, sheet_name='Sheet Name')

# Example: Export high-scoring games
high_scoring.to_excel('high_scoring_games.xlsx', 
                      index=False, 
                      sheet_name='High Scoring')
```

**Excel Export Tips:**
- `index=False` - Don't include row numbers
- `sheet_name='...'` - Name your worksheet
- Use descriptive filenames
- These files are perfect for MOS practice!

---

## 🐛 Common Mistakes & Fixes

### ❌ Forgot quotes around text
```sql
WHERE state = California  -- ERROR!
WHERE season = 2021-22    -- ERROR!
```
**✅ Fix:**
```sql
WHERE state = 'California'  -- Use single quotes
WHERE season = '2021-22'    -- Text needs quotes!
```

---

### ❌ Wrong clause order
```sql
SELECT * FROM teams LIMIT 10 WHERE state = 'Texas'  -- ERROR!
```
**✅ Fix:**
```sql
SELECT * FROM teams WHERE state = 'Texas' LIMIT 10
```
**Remember:** SELECT → FROM → WHERE → ORDER BY → LIMIT

---

### ❌ Comma after last column
```sql
SELECT full_name, city, state, FROM teams  -- ERROR!
```
**✅ Fix:**
```sql
SELECT full_name, city, state FROM teams  -- No comma before FROM
```

---

### ❌ Using == instead of =
```sql
WHERE pts == 120  -- This might work but use =
```
**✅ Fix:**
```sql
WHERE pts = 120  -- Use single = in SQL
```

---

### ❌ Forgetting to filter by games played
```sql
-- Bad: Includes players who only played 2 games
SELECT player_id, pts
FROM player_season_stats
WHERE pts >= 20
```
**✅ Fix:**
```sql
-- Good: Only includes players with significant playing time
SELECT player_id, pts, gp
FROM player_season_stats
WHERE pts >= 20 AND gp >= 40
```

---

## 📝 Query Building Strategy

### Start Simple, Build Up

```sql
-- Step 1: Select all
SELECT * FROM teams;

-- Step 2: Select specific columns
SELECT full_name, state FROM teams;

-- Step 3: Add filtering
SELECT full_name, state FROM teams WHERE state = 'California';

-- Step 4: Add sorting
SELECT full_name, state FROM teams WHERE state = 'California' ORDER BY full_name;

-- Step 5: Add limit
SELECT full_name, state FROM teams WHERE state = 'California' ORDER BY full_name LIMIT 5;
```

**Test after each step!**

---

## 🎯 Common Query Patterns from Tasks

### Pattern 1: High-Scoring Games
```sql
SELECT season, game_date, team_id, matchup, pts, wl
FROM team_game_stats
WHERE pts >= 120
ORDER BY pts DESC
LIMIT 20
```

### Pattern 2: Top Scorers (with games played filter!)
```sql
SELECT player_id, season, team_id, gp, pts, reb, ast
FROM player_season_stats
WHERE season = '2021-22'
  AND pts >= 20
  AND gp >= 40
ORDER BY pts DESC
```

### Pattern 3: All-Around Players
```sql
SELECT player_id, gp, pts, reb, ast
FROM player_season_stats
WHERE season = '2021-22'
  AND pts >= 15
  AND reb >= 5
  AND ast >= 5
  AND gp >= 40
ORDER BY pts DESC
```

### Pattern 4: Wins with Good Offense
```sql
SELECT game_date, team_id, matchup, pts, wl
FROM team_game_stats
WHERE season = '2021-22'
  AND wl = 'W'
  AND pts >= 115
ORDER BY pts DESC
LIMIT 25
```

### Pattern 5: Close Games (Using BETWEEN)
```sql
SELECT game_date, team_id, matchup, pts, wl
FROM team_game_stats
WHERE season = '2021-22'
  AND pts BETWEEN 100 AND 110
ORDER BY pts
```

### Pattern 6: Teams by State
```sql
SELECT full_name, city, state
FROM teams
ORDER BY state, full_name
```

---

## 🔄 SQL vs Pandas Comparison

| Operation | Pandas | SQL |
|-----------|--------|-----|
| Load all data | `pd.read_csv('file.csv')` | `SELECT * FROM table` |
| Select columns | `df[['col1', 'col2']]` | `SELECT col1, col2 FROM table` |
| Filter rows | `df[df['pts'] > 100]` | `WHERE pts > 100` |
| Sort ascending | `df.sort_values('pts')` | `ORDER BY pts` |
| Sort descending | `df.sort_values('pts', ascending=False)` | `ORDER BY pts DESC` |
| First N rows | `df.head(10)` | `LIMIT 10` |
| AND condition | `df[(df['A'] > 5) & (df['B'] == 'x')]` | `WHERE A > 5 AND B = 'x'` |
| OR condition | `df[(df['A'] == 1) \| (df['B'] == 2)]` | `WHERE A = 1 OR B = 2` |
| Export to Excel | `df.to_excel('file.xlsx', index=False)` | *(do after query)* |

---

## 🎓 Practice Examples

### Example 1: Find Texas Teams
```sql
SELECT full_name, city
FROM teams
WHERE state = 'Texas'
ORDER BY city
```

### Example 2: High-Scoring Games (2021-22)
```sql
SELECT game_date, team_id, pts, wl
FROM team_game_stats
WHERE season = '2021-22' AND pts >= 130
ORDER BY pts DESC
LIMIT 20
```

### Example 3: Elite 3-Point Shooters
```sql
SELECT player_id, gp, pts, fg3_pct
FROM player_season_stats
WHERE season = '2021-22'
  AND fg3_pct >= 40
  AND gp >= 50
  AND pts >= 10
ORDER BY fg3_pct DESC
```

### Example 4: Losses Despite Good Scoring
```sql
SELECT game_date, team_id, matchup, pts, wl
FROM team_game_stats
WHERE season = '2021-22' 
  AND wl = 'L'
  AND pts >= 110
ORDER BY pts DESC
LIMIT 20
```

---

## 💡 Pro Tips

1. **Always filter by games played (gp) for player stats**
   - `WHERE gp >= 40` ensures meaningful comparisons
   - Avoids players who only played a few games

2. **Always filter by season**
   - `WHERE season = '2021-22'`
   - Database has multiple seasons!

3. **Start with LIMIT 5** when testing
   - Makes results easier to read
   - Runs faster on large tables

4. **Use `*` to explore**
   - `SELECT * FROM table LIMIT 5`
   - See what columns are available

5. **Check column names if unsure**
   - Look at this reference guide
   - Or run `SELECT * FROM table LIMIT 1`

6. **Break complex queries into steps**
   - Get SELECT working
   - Add WHERE
   - Add ORDER BY
   - Add LIMIT

7. **Test each AND condition separately**
   - If your query returns 0 rows, test each condition alone
   - Example: Test `WHERE pts >= 20` then `WHERE gp >= 40` separately

---

## 📊 Excel Files You'll Create

As you work through the tasks, you'll create these Excel files:

1. **high_scoring_games.xlsx** - Games with 120+ points
2. **top_scorers.xlsx** - Players averaging 20+ PPG
3. **win_loss_records.xlsx** - All 2021-22 game results
4. **nba_win_prediction.xlsx** - ML-ready dataset

**These files are perfect for practicing:**
- Excel formulas (SUM, AVERAGE, IF, COUNTIF)
- Charts and visualizations
- Conditional formatting
- PivotTables
- MOS certification skills!

---

## 🚀 Next Level (Coming in Week 2!)

**Next lessons will add:**
- `COUNT(*)` - Count rows
- `SUM()` - Add up values
- `AVG()` - Calculate averages
- `MAX()` / `MIN()` - Find extremes
- `GROUP BY` - Summarize by categories
- `JOIN` - Combine tables
- `HAVING` - Filter groups

**For now:** Master SELECT, WHERE, ORDER BY, LIMIT!

---

## ✅ Checklist Before Asking for Help

When stuck:

- [ ] Did I connect to the database? (`conn = sqlite3.connect('nba_5seasons.db')`)
- [ ] Are all text values in single quotes? (`'2021-22'`, `'W'`, `'California'`)
- [ ] Are my clauses in the right order? (SELECT → FROM → WHERE → ORDER BY → LIMIT)
- [ ] Did I filter by season? (`WHERE season = '2021-22'`)
- [ ] For player stats: Did I filter by games played? (`AND gp >= 40`)
- [ ] Did I test with `LIMIT 5` first?
- [ ] Did I try running just the WHERE conditions separately?

---

## 📌 Keep This Open!

**Print this guide or keep it in a separate tab while working.**

You'll reference it constantly - that's normal and expected!

Even professional data scientists look up SQL syntax regularly.

**Happy querying!** 🏀📊

---

## 🔍 Quick Column Lookup

**Need to find a column? Use Ctrl+F to search:**
- Points: `pts`
- Rebounds: `reb`
- Assists: `ast`
- Games Played: `gp`
- Win/Loss: `wl`
- 3-Point %: `fg3_pct`
- Season: `season`
- State: `state`

---

**Version:** AI Course Week 1 - Updated  
**Updated:** January 2026  
**For:** ai04a SQL Introduction Tasks  
**Aligned with:** ai04aTasks.ipynb
