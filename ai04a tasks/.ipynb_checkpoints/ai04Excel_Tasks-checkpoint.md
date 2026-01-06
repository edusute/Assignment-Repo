# AI04 Excel Task – Data Exploration & Analysis

**Course:** Applications of Artificial Intelligence (AI04)
**Lesson Focus:** Using Excel to Explore, and Analyze/Visualize

---

## Overview

In this task, you will work with Excel files generated from NBA game and team data. The goal is **not database practice**, but rather to:

* Explore real-world datasets
* Perform feature analysis using Excel formulas
* Visualize patterns relevant to machine learning
* Build intuition about prediction, classification, and clustering

These Excel tasks support concepts you will later apply in Python and machine learning models but perhaps more importantly, prepare you for the MOS certification. 

---

## Files You Should Have

You should have the following Excel files:

1. `nba_win_prediction.xlsx`
2. `win_loss_records.xlsx`
3. `top_scorers.xlsx`
4. `high_scoring_games.xlsx`

> If you do not have these files, complete the AI04Part2Tasks.ipynb task first.

---

## Skills Practiced (AI + Excel Aligned)

* Data exploration and feature inspection
* Formula creation (IF, AVERAGE, COUNTIF, MAX, MIN)
* Interpreting distributions and trends
* Visualizing relationships in data
* Understanding inputs (features) vs outputs (targets)
* Preparing data for machine learning models

---

## Part 1: nba_win_prediction.xlsx – Features & Target Variables

**Open:** `nba_win_prediction.xlsx`

This dataset represents **team-level game data**, which is commonly used for ML classification.

### Task 1.X: Create a Data Dictionary Worksheet (MOS-Aligned)

In this task, you will create a **Data Dictionary** worksheet that documents every
column in the dataset. This is a common real-world Excel practice used in data
analysis and machine learning projects.

---

## Step 1: Create the Worksheet

1. Add a new worksheet.
2. Rename it:  
   **`Data_Dictionary`**

---

## Step 2: Create the Dictionary Table

In the new worksheet, create a table with the following column headers:

| Column Name | Data Type | Description | Role (ML) | Example Value |

---

## Step 3: Enter the Data Dictionary (Use This Table)

Enter the following rows exactly as shown:

| Column Name | Data Type | Description | Role (ML) | Example Value |
|------------|----------|-------------|-----------|---------------|
| team_id | Number | Unique identifier for the team | Feature | 1610612737 |
| pts | Number | Total points scored by the team in the game | Feature | 112 |
| fgm | Number | Field goals made by the team | Feature | 41 |
| fga | Number | Field goals attempted by the team | Feature | 87 |
| fg3m | Number | Three-point field goals made | Feature | 13 |
| fg3a | Number | Three-point field goals attempted | Feature | 36 |
| reb | Number | Total rebounds by the team | Feature | 45 |
| ast | Number | Total assists by the team | Feature | 26 |
| stl | Number | Total steals by the team | Feature | 8 |
| blk | Number | Total blocks by the team | Feature | 6 |
| tov | Number | Total turnovers committed by the team | Feature | 14 |
| wl | Text | Game result: W = win, L = loss | Target | W |

---

## Step 4: Format the Worksheet (MOS Skills)

Apply the following Excel formatting:

- Bold the header row
- Apply a light fill color to the header row
- Add borders to all cells
- Auto-fit column widths
- Center-align the **Role (ML)** column

Optional (recommended):
- Convert the range into an **Excel Table**
- Apply a professional table style

---

## Step 5: Why This Matters

This data dictionary:
- Explains what each column represents
- Identifies model inputs (features) vs the output (target)
- Supports machine learning understanding
- Demonstrates professional Excel documentation skills

This worksheet will be referenced throughout the rest of the AI04 tasks.


---

### Task 1.2: Create a Binary Win Column

Add a new column in the data worksheet (not the new data dictionary sheet you created):

**Column: Win (Numeric)**

* Formula: `=IF(wl="W", 1, 0)`
* Purpose: Convert categorical labels into numeric form for ML
* Format: Number, 0 decimals

---

### Task 1.3: Feature Averages

At the bottom of the sheet, calculate:

* Average points
* Average turnovers
* Average rebounds

Use `=AVERAGE(range)` for each.

Purpose: Establish baseline values used for comparison in models.

---

### Task 1.4: Visualization

At the bottom of the sheet, create a chart:

**Chart: Points vs Turnovers**

* Type: Scatter plot
* X-axis: Turnovers
* Y-axis: Points
* Title: "Points vs Turnovers (Game-Level Data)"

Purpose: Visualize relationships between features.

---

## Part 2: win_loss_records.xlsx – Classification Patterns

**Open:** `win_loss_records.xlsx`

This dataset summarizes team performance across a season.

### Task 2.1: Win Percentage

Add a new column:

**Column: Win Percentage**

* Formula: `=(wins / games_played) * 100`
* Format: Percentage, 1 decimal

Purpose: Compare team success levels.

---

### Task 2.2: Performance Labeling

Add a new column:

**Column: Team Tier**

* Formula:

```
=IF(win_pct >= 60, "Elite", IF(win_pct >= 50, "Above Average", IF(win_pct >= 40, "Average", "Below Average")))
```

Purpose: Simulate how ML might group teams into categories.

---

### Task 2.3: Visualization

Create a column chart:

* X-axis: Team name
* Y-axis: Win percentage
* Title: "Team Win Percentage Distribution"
* Add a horizontal reference line at 50%

Purpose: Visualize classification boundaries.

---

## Part 3: top_scorers.xlsx – Regression Thinking

**Open:** `top_scorers.xlsx`

This dataset focuses on player scoring output.

### Task 3.1: Verify Points Per Game

Add a column:

**Column: Calculated PPG**

* Formula: `=total_points / games_played`
* Format: Number, 1 decimal

Purpose: Reinforce how regression predicts numeric outcomes.

---

### Task 3.2: Scoring Levels

Add a column:

**Column: Scoring Tier**

* Formula:

```
=IF(ppg >= 25, "Elite", IF(ppg >= 20, "All-Star", IF(ppg >= 15, "Starter", "Role Player")))
```

Purpose: Compare regression (PPG) vs classification (tiers).

---

### Task 3.3: Visualization

Create a horizontal bar chart:

* Data: Top 15 players by PPG
* Title: "Top Scorers – Points Per Game"

---

## Part 4: high_scoring_games.xlsx – Pattern Recognition

**Open:** `high_scoring_games.xlsx`

This dataset contains games with 120+ points scored.

### Task 4.1: Scoring Categories

Add a column:

**Column: Scoring Level**

* Formula:

```
=IF(points >= 140, "Historic", IF(points >= 130, "Exceptional", "High"))
```

Purpose: Identify patterns in extreme outcomes.

---

### Task 4.2: Summary Statistics

Calculate:

* Average points
* Maximum points
* Total number of high-scoring games

Purpose: Understand distribution and outliers.

---

### Task 4.3: Trend Visualization

Create a line or scatter chart:

* X-axis: Game date
* Y-axis: Points scored
* Title: "High-Scoring Games Over Time"

Purpose: Identify trends that ML models might learn.

---

## Formatting Requirements

* Clear headers (bold)
* Consistent number formatting
* Readable charts with titles and labels
* Clean layout suitable for interpretation

---

## Submission Checklist

* [ ] All Excel files completed
* [ ] All required formulas added
* [ ] All charts created
* [ ] Files saved with updates
* [ ] Uploaded to GitHub in your `ai04` folder

---

## Big Picture Connection

This task builds intuition for machine learning by:

* Identifying features and targets
* Exploring relationships visually
* Understanding classification vs regression
* Preparing data for modeling in Python

**Excel helps us understand the data before we teach machines to learn from it.**
