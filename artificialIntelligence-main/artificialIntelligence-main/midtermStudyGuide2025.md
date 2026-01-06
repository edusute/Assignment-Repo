# AI & Machine Learning Midterm Study Guide

## AI Fundamentals

# **What Is AI?**
- **Artificial Intelligence (AI)** refers to any computer system designed to perform tasks that normally require human intelligence—such as recognizing patterns, making decisions, or understanding language.
- AI has existed since the **1950s** and includes many approaches: rule-based systems, search algorithms, expert systems, machine learning, and more.
- **Generative AI** is *one modern branch* of AI that focuses on creating new content (text, images, audio, code), but it is **not the entirety of AI**.

---

# **What Determines AI Capabilities?**
- The **data it was trained on** (quantity, quality, diversity) is the most influential factor for machine-learning-based AI.
- The **model architecture** (decision tree, neural network, transformer, etc.) also shapes what the AI can learn or represent.
- The **compute resources** available during training and inference affect speed and complexity.

---

# **Types of Learning in Machine Learning**
### **Supervised Learning**
- Learns from **labeled examples** (input → correct output).  
- Used when you know the “correct answer” for each training example.
- Includes both **classification** and **regression** models.

**Examples of Supervised Learning Models:**
- **Decision Trees** (classification & regression)  
- **Random Forests**  
- **Linear Regression**  
- **Logistic Regression**  
- **Support Vector Machines (SVMs)**  
- **Neural Networks** (when trained on labeled data)

**Example Tasks:**
- **Classification**: image classification, spam detection  
- **Regression**: predicting house prices, forecasting sales

### **Unsupervised Learning**
- Learns by discovering **patterns in unlabeled data**.  
  *Examples: clustering customer groups, anomaly detection.*

### **Reinforcement Learning**
- Learns through **trial and error**, receiving rewards or penalties.  
  *Examples: game-playing agents, robotics control.*

---

# **Non-Learning Approaches (Traditional AI)**
### **Rule-Based AI / Expert Systems**
- Uses human-written **IF/THEN rules** and decision logic.
- Powerful for narrow, well-defined tasks but does **not learn** from data.


---

## Machine Learning Decision Trees

**ML vs Hard-Coded Decision Trees:**
- **ML Decision Trees**: Automatically discover rules from data
- **Hard-Coded Trees**: Rules written manually by programmers using if/else statements

**The ML Workflow:**
1. **Input (X)**: Data the AI uses to learn (features like age, gender, ticket price)
2. **Target (y)**: The answer the model tries to predict (like "survived")
3. **Training**: Model learns patterns from the training data
4. **Testing**: Model predicts on new, unseen data

---

## Data Preparation (60-80% of the job!)

**Why Data Cleaning Matters:**
- "Garbage in, garbage out" - messy data = bad predictions
- Most real-world data has problems that need fixing

**Common Data Prep Tasks:**

1. **Handling Missing Values**
   - Check Non-Null Count vs total rows
   - Use **median** for age (not affected by outliers like babies/elderly)

2. **Converting Categorical Data**
   - ML models need numbers, not words
   - Example: "male"/"female" → 0/1
   - Use **drop_first=True** to avoid Dummy Variable Trap (prevents redundant info)

3. **Splitting Features & Target**
   - **X (Features)**: Inputs used to make predictions
   - **y (Target)**: The answer you're trying to predict

4. **Train/Test Split**
   - 80% train / 20% test is common
   - Tests on unseen data to prevent overfitting
   - **random_state=42**: Makes the split repeatable

---

## Generative AI

**Prompt Engineering:**
- Designing queries to guide AI toward desired responses
- Providing context and examples helps AI generate better outputs

**Benefits:**
- **Efficiency**: Boosts productivity (data entry, analysis)
- **Creativity**: Helps generate new content and ideas
- **Learning**: Assists with education and exploration

**Potential Harms:**
- **Misinformation**: May generate false information
- **Bias**: Reflects biases in training data
- **Plagiarism/Copyright**: Uses data without permission
- **Hallucination**: Makes up confident-sounding false info

---

## Python Fundamentals

### Data Types
| Type | Purpose | Example |
|------|---------|---------|
| `int` | Whole numbers | `6`, `42`, `-10` |
| `float` | Decimals/real numbers | `3.14`, `2.5` |
| `str` | Text | `"hello"`, `'AI'` |
| `bool` | True/False | `True`, `False` |

### Key Functions
- `input()`: Always returns a **string**
- `int(3.9)`: **Truncates** (chops off) decimal → `3`

### Operators

**Arithmetic:**
- `**` → Exponentiation (power)
- `%` → Modulus (remainder after division)
- `//` → Integer division

**Comparison:**
- `==` → Equal to
- `!=` → NOT equal to
- `>=` → Greater than or equal to

**Logical:**
- `and` → Both must be True
- `or` → At least one must be True
- `not` → Reverses True/False

### Control Flow

**if-elif-else Chain:**
- Executes **only the first True condition**
- Skips all remaining blocks after finding a match
- `if-else` provides exactly two possible paths

**Short-Circuiting in `A and B`:**
- If A is False, Python skips B (result already known to be False)

### Loops & Strings

**range(start, stop):**
- The **stop number is excluded** from the sequence

**String Methods:**
- `.isalpha()` → Returns True if all characters are letters (A-Z, a-z)
- `.isdigit()` → Checks for digits
- `.islower()` → Checks if lowercase
- `.isspace()` → Checks for whitespace

---

## ML Libraries & Evaluation

**Key Libraries:**
- **pandas**: Working with DataFrames (tables of data)
- **sklearn (scikit-learn)**: Machine learning tools like `DecisionTreeClassifier`
- **matplotlib**: Visualization/charts

**Evaluation Metric:**
- **Accuracy**: Percentage of all predictions that were correct overall

---

## Tips

1. **Algorithm**: A sequence of steps for a computational process
2. **Data cleaning is crucial**: It's 60-80% of a data scientist's work
3. **Titanic dataset**: `survived` is the Target (y) you're predicting
4. **Median vs Mean**: Median is better for age data (outlier-resistant)
5. **Why convert text to numbers?**: ML models need math - can't calculate with words
6. **Train/Test purpose**: Prove the model understands, not just memorizes

---

## Study Strategy

✅ Review your JupyterLab decision tree projects  
✅ Understand the difference between Features vs Target in datasets  
✅ Remember: Data quality determines AI quality  
✅ Understand why we split data for training and testing  

Good luck!