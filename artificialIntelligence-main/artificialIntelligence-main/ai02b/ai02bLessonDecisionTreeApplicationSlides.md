---
marp: true
theme: default
paginate: true
header: 'AI Lesson 02b: Coding Decision Trees in Python'
footer: 'Medina County Career Center'
---

# Coding Decision Trees in Python

**Lesson 02b: From Diagrams to Code**

---

## Learning Objectives

- Translate decision tree diagrams into Python code
- Use nested if/elif/else statements to implement decision logic
- Gather user input to navigate through decision trees
- Create interactive decision-making programs
- Test and debug decision tree code

---

## From Diagram to Code

Remember this decision tree?

```
              Is it raining?
                   │
         ┌─────────┴─────────┐
         │                   │
        YES                 NO
         │                   │
    Wear jacket       Is temp < 60°F?
                            │
                  ┌─────────┴─────────┐
                  │                   │
                 YES                 NO
                  │                   │
             Wear jacket        No jacket needed
```

Let's code it!

---

## Example 1: Simple Jacket Advisor

**Activity: I need two volunteers to write the code for this tree on the smart board!**

While volunteers write the code, everyone else:
- Copy it into IDLE or VS Code
- Test it with different inputs

---

## Jacket Advisor: The Code

```python
# Get information from user
raining = input("Is it raining? (yes/no): ")
temperature = int(input("What's the temperature (°F)? "))

# Make decision
if raining == "yes":
    print("Wear a jacket (it's raining!)")
elif temperature < 60:
    print("Wear a jacket (it's cold!)")
else:
    print("No jacket needed!")
```

---

## Sample Runs
**Run 1:**
```
Is it raining? (yes/no): yes
What's the temperature (°F)? 75
Wear a jacket (it's raining!)
```
**Run 2:**
```
Is it raining? (yes/no): no
What's the temperature (°F)? 45
Wear a jacket (it's cold!)
```
**Run 3:**
```
Is it raining? (yes/no): no
What's the temperature (°F)? 72
No jacket needed!
```
---

## Key Pattern: Input → Decision → Output

```python
# 1. GATHER INFORMATION (input)
variable = input("Question?")

# 2. MAKE DECISION (if/elif/else)
if condition:
    # decision path 1
elif condition:
    # decision path 2
else:
    # default path

# 3. GIVE RESULT (output)
print("Answer")
```

---

## Example 2: Movie Rating Advisor

```
                 Age >= 13?
                     │
           ┌─────────┴─────────┐
           │                   │
          YES                 NO
           │                   │
    Contains violence?    Contains scary scenes?
           │                   │
    ┌──────┴──────┐      ┌────┴────┐
    │             │      │         │
   YES           NO     YES       NO
    │             │      │         │
Age >= 17?    Approved  Not    Approved
    │                  Approved
┌───┴───┐
│       │
YES    NO
```

---

## Movie Rating Advisor Activity

**Activity: I need two volunteers to write the code for the movie rating tree on the smart board!**

While volunteers write the code, everyone else:
- Copy it into IDLE or VS Code
- Test it with different ages and content types

---

## Movie Rating Advisor: The Code

```python
# Gather information
age = int(input("Enter age: "))
has_violence = input("Contains violence? (yes/no): ")
has_scary = input("Contains scary scenes? (yes/no): ")

# Decision tree logic
if age >= 13:
    # Teen or adult path
    if has_violence == "yes":
        if age >= 17:
            print("✅ Movie approved for viewing")
        else:
            print("❌ Too violent for your age")
    else:
        print("✅ Movie approved for viewing")
else:
    # Child path
    if has_scary == "yes":
        print("❌ Too scary for your age")
    else:
        print("✅ Movie approved for viewing")
```

---

## Sample Runs

**Run 1:**
```
Enter age: 15
Contains violence? (yes/no): yes
Contains scary scenes? (yes/no): no
❌ Too violent for your age
```

**Run 2:**
```
Enter age: 10
Contains violence? (yes/no): no
Contains scary scenes? (yes/no): no
✅ Movie approved for viewing
```

---

## Understanding Nested If Statements

**Nesting** means putting if statements inside other if statements.

```python
if condition1:          # First question
    if condition2:      # Second question (only if first is True)
        # Both true
    else:
        # First true, second false
else:
    # First false
```

**⚠️ Indentation is CRITICAL!** Each level of nesting adds one more indent.

---

## Example 3: Restaurant Recommendation

```python
print("🍽️ Restaurant Recommendation System")
print("-" * 40)

# Gather preferences
budget = int(input("Budget per person ($): "))
cuisine = input("Preferred cuisine (italian/mexican/american): ")
quick = input("Need quick service? (yes/no): ")
```

---

## Restaurant Recommendation (cont.)

```python
# Decision tree
if budget < 15:
    # Budget-friendly options
    if quick == "yes":
        if cuisine == "mexican":
            print("Recommendation: Chipotle")
        elif cuisine == "italian":
            print("Recommendation: Pizza Hut")
        else:
            print("Recommendation: Five Guys")
    else:
        if cuisine == "mexican":
            print("Recommendation: Local taco place")
        elif cuisine == "italian":
            print("Recommendation: Small Italian bistro")
        else:
            print("Recommendation: Local diner")
```

---

## Restaurant Recommendation (cont.)

```python
else:
    # Higher-end options
    if cuisine == "mexican":
        print("Recommendation: Upscale Mexican restaurant")
    elif cuisine == "italian":
        print("Recommendation: Fine Italian dining")
    else:
        print("Recommendation: Steakhouse")
```

**Sample Output:**
```
Budget per person ($): 12
Preferred cuisine (italian/mexican/american): mexican
Need quick service? (yes/no): yes
Recommendation: Chipotle
```

---

## Example 4: Study Plan Advisor

```python
print("📚 Study Plan Generator")
print("-" * 40)

# Gather information
hours_available = int(input("Hours available to study: "))
difficulty = input("Subject difficulty (easy/medium/hard): ")
test_tomorrow = input("Test tomorrow? (yes/no): ")
```

---

## Study Plan Advisor (cont.)

```python
# Generate study plan
if test_tomorrow == "yes":
    # Urgent studying
    if hours_available >= 3:
        print("\nStudy Plan:")
        print("- Review all notes (1 hour)")
        print("- Practice problems (1.5 hours)")
        print("- Take practice test (30 min)")
    else:
        print("\nStudy Plan:")
        print("- Focus on weak areas only")
        print("- Quick review of key concepts")
```

---

## Study Plan Advisor (cont.)

```python
else:
    # Regular studying
    if difficulty == "hard":
        if hours_available >= 2:
            print("\nStudy Plan:")
            print("- Deep dive into concepts (1 hour)")
            print("- Practice problems (45 min)")
            print("- Create study guide (15 min)")
        else:
            print("\nStudy Plan:")
            print("- Focus on one concept at a time")
            print("- Get help if needed!")
    elif difficulty == "medium":
        print("\nStudy Plan:")
        print("- Review notes (30 min)")
        print("- Practice problems (30 min)")
    else:
        print("\nStudy Plan:")
        print("- Quick review (15 min)")
        print("- Light practice (15 min)")
```

---

## Making Decisions More Robust

### Handling Bad Input

```python
# Basic version (can crash)
age = int(input("Enter age: "))

# Better version (validates input)
age_input = input("Enter age: ")
if age_input.isdigit():
    age = int(age_input)
    # Continue with logic...
else:
    print("❌ Please enter a number!")
```

---

## Using .lower() for Text Input

```python
# Problem: User might type "Yes", "YES", or "yes"
answer = input("Is it raining? (yes/no): ")
if answer == "yes":  # Only works if they type lowercase
    print("Bring umbrella")

# Solution: Convert to lowercase
answer = input("Is it raining? (yes/no): ").lower()
if answer == "yes":  # Now works for Yes, YES, yes
    print("Bring umbrella")
```

---

## Using 'and' / 'or' for Complex Conditions

```python
# Multiple conditions at once
temperature = int(input("Temperature (°F): "))
raining = input("Raining? (yes/no): ").lower()

if temperature < 50 and raining == "yes":
    print("Wear a jacket AND bring an umbrella!")
elif temperature < 50 or raining == "yes":
    print("Wear a jacket OR bring an umbrella")
else:
    print("You're good to go!")
```

---

## Project Template: Build Your Own

```python
# DECISION TREE TEMPLATE
print("=" * 50)
print("YOUR TITLE HERE")
print("=" * 50)

# Step 1: Gather information (2-4 questions)
var1 = input("Question 1: ")
var2 = input("Question 2: ")
var3 = input("Question 3: ")
```

---

## Project Template (cont.)

```python
# Step 2: Make decisions
if condition_based_on_var1:
    if condition_based_on_var2:
        print("Outcome 1")
    else:
        print("Outcome 2")
else:
    if condition_based_on_var3:
        print("Outcome 3")
    else:
        print("Outcome 4")

print("\n" + "=" * 50)
print("Thanks for using [Your Program Name]!")
```

---

## Common Pattern 1: Age-Based Decisions

```python
age = int(input("Enter age: "))

if age < 13:
    category = "Child"
elif age < 20:
    category = "Teen"
elif age < 65:
    category = "Adult"
else:
    category = "Senior"

print(f"Category: {category}")
```

---

## Common Pattern 2: Range Checking

```python
score = int(input("Enter test score: "))

if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
elif score >= 70:
    grade = "C"
elif score >= 60:
    grade = "D"
else:
    grade = "F"

print(f"Grade: {grade}")
```

---

## Common Pattern 3: Multiple Factors

```python
has_license = input("Have driver's license? (yes/no): ").lower()
age = int(input("Age: "))
has_car = input("Have access to car? (yes/no): ").lower()

can_drive = has_license == "yes" and age >= 16 and has_car == "yes"

if can_drive:
    print("✅ You can drive!")
else:
    print("❌ Cannot drive yet")
```

---

## Common Mistakes

### Mistake 1: Wrong Indentation

```python
# ❌ WRONG - Second if should be indented
if age >= 13:
if has_ticket:  # This should be indented!
    print("Can enter")

# ✅ RIGHT
if age >= 13:
    if has_ticket:  # Properly indented
        print("Can enter")
```

---

## Common Mistakes

### Mistake 2: Using = Instead of ==

```python
# ❌ WRONG - Assignment, not comparison
if answer = "yes":  # Should be ==
    print("Yes!")

# ✅ RIGHT
if answer == "yes":  # Comparison operator
    print("Yes!")
```

---

## Common Mistakes

### Mistake 3: Forgetting .lower()

```python
# ❌ WRONG - Won't work if user types "Yes"
if answer == "yes":
    print("Correct!")
    
# ✅ RIGHT
if answer.lower() == "yes":
    print("Correct!")
```

---

## Common Mistakes

### Mistake 4: Logic Errors

```python
# ❌ WRONG - Will never reach second condition
if age >= 13:
    print("Teen or older")
if age >= 18:  # Should be elif!
    print("Adult")

# ✅ RIGHT
if age >= 18:
    print("Adult")
elif age >= 13:
    print("Teen")
```

---

## Testing Your Decision Tree

**Test every path!** For a tree with 4 outcomes, you need 4 test runs.

**Example Test Plan:**
```
Test 1: Path to Outcome 1
  Input: raining=yes, temp=70
  Expected: "Bring umbrella"
  
Test 2: Path to Outcome 2
  Input: raining=no, temp=40
  Expected: "Wear jacket"
  
Test 3: Path to Outcome 3
  Input: raining=no, temp=75
  Expected: "You're good!"
```

---

## Key Takeaways

1. Decision trees = nested if/elif/else statements in Python
2. Indentation is critical - each nested level needs proper indentation
3. Use .lower() to handle different capitalizations
4. Test every path through your tree
5. Validate input when possible
6. Order matters - put most restrictive conditions first

---

## Vocabulary Review

- **Nested if statement:** An if inside another if
- **Condition:** The test in an if statement (e.g., `age >= 18`)
- **Branch:** Each possible path through the code
- **Input validation:** Checking if user input is valid before using it
- **Logic error:** Code runs but gives wrong results

---

# Questions?

**Next:** Practice building your own decision tree programs!