---
marp: true
theme: default
class: invert
paginate: true
---

# Welcome Back!
## AI Course Review + What's Next

**Database Applications Development**
**Software Engineering | Medina County Career Center**

---

## What We've Learned So Far

**Lesson 01-02:** Introduction to Machine Learning
- What is AI/ML?
- Decision trees (visual + coded in Python)
- If/elif/else as decision-making logic

---

**Lesson 03:** Data Preparation with Pandas
- Loading CSV files
- Cleaning data (handling missing values)
- Encoding categorical variables (one-hot encoding)
- Separating features (X) and target (y)
- Train/test splitting
- Training decision tree models
- Evaluating accuracy

**You've completed a full ML pipeline!**

---

## The Machine Learning Workflow

```
1. Load Data          → pd.read_csv()
2. Explore Data       → df.head(), df.info()
3. Clean Data         → fillna(), dropna()
4. Encode Categories  → pd.get_dummies()
5. Split Data         → train_test_split()
6. Train Model        → model.fit(X_train, y_train)
7. Evaluate Model     → accuracy_score()
8. Make Predictions   → model.predict()
```

**This process works for ANY supervised learning problem!**

---

## Key Terms - Quick Review

**Features (X):** Input variables used to make predictions
- Example: age, fare, passenger class

**Target (y):** What we're trying to predict
- Example: survived (1 or 0)

**Training Data:** Data the model learns from

**Testing Data:** Data we use to evaluate the model (unseen!)

**Accuracy:** Percentage of correct predictions

---

## Key Terms - Data Preparation

**Missing Values:** Gaps in data (NaN)
- Handle with: median, mean, or drop rows

**Categorical Data:** Text labels (male/female, embarked location)
- Convert to numbers using **one-hot encoding**

**Dummy Variables:** Binary columns representing categories
- `pd.get_dummies(drop_first=True)`

**Why drop_first?** Avoid redundancy (if not male, must be female)

---

## Decision Trees - What They Do

```
              Fare > $30?
                  │
         ┌────────┴────────┐
         │                 │
        YES                NO
         │                 │
    Sex = female?      Survived?
         │                 │
    ┌────┴────┐           ...
    │         │
   YES       NO
    │         │
 Survived  Not Survived
```

**The computer learns these questions from data!**

We provide examples → Model finds patterns → Makes predictions

---

## What's Next: Real-World Data

**The Problem:**
- We've used CSV files (Titanic dataset)
- What about **millions** of rows?
- What if data is updated daily?
- What if you only need **specific records**?

**The Solution: Databases + SQL**

---

## Why AI Engineers Need SQL

**Industry Reality:**
- Most ML data comes from **databases**, not CSV files
- Companies store billions of records
- SQL lets you **filter** data BEFORE loading into Python
- SQL lets you **combine** multiple data sources
- SQL lets you **aggregate** data to create new features

**This Week:** Learn SQL in the context of machine learning

---

## Our Dataset: NBA Basketball

**Why NBA data?**
- Large dataset (thousands of games, hundreds of players)
- Multiple related tables (teams, players, games)
- Real ML applications:
  - Predict game winners
  - Predict player performance
  - Analyze team strategies


---

## SQL Basics Preview

**SELECT** - Choose which columns (features) you want
**WHERE** - Filter rows (training examples)
**JOIN** - Combine related tables
**GROUP BY** - Create summary statistics (new features!)
**ORDER BY** - Sort results

**Example:**
```sql
SELECT player_name, points, assists, rebounds
FROM player_stats
WHERE points > 20 AND season = '2021-22'
ORDER BY points DESC
LIMIT 10
```

---

## The AI Workflow with SQL

```
┌──────────────┐
│   Database   │  (Lots of rows stored efficiently)
│   (SQLite)   │
└──────┬───────┘
       │
       │  SQL Query (filter, aggregate, join)
       ▼
┌──────────────┐
│   Pandas     │  (Only load what you need!)
│  DataFrame   │
└──────┬───────┘
       │
       │  Data preparation (clean, encode)
       ▼
┌──────────────┐
│   ML Model   │  (Train decision tree, make predictions)
│  (sklearn)   │
└──────────────┘
```

---

## This Week's Plan

**Today:** SQL Introduction - SELECT, WHERE, ORDER BY, LIMIT
**Tomorrow:** Practice writing queries with NBA data
**Later:** Aggregations (GROUP BY) to create ML features
**End of Week:** Build ML model using SQL-prepared data

**You'll learn SQL while preparing for your next ML project!**

---

## Certification Alignment

**What we're working toward:**

**CertIPort SQL Database Fundamentals**
- SELECT queries, filtering, sorting, aggregations, joins

**Microsoft Excel Associate (MOS)**
- We'll export SQL results to Excel
- Create charts, formulas, pivot tables

**These skills = employable data analyst/ML engineer!**

---

## Let's Get Started!

**Open:** `ai04a_SQL_Introduction.ipynb`

**Today you'll:**
- Connect to NBA database
- Write basic SQL queries
- Load results into pandas DataFrames
- Prepare data for machine learning

**Remember:** SQL is just a tool to get the right data for your ML models!

