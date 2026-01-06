---
marp: true
theme: default
paginate: true
---

# Machine Learning with Decision Trees
## Lesson 4: Train, Evaluate, and Apply

**AI/ML Course**
Medina County Career Center

---

# What We'll Cover Today

**Building on Lessons 1-3:**
✅ Data loaded, cleaned, and prepared
✅ Features encoded and X/y separated

**Today - Complete the ML Pipeline:**
1. **Train/Test Split** - Divide data properly
2. **Train Model** - Teach the decision tree
3. **Evaluate** - Measure performance
4. **Visualize** - See how it works
5. **Apply** - Make new predictions

---
```python
# Let's get caught up first
# Import the tools we need: pandas for data, matplotlib for charts, scikit-learn for ML models
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import accuracy_score, classification_report
import warnings  # Suppressing warnings will keep our notebooks clean 

warnings.filterwarnings('ignore')   # Hides all warning messages

# Load the CSV file into a DataFrame so we can work with it in Python
df = pd.read_csv("Titanic Dataset.csv")
print(f"✓ Dataset loaded: {df.shape}")      # Show number of rows and columns

# Keep only the columns we need for our model (removes extra/unnecessary data)
df = df[['pclass', 'survived', 'sex', 'age', 'sibsp', 'parch', 'fare', 'embarked']]
print(f"✓ Features selected: {df.shape[1]} columns")

# Convert "fare" to a numeric type (non-numeric values turn into NaN if needed)
df['fare'] = pd.to_numeric(df['fare'], errors='coerce')

# Fill missing ages/fares with the median and remove rows missing "embarked"
df['age'].fillna(df['age'].median(), inplace=True)     # Replace missing ages
df['fare'].fillna(df['fare'].median(), inplace=True)   # Replace missing fares
df.dropna(subset=['embarked'], inplace=True)           # Drop rows missing a category
print(f"✓ Missing values handled: {df.isnull().sum().sum()} remaining")

# Convert text columns ("sex", "embarked") into numeric dummy variables for ML
df = pd.get_dummies(df, columns=['sex', 'embarked'], drop_first=True)
print(f"✓ Categorical variables encoded")

# Split data into features (X) the model uses, and the target (y) we want to predict
X = df.drop('survived', axis=1)    # All columns except the answer
y = df['survived']                 # The column we want to predict

print(f"\n✓ Data preparation complete!")
print(f"X shape: {X.shape} (rows, features)")   # How many rows/features we have
print(f"y shape: {y.shape} (rows)")             # Number of target labels
print(f"Feature names: {X.columns.tolist()}")  # The final features used for ML
print(f"\nSurvival rate: {y.mean():.2%}")      # Quick look at target distribution
```
---

# Part 1: Train/Test Split

---

# Why Split the Data?

**Bad approach:** Train on ALL data, test on SAME data
- Like memorizing test answers
- Doesn't show if you truly learned

**Good approach:** Train on SOME data, test on DIFFERENT data
- Like studying practice problems, then taking a new test
- Shows real understanding

**Standard split:** 80% training / 20% testing

---

# The Train/Test Split

```python
from sklearn.model_selection import train_test_split

# Split: 80% train, 20% test
X_train, X_test, y_train, y_test = train_test_split(
    X, y, 
    test_size=0.2,      # 20% for testing
    random_state=42     # Reproducible results
)

print(f"Training: {X_train.shape[0]} passengers")
print(f"Testing: {X_test.shape[0]} passengers")
```

**Result:** ~1045 training, ~262 testing

---

# Why random_state=42?

**Random splitting is important:**
- Prevents bias (all rich people in one set)
- Both sets represent full data

**random_state=42:**
- Makes the "random" split repeatable
- Everyone gets same results
- Any number works (42 is tradition!)

---

# Part 2: Training the Model

---

# Create and Train the Model

```python
from sklearn.tree import DecisionTreeClassifier

# Create model
model = DecisionTreeClassifier(
    max_depth=5,        # Limits tree depth (prevents overfitting)
    random_state=42     # Reproducible tree
)

# Train model (this is where learning happens!)
model.fit(X_train, y_train)

print("✓ Model trained!")
print(f"Tree depth: {model.get_depth()}")
print(f"Leaves: {model.get_n_leaves()}")
```

---

# What Happens During Training?

**The model learns patterns:**
1. Examines all training passengers
2. Finds which features best predict survival
3. Builds decision rules (the tree structure)

**Example patterns learned:**
- "Most women survived"
- "Most 1st class passengers survived"  
- "Children were more likely to survive"

**Like a child learning from examples!**

---

# Part 3: Evaluating Performance

---

# Make Predictions and Calculate Accuracy

```python
from sklearn.metrics import accuracy_score, classification_report

# Make predictions on test set
y_pred = model.predict(X_test)

# Calculate accuracy
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy: {accuracy:.2%}")

# Detailed metrics
print(classification_report(y_test, y_pred, 
                          target_names=['Died', 'Survived']))
```

**Typical result:** 80-85% accuracy

---

# Understanding the Metrics

### **Accuracy — “How often was the model correct overall?”**

* Measures the **percentage of all predictions that were correct**
* Example:

  * 0.80 accuracy → about **210 correct out of 262**
* **BUT:** Accuracy can be misleading if **one class appears much more often** than the other

  * *Class = the category we predict (Died vs Survived)*
  * A model could get high accuracy by always predicting the **majority** class

---

### **Precision — “Model: When I say someone survived, how often am I right?”**

* Looks at only the cases the model **predicted as survived**
* High precision = few **false alarms** (false positives)

  > Of the passengers the model said survived, how many actually survived?

---

### **Recall — “Model: Out of all the real survivors, how many did I find?”**

* Looks at the **actual survivors** in the test set
* High recall = few **missed survivors** (false negatives)

  > Did the model find most of the true survivors?

---

### **F1-Score — “Team score: balance point between the scores of precision + recall”**

* A single number combining both metrics
* Useful when:

  * One class is smaller than the other
  * Precision is high but recall is low (or vice-versa)

  > F1 is a fair way to judge the model when precision and recall disagree.

---

# Why These Metrics Matter

* **Accuracy** shows *overall* performance
* **Precision** shows how *trustworthy* positive predictions are
* **Recall** shows how *complete* the model is at finding positives
* **F1** gives a balanced view when classes are uneven

---

# Feature Importance

```python
# Which features mattered most?
importance = pd.DataFrame({
    'feature': X.columns,
    'importance': model.feature_importances_
}).sort_values('importance', ascending=False)

print(importance)

# Visualize
plt.figure(figsize=(10, 6))
plt.barh(importance['feature'], importance['importance'])
plt.xlabel('Importance')
plt.title('Feature Importance')
plt.show()
```

**Typically:** sex_male is most important!

---

# Part 4: Visualization

---

# Visualize the Decision Tree

```python
from sklearn.tree import plot_tree

plt.figure(figsize=(20, 10))
plot_tree(model, 
          feature_names=X.columns,
          class_names=['Died', 'Survived'],
          filled=True,      # Color by prediction
          rounded=True,     # Rounded boxes
          fontsize=10)
plt.title("Titanic Survival Decision Tree")
plt.show()
```

**Now you can see HOW the model makes decisions!**

---

# Reading the Tree

**Each box (node) shows:**
- **Question:** e.g., "sex_male ≤ 0.5"
- **Gini:** Impurity measure (0 = pure)
- **Samples:** Number of passengers
- **Value:** [died, survived] counts
- **Class:** Final prediction

**Colors:**
- Orange = Predicts "died"
- Blue = Predicts "survived"

---

# Example Decision Path

```
sex_male ≤ 0.5?
├─ Yes (female): → High survival
│   └─ pclass ≤ 2.5?
│       ├─ Yes (1st/2nd): → Survived!
│       └─ No (3rd): → Check age...
└─ No (male): → Lower survival
    └─ age ≤ 6.5?
        ├─ Yes (child): → Survived!
        └─ No (adult): → Died
```

**The model learned "women and children first"!**

---

# Part 5: Making New Predictions

---

# Predict New Passengers

```python
# Create hypothetical passenger
# Order: [pclass, age, sibsp, parch, fare, sex_male, embarked_Q, embarked_S]
new_passenger = [[3, 25, 0, 0, 7.25, 1, 0, 1]]
# 3rd class, 25yo male, no family, low fare, boarded at S

# Make prediction
prediction = model.predict(new_passenger)
probability = model.predict_proba(new_passenger)

print(f"Prediction: {'Survived' if prediction[0] == 1 else 'Died'}")
print(f"Survival probability: {probability[0][1]:.2%}")
```

---

# Test Different Scenarios

**Scenario 1:** Wealthy young woman
```python
woman_1st = [[1, 25, 0, 0, 100, 0, 0, 1]]
```

**Scenario 2:** Poor elderly man
```python
man_3rd = [[3, 65, 0, 0, 7.25, 1, 0, 1]]
```

**Scenario 3:** Young boy with family
```python
boy_3rd = [[3, 5, 1, 2, 20, 1, 0, 1]]
```

**Try different combinations and see what the model predicts!**

---

# Complete ML Pipeline Summary

```python
# 1. Split data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 2. Create and train model
model = DecisionTreeClassifier(max_depth=5, random_state=42)
model.fit(X_train, y_train)

# 3. Evaluate
y_pred = model.predict(X_test)
print(f"Accuracy: {accuracy_score(y_test, y_pred):.2%}")

# 4. Visualize
plot_tree(model, feature_names=X.columns, filled=True)

# 5. Predict new data
new_passenger = [[...]]
model.predict(new_passenger)
```

---

# Real-World Applications

**Decision trees are used for:**
- **Medical diagnosis:** Predict diseases from symptoms
- **Loan approval:** Assess creditworthiness
- **Customer churn:** Identify at-risk customers
- **Fraud detection:** Flag suspicious transactions
- **Product recommendations:** Suggest relevant items

**Why?** Easy to understand, explainable, handles mixed data

---

# Limitations & Next Steps

**Pros:**
✓ Easy to understand and visualize
✓ No complex preprocessing needed
✓ Handles numerical and categorical data

**Cons:**
✗ Can overfit (memorize training data)
✗ Unstable (small changes → big differences)
✗ Biased toward features with more levels

**Next steps:** Random Forests, Gradient Boosting (ensemble methods)

---

# Key Terms to Remember

- **Train/Test Split:** Divide data for honest evaluation
- **Training:** Model learns patterns from data
- **Accuracy:** % of correct predictions
- **Precision/Recall:** Quality metrics for predictions
- **Feature Importance:** Which features matter most
- **Overfitting:** Memorizing training data
- **Decision Path:** Route from root to prediction
- **predict_proba():** Get probability estimates

---

# What You've Accomplished!

**Technical Skills:**
- Complete ML pipeline from raw data to predictions
- Data cleaning and preparation
- Model training and evaluation
- Performance analysis
- Visualization and interpretation

**This workflow applies to ALL machine learning projects!**

---

# Practice Task

Complete **ai03dTasks.ipynb**:

1. Run setup to prepare data
2. Perform train/test split
3. Train decision tree model
4. Evaluate performance with multiple metrics
5. Calculate and visualize feature importance
6. Visualize the decision tree
7. Make predictions on new scenarios
8. Reflect on the complete process

---

# Questions?

**Congratulations on completing the Decision Trees unit!**

Remember: Machine learning is 80% data preparation, 20% modeling.

The skills you learned apply to ANY ML project!

