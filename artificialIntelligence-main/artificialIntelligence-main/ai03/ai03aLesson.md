---
marp: true
theme: default
paginate: true
---

# Machine Learning with Decision Trees
## Lesson 1: Introduction & Setup

**AI/ML Course**
Medina County Career Center

---

# What We're Building

In this series of lessons, you'll learn how to:
- Load and inspect real-world data
- Clean and prepare data for machine learning
- Build a **decision tree** model
- Evaluate how well your model works
- Use your model to make predictions

**Real-world dataset**: Titanic passenger data
**Goal**: Predict who survived the Titanic disaster

---

# What is a Decision Tree?

A **decision tree** is like a flowchart that makes decisions by asking yes/no questions.

**Example**:
- Is the passenger's fare > $30?
  - **Yes** → Is the passenger female?
    - **Yes** → Predict: Survived ✓
    - **No** → Predict: Did not survive ✗
  - **No** → Predict: Did not survive ✗

The computer learns these questions automatically from the data!

---

# The Titanic Dataset

We'll use data about Titanic passengers to predict survival.

**Features we'll use**:
- `pclass`: Passenger class (1st, 2nd, 3rd)
- `sex`: Male or female
- `age`: Age in years
- `sibsp`: Number of siblings/spouses aboard
- `parch`: Number of parents/children aboard
- `fare`: Ticket price
- `embarked`: Port where they boarded (C, Q, or S)

Note on where the Titanic embarked so we know what C, Q, and S stand for: 
- C = Cherbourg (France) 
- Q = Queenstown — which is now known as Cobh (Ireland) 
- S = Southampton (England) — this is where Titanic began its maiden voyage.

### Target (what we're predicting):
We are using the `survived` (1 = yes, 0 = no) variable as our final output of the decision tree.

---

# Libraries We'll Use

**pandas** → Working with tables of data (DataFrames)
**scikit-learn** → Machine learning tools
**matplotlib** → Drawing charts and visualizations

Think of these as toolboxes with pre-built functions for common tasks.

---

# Step: Install Libraries (One-Time Setup)

If you're using Jupyter or VS Code for the first time, you may need to install these libraries.

```python
# Run this ONCE in a terminal or Jupyter cell
# Remove the # to uncomment and run

# !pip install scikit-learn pandas matplotlib kagglehub
```

**What this does**: Downloads and installs the libraries we need.

**Note**: In our classroom setup, these might already be installed!

---

# Step: Import Libraries

Once installed, we need to **import** them into our Python file.

```python
import pandas as pd  # for working with tables (dataframes)
from sklearn.model_selection import train_test_split  # split data
from sklearn.tree import DecisionTreeClassifier, plot_tree  # decision tree
from sklearn.metrics import accuracy_score, classification_report  # evaluation
import matplotlib.pyplot as plt  # to draw the tree
```

**What this does**: Makes the functions from these libraries available in our code.

---

# Understanding the Imports

```python
import pandas as pd
```
- Imports the pandas library
- `as pd` creates a shortcut (we can type `pd` instead of `pandas`)

```python
from sklearn.tree import DecisionTreeClassifier
```
- Imports just the `DecisionTreeClassifier` from scikit-learn
- This is the tool that builds our decision tree

**scikit-learn** = `sklearn` (they're the same thing!)

---

# Step: Load the Data

We'll use the **Titanic dataset** from Kaggle.

```python
import kagglehub

# Download the Titanic dataset from Kaggle
path = kagglehub.dataset_download("sakshisatre/titanic-dataset")
print("Path to dataset files:", path)
```

**What this does**:
- Downloads the Titanic dataset
- Saves it to your computer (in a cache folder)
- Shows you where it saved the file

---

## Save the Dataset and Load as a Local File

 You'll have to copy/save the dataset to the same folder as your ipynb file for ease of importing it into our environment (JupyterLab in this case):

```python
# Load from a file in the same folder as your notebook
df = pd.read_csv("Titanic Dataset.csv")
```

**`df`** = short for "DataFrame" (a table in pandas)

**Important**: Make sure the CSV file is in the same folder as your Python file!

---

# Step: Inspect the Data

Let's look at what we loaded:

```python
# Show the first 5 rows
print("First 5 rows of the dataset:")
print(df.head())
```

**Expected output**:
```
   pclass  survived  name              sex    age  sibsp  parch  ...
0       1         1  Allen, Miss. ...  female  29.0      0      0  ...
1       1         1  Allison, Master  male     0.92     1      2  ...
...
```

---

# Understanding .head()

```python
df.head()      # Shows first 5 rows (default)
df.head(10)    # Shows first 10 rows
df.tail()      # Shows last 5 rows
```

**Why do this?**
- Verify the data loaded correctly
- See what columns (features) we have
- Check if data looks reasonable

---

# Step: Check Data Info

```python
# Get information about the dataset
print("Dataset info:")
print(df.info())
```

**This tells us**:
- How many rows (passengers) we have
- How many columns (features) we have
- Data type of each column (int, float, string)
- If any values are missing (Non-Null Count)

---

# Example Output

```
<class 'pandas.core.frame.DataFrame'>
RangeIndex: 1309 entries, 0 to 1308
Data columns (total 15 columns):
 #   Column    Non-Null Count  Dtype  
---  ------    --------------  -----  
 0   pclass    1309 non-null   int64  
 1   survived  1309 non-null   int64  
 2   name      1309 non-null   object 
 3   sex       1309 non-null   object 
 4   age       1046 non-null   float64  ← Missing values!
 5   sibsp     1309 non-null   int64  
...
```

**Notice**: `age` only has 1046 values out of 1309 → we'll need to handle this!

---

# Step: Basic Statistics

```python
# Show statistics for numeric columns
print("Basic statistics:")
print(df.describe())
```

**This shows**:
- `count`: How many values
- `mean`: Average
- `std`: Standard deviation (spread)
- `min`, `25%`, `50%`, `75%`, `max`: Range of values

Helps us understand the data distribution.

---

# Example Statistics Output

```
           pclass    survived         age       sibsp       parch        fare
count   1309.00     1309.00      1046.00    1309.00    1309.00     1308.00
mean       2.29        0.38        29.88       0.50       0.39       33.30
std        0.84        0.49        14.41       1.04       0.87       51.76
min        1.00        0.00         0.17       0.00       0.00        0.00
25%        2.00        0.00        21.00       0.00       0.00        7.90
50%        3.00        0.00        28.00       0.00       0.00       14.45
75%        3.00        1.00        39.00       1.00       0.00       31.28
max        3.00        1.00        80.00       8.00       9.00      512.33
```

**Observations**: Average age ~30, average survival ~38%, fare varies widely

---

# Quick Check: Why These Steps?

1. **Install/Import**: Get the tools we need
2. **Load**: Bring the data into Python
3. **Inspect**: Understand what we're working with

**Before building a model, you must understand your data!**

This is like a chef checking ingredients before cooking.

---

# What's Next?

**Lesson 2**: Data Cleaning
- Select which features to use
- Handle missing values (like the missing ages)
- Understand why data cleaning is critical

**Remember**: Real-world data is messy! Most of machine learning is preparing data properly.

---

# Practice Task

Create a new Python file or Jupyter notebook:

1. Import the necessary libraries
2. Load the Titanic dataset (use kagglehub or a local CSV)
3. Print the first 10 rows
4. Print the dataset info
5. Print the statistics

**Bonus**: Answer these questions:
- How many passengers are in the dataset?
- What's the average age of passengers?
- How many passengers survived?

---

# Key Terms to Remember

- **DataFrame**: A table in pandas (like an Excel spreadsheet)
- **Features**: The columns we use to make predictions (pclass, age, sex, etc.)
- **Target**: What we're trying to predict (survived)
- **Import**: Bringing libraries into our code
- **Load**: Reading data from a file into our program

---

# Questions?

Next lesson: We'll clean this data and prepare it for machine learning!
