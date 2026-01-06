---
marp: true
theme: default
paginate: true
header: 'AI Lesson 01: What is Artificial Intelligence?'
footer: 'Medina County Career Center'
---

# What is Artificial Intelligence?

**Lesson 01: Introduction to AI**

---

## Learning Objectives

- Define artificial intelligence and distinguish it from traditional programming
- Identify examples of AI in everyday life
- Understand the difference between rule-based systems and learning systems
- Recognize the three main types of AI approaches

---

## What is Artificial Intelligence?

**Artificial Intelligence (AI)** is when computers perform tasks that typically require human intelligence:

- Recognizing faces in photos
- Understanding spoken language
- Making recommendations
- Playing games
- Driving cars
- Answering questions

---

## The Key Difference

**Traditional Programming:**
```
Input → Rules (written by programmer) → Output
```

**Artificial Intelligence:**
```
Input + Output Examples → AI learns patterns → Can handle new inputs
```

---

## Example: Spam Filter

### Traditional Programming Approach

```python
def is_spam(email):
    # Programmer writes ALL the rules
    if "FREE MONEY" in email:
        return True
    if "CLICK HERE NOW" in email:
        return True
    if "You won" in email:
        return True
    return False
```

**Problem:** What if spam gets creative? You'd need to update the code constantly!

---

## Example: Spam Filter (continued)

### AI Approach

```
AI examines thousands of spam and non-spam emails
↓
AI learns patterns (without explicit rules)
↓
AI can identify NEW spam it's never seen before
```

**Key Insight:** The programmer doesn't write the rules—the AI discovers them!

---

## Real-World AI Examples

### 1. Netflix Recommendations 🎬
- **What it does:** Suggests shows you might like
- **How:** Analyzes what you've watched, what similar people watched, and learns patterns
- **Traditional approach would require:** Manually programming rules for millions of users and shows (impossible!)

---

## Real-World AI Examples

### 2. Snapchat Filters 📸
- **What it does:** Recognizes your face and adds effects
- **How:** AI learned from millions of face images to detect facial features
- **Traditional approach would require:** Writing code for every possible face, angle, lighting (impossible!)

---

## Real-World AI Examples

### 3. Google Translate 🌍
- **What it does:** Translates between 100+ languages
- **How:** AI learned from millions of translated documents
- **Traditional approach would require:** Programming every grammar rule and word combination (nearly impossible!)

---

## Real-World AI Examples

### 4. Siri / Alexa 🗣️
- **What it does:** Understands spoken commands
- **How:** AI learned speech patterns from recordings
- **Traditional approach would require:** Programming rules for every accent, speed, and phrase (impossible!)

---

## Three Main Approaches to AI

1. **Rule-Based Systems** (Decision Trees)
2. **Machine Learning** (Supervised Learning Models)
3. **Neural Networks** / Deep Learning

---

## 1. Rule-Based Systems

**Decision Trees**

- Programmer writes explicit rules
- Computer follows them exactly

**Example:**
"If temperature > 80°F, predict shorts."

**Good for:** Clear, well-defined problems

---

## 2. Machine Learning

The programmer provides **labeled examples**, not rules.
The AI **learns the relationship** between inputs and outputs.

Two main types:
- **Regression Models** (predicting numbers)
- **Classification Models** (predicting categories)

---

## Machine Learning: Regression

**Predicts numbers**

Models include:
- **Linear Regression** - Best straight-line fit
- **Polynomial Regression** - Curved line for complex patterns
- **Random Forest Regression** - Many decision trees working together

**Example:** Predict the exact temperature tomorrow

**Use when:** The output is a **number**

---

## Machine Learning: Classification

**Predicts categories**

Models include:
- **Logistic Regression** - Predicts using probability
- **Naive Bayes** - Text classification
- **Decision Trees** - If/else-style branches
- **Random Forests** - Many decision trees voting
- **Support Vector Machines (SVM)** - Finds boundary between categories

**Example:** Predict if an email is spam or not

**Use when:** The output is a **label** (category)

---

## 3. Neural Networks / Deep Learning

Inspired by the brain, learns complex and abstract patterns.

**Examples:**
- Recognizing cats in photos
- Translating languages
- Voice recognition

**Good for:** Vision, audio, language, and very complex tasks

---

## Summary

- **Regression** predicts numbers
- **Classification** predicts categories
- Both are **supervised machine learning**
- **Rule-based systems** use explicit human-written rules
- **Neural networks** handle very complex tasks

---

## Visual Comparison

### 🧩 Traditional Programming
**Programmer → Writes Rules → Computer Executes**

**Example:** If age < 13, deny account

**Key Idea:** Rules are hard-coded by the programmer with no learning

---

## Visual Comparison

### ⚙️ Rule-Based AI (Expert Systems)
**Human Experts → Encode Knowledge → AI Follows**

**Example:** If patient has fever AND cough → possible flu

**Key Idea:** AI does not learn from data. All logic written by humans based on expert knowledge

---

## Visual Comparison

### 🤖 Machine Learning
**Data → Algorithm Learns Patterns → AI Makes Decisions**

**Example:** Given weather & user activity data, AI learns:
*sunny AND temp > 70 → recommend beach*

**Key Idea:** The model finds rules automatically and improves with more data

---

## Quick Comparison Table

| **Type** | **Who Creates Rules?** | **Learns?** | **Uses Data?** | **Example** |
|----------|------------------------|-------------|----------------|-------------|
| **Traditional Programming** | Human programmer | ❌ | ❌ | Form validation |
| **Rule-Based AI** | Human experts | ❌ | ❌ | Medical diagnosis |
| **Machine Learning** | Learns from data | ✅ | ✅ | Netflix recommender |

---

## When to Use Each Approach

| Approach | Best For | Example |
|----------|----------|---------|
| **Traditional Programming** | Simple, clear rules | Calculator, login system |
| **Rule-Based AI** | Multiple conditions | Medical diagnosis, game AI |
| **Machine Learning** | Pattern recognition | Face recognition, spam detection |

---

## AI is Already Everywhere

**Social Media:**
- Which posts appear in your feed? *AI*
- Face tagging in photos? *AI*

**Shopping:**
- Product recommendations? *AI*
- Fraud detection? *AI*

**Entertainment:**
- YouTube suggestions? *AI*
- Spotify playlists? *AI*

---

## AI in Your Daily Life

**School/Work:**
- Grammar checking (Grammarly)? *AI*
- Autocomplete in Google Search? *AI*
- Photo enhancement on your phone? *AI*

**Challenge:** Can you identify 3 places you used AI today without realizing it?

---

## What AI is NOT

❌ **AI is not magic** - It's math and patterns

❌ **AI is not always "smart"** - It can make mistakes

❌ **AI doesn't "understand" like humans** - It recognizes patterns

❌ **AI can't do everything** - It's trained for specific tasks

---

## The AI Spectrum

```
Simple ←─────────────────────────────────────────→ Complex

Thermostat        Decision Trees       Image Recognition      Self-Driving Cars
(if/else)         (many if/else)       (ML patterns)          (Deep Learning)
```

---

## Key Takeaways

1. AI makes computers act intelligently without programming every rule
2. Traditional programming requires explicit instructions
3. Rule-based AI uses programmer-defined logic for complex decisions
4. Machine Learning discovers patterns from data
5. AI is everywhere in modern technology
6. Different problems need different AI approaches

---

## Discussion Questions

Think about these:

1. **Can you identify 3 places you used AI today without realizing it?**

2. **When would traditional programming be BETTER than AI?**
   - Hint: Think about a calculator

3. **What's something that would be hard to program traditionally but easy for AI?**
   - Hint: Think about recognizing faces

---

## Looking Ahead

**This week we'll focus on Decision Trees** - the bridge between traditional programming and machine learning!

**Why start here?**
- Uses Python skills you already have (if/elif/else)
- Shows how AI makes decisions
- Foundation for understanding more complex AI

**Next lesson:** We'll build our first decision tree!

---

## Quick Check

Before moving on, make sure you can:

- [ ] Explain the difference between traditional programming and AI
- [ ] Give 3 examples of AI in your daily life
- [ ] Describe when rule-based AI is useful
- [ ] Understand that AI learns patterns rather than following programmed rules

---

## Pro Tip

**Start noticing AI in your daily life!**

When you see "Recommended for you" or autocomplete, that's AI at work!

---

# Questions?

Thank you!