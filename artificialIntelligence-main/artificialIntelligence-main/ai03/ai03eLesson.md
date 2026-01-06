---
marp: true
theme: default
paginate: true
size: 16:9
---

<!-- _class: lead -->

# ML Practice: Heart Disease Prediction
## The Real-World Data Science Dilemma

**AI/ML Applications | Practice Lesson**

---

## Learning Objectives

By the end of this lesson, you will:
- Apply ML workflow to medical data with **real-world missing data problems**
- **Compare two approaches** to handling missing data
- Understand why **data quality matters more than quantity** (sometimes)
- Learn why **metrics can lie** when testing on synthetic data
- Think critically about **ethics AND reliability** in medical ML

**Key Question:** When data is missing, what should we do?

---

## The Dataset

**Source:** Heart Disease UCI (Kaggle)
- **920 patients** from 4 hospitals (1980s data)
- **16 features**: age, blood pressure, cholesterol, test results
- **Target:** Does patient have heart disease? (yes/no)

**Real Stakes:** Early detection saves lives

---

## Understanding the Features

We renamed medical jargon to plain English:

| Original | Easy Name | What It Means |
|----------|-----------|---------------|
| `trestbps` | `resting_bp` | Blood pressure at rest |
| `chol` | `cholesterol` | Cholesterol level |
| `thal` | `blood_flow` | Blood flow test ⚠️ **CRITICAL** |
| `ca` | `blocked_vessels` | # of blocked vessels ⚠️ **EXPENSIVE** |
| `exang` | `exercise_chest_pain` | Chest pain during exercise? |

---

## The Problem We Discovered

**Missing Data Analysis:**

| Feature | Missing | Percent |
|---------|---------|---------|
| `blocked_vessels` | 611 patients | **66%** |
| `blood_flow` | 486 patients | **53%** |
| `stress_test_slope` | 309 patients | **34%** |

**Why so much missing?**
- These tests are **expensive** ($5,000+ for angiogram)
- **Invasive** procedures
- Only ordered when doctors **already suspect disease**

---

## The Big Decision

### What do we do with missing data?

**Option 1: Drop rows** (Clean Data Path)
- ✅ Only use real test results
- ✅ No fabricated data
- ❌ Lose 67% of patients (920 → 299)

**Option 2: Fill missing values** (Maximum Data Path)
- ✅ Keep all 920 patients
- ✅ Larger training set
- ❌ ~67% of data becomes synthetic

**We'll try BOTH and compare!**

---

## The Workflow (Same as Titanic!)

```python
# 1. Load data
df = pd.read_csv('heart_disease_uci.csv')

# 2. Rename columns for clarity
df = df.rename(columns={'trestbps': 'resting_bp', 'thal': 'blood_flow', ...})

# 3. Create target variable (0=healthy, 1=disease)
df['has_disease'] = (df['num'] > 0).astype(int)

# 4. Handle missing data (TWO PATHS!)
# Path A: Drop rows missing blocked_vessels or blood_flow
# Path B: Fill all missing values with median/mode

# 5. Encode categorical variables
X = pd.get_dummies(X, drop_first=True)

# 6. Train/test split & train model
model = DecisionTreeClassifier(max_depth=5, random_state=42)
```

---

## Path A: Clean Data (299 patients)

```python
# Drop rows with missing critical tests
df_clean = df.dropna(subset=['blocked_vessels', 'blood_flow'])
# Result: 299 patients (100% real data)
```

**Pros:**
- ✅ All data is REAL medical tests
- ✅ Trustworthy metrics
- ✅ Ethically sound

**Cons:**
- ❌ Only 60 test patients
- ❌ Smaller training set

---

## Path B: Maximum Data (920 patients)

```python
# Fill missing values
for col in numeric_cols:
    df[col] = df[col].fillna(df[col].median())
for col in categorical_cols:
    df[col] = df[col].fillna(df[col].mode()[0])
# Result: 920 patients (67% contains synthetic data)
```

**Pros:**
- ✅ 184 test patients (3x more)
- ✅ Larger training set

**Cons:**
- ❌ 67% of data is fabricated
- ❌ Questionable reliability

---

## The Results: First Look

**Path A (Clean Data):**
- Accuracy: **77%** on 60 test patients
- Recall (catching disease): **64%**
- False Negative Rate: **36%** (missed 10 out of 28 sick patients)

**Path B (Maximum Data):**
- Accuracy: **78%** on 184 test patients
- Recall (catching disease): **80%**
- False Negative Rate: **20%** (missed 20 out of 102 sick patients)

**Initial reaction:** Path B looks better! 

---

## WAIT - Don't Compare Raw Counts!

**The Problem:** Different sample sizes!

**Path A:** Missed 10 out of 28 sick patients = **36% miss rate**
**Path B:** Missed 20 out of 102 sick patients = **20% miss rate**

**Key Insight:** Path B's "20 missed patients" sounds worse than Path A's "10 missed patients" BUT:
- Path B had 3.6x more sick patients to test
- If Path A had 102 sick patients at 36% miss rate → would miss **37 patients**!

**Always compare RATES, not raw numbers!**

---

## The REAL Problem with Path B

### Can We Even Trust These Numbers?

**Path B's test set:** 184 patients
- ~**67% have synthetic data** (~123 patients)
- ~**33% have real data** (~61 patients)

**The Circular Reasoning Trap:**
1. We filled missing `blood_flow` with "normal" (most common)
2. Model learned patterns from our fabrications
3. Test patient missing `blood_flow` → We fill with "normal"
4. Model predicts based on the fake data we just fed it
5. We say "Correct!" → **But based on what?**

---

## The Devastating Question

**What is Path B really measuring?**

- ✅ Path B might be **90% accurate on synthetic data** (easy - it learned from it!)
- ❌ Path B might be **50% accurate on real data** (actual medical performance)
- Average: 78% (meaningless metric!)

**We have NO WAY to know its true performance on real patients!**

---

## The Real Comparison

| Metric | Path A | Path B |
|--------|--------|--------|
| Accuracy | **77% on REAL data** | 78% on mixed data |
| False Negative Rate | 36% | 20% |
| Test Set | 60 real patients | 184 mixed (67% synthetic) |
| **Can we trust it?** | ✅ **YES** | ❌ **NO** |
| Real-world use | ✅ Will work on new patients | ❓ Unknown performance |

**Key Insight:** Path A's 77% means something. Path B's 78% might not.

---

## Feature Importance Reveals the Problem

**Path A (Clean Data) - Top Features:**
1. `blood_flow_normal` (35%) ← **From real tests**
2. `blocked_vessels` (16%) ← **From real tests**
3. `cholesterol` (8%)

**Path B (Maximum Data) - Top Features:**
1. `exercise_chest_pain` (36%)
2. `cholesterol` (21%)
3. `age` (10%)

**Notice:** Path B doesn't rely on the features we fabricated as much!
**Why?** The synthetic data created noise, not signal.

---

## The Deployment Problem

**New patient walks in without expensive tests...**

**Path A (Honest):**
- "Sorry, our model requires these tests first"
- Honest but limited use case

**Path B (Trap):**
- Option 1: Make up test results → Predicting your own fabrications
- Option 2: Require real tests → You're back to Path A's use case

**Path B's "advantage" was an illusion all along!**

---

## Ethics & Real-World Use

### How Doctors Actually Use ML:

✅ **Risk screening tool** - Flag high-risk patients for more testing
✅ **Population health** - Identify who needs preventive care
✅ **Research tool** - Find patterns in large datasets
❌ **NOT for final diagnosis** - Always need doctor confirmation

### Critical Limitations:

⚠️ Model only knows training data (1980s, 4 hospitals)
⚠️ **False negatives are dangerous** (missing sick patients)
⚠️ Bias if training data lacks diversity
⚠️ **Synthetic data makes metrics unreliable**

---

## Key Takeaways

### What You Learned:

1. **Data quality matters more than quantity** (sometimes)
   - 77% on 299 real patients > 78% on 920 mixed patients

2. **Metrics can lie** when testing on synthetic data
   - Circular reasoning: predicting your own fabrications

3. **Ethics and reliability go hand-in-hand**
   - Fabricating medical data is both unethical AND unreliable

4. **Compare rates, not raw counts**
   - 36% miss rate ≠ 20% miss rate (different sample sizes)

5. **Preparation choices matter more than algorithms**
   - How you handle missing data can make or break your model

---

## Discussion Questions

**Before starting the lab:**

1. If Path B had "better" accuracy with trustworthy metrics, would that make it okay to use fabricated test results?

2. When a new patient comes in without the expensive tests, which model can actually help them?

3. In what situations would you choose data quantity over data quality? When would you do the opposite?

4. What would you do if you ONLY had 100 patients total?

---

## The Lab Assignment

**You will:**
1. Build BOTH models (Path A and Path B)
2. Compare their performance using proper rate-based metrics
3. Calculate how much synthetic data contaminates Path B
4. Decide which model you would deploy in a real hospital
5. Defend your choice with evidence

**Files needed:**
- `heart_disease_uci.csv` (dataset)
- `ai03eTasks_dual_path_FINAL.ipynb` (your task notebook)

**Key insight:** There's no "right" answer - only informed decisions with clear tradeoffs.

---

## Extension: What If We Had More Time?

**Advanced approaches to missing data:**

1. **Multiple Imputation** - Create several synthetic datasets, average results
2. **Model-based Imputation** - Use other features to predict missing values
3. **Indicator Variables** - Add "was_missing" flag as a feature
4. **Collect More Data** - The best solution (but expensive/time-consuming!)

**For this class:** We're learning the fundamental tradeoff between quality and quantity.

---

<!-- _class: lead -->

## Remember:

> "You now think like a data scientist, not just a coder."

Real-world ML is messy. There are no perfect answers.
Only informed decisions with clear tradeoffs.

**Let's build both models and see what happens!**

---

## Submission Checklist

Before you submit:
- [ ] All code cells run without errors
- [ ] All 13 questions answered with thought and evidence
- [ ] Comparison table filled in
- [ ] Can defend your model choice (Question 11)
- [ ] Understand the synthetic data reliability problem
- [ ] Final reflection complete

**File:** `ml_practice_heart_disease_comparison.ipynb`
**Upload to:** GitHub

---

<!-- _class: lead -->

# Questions?
