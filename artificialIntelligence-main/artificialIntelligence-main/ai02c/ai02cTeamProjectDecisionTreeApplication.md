# AI Lesson 02c Team Project: Decision Tree Application

## Overview

Work with a partner to design and code a decision tree program that solves a real-world problem. This project combines your Python skills with AI decision-making concepts.

**Team Size:** 2 students per team

---

## Project Requirements

Your decision tree program must include:

### Technical Requirements
- [ ] At least **3 user inputs** (questions to gather information)
- [ ] At least **2 levels of nested if statements**
- [ ] At least **4 different possible outcomes/recommendations**
- [ ] Use `.lower()` to handle text input variations
- [ ] Include comments explaining your logic
- [ ] Professional output with clear formatting
- [ ] A header with program title and team members' names

### Documentation Requirements
- [ ] A **flowchart or diagram** of your decision tree (hand-drawn or digital)
- [ ] A **test plan** showing at least 4 different test cases
- [ ] Brief explanation (3-4 sentences) of what problem your program solves

---

## Team Roles

**Both team members should contribute to all aspects**, but you **may** divide initial responsibilities:

### Role Option 1: Designer
- Sketch the initial decision tree flowchart
- Design the user experience (questions and output messages)
- Plan test cases
- Help debug code

### Role Option 2: Coder
- Write the initial Python code structure
- Implement the if/elif/else logic
- Add input validation
- Help refine flowchart



---

## Project Options

Choose ONE of the following projects (or propose your own with teacher approval):

### Option 1: College Major Advisor 
Help students decide what to study based on their interests and skills.

**Factors to consider:**
- Favorite subjects (math/science/arts/humanities)
- Career goals (help people/make things/solve problems/create art)
- Preferred work environment (office/outdoors/lab/remote)

**Sample outcomes:** Engineering, Business, Education, Nursing, Computer Science, Graphic Design, etc.

---

### Option 2: Video Game Recommender 
Recommend games based on player preferences.

**Factors to consider:**
- Gaming platform (PC/Console/Mobile)
- Preferred genre (Action/RPG/Sports/Strategy/Puzzle)
- Time commitment (casual/regular/hardcore)
- Single-player or multiplayer

**Sample outcomes:** Specific game recommendations with reasons why

---

### Option 3: Workout Plan Generator 
Create personalized workout recommendations.

**Factors to consider:**
- Fitness goal (lose weight/build muscle/increase endurance/flexibility)
- Experience level (beginner/intermediate/advanced)
- Time available (15min/30min/60min)
- Equipment available (none/basic/full gym)

**Sample outcomes:** Specific workout plans with exercises listed

---

### Option 4: Study Strategy Advisor 
Help students develop effective study plans.

**Factors to consider:**
- Subject difficulty (easy/medium/hard)
- Time until test (tonight/few days/week+)
- Study style (visual/auditory/hands-on)
- Current grade (struggling/average/excelling)

**Sample outcomes:** Customized study plans with specific strategies

---

### Option 5: Career Path Explorer 
Guide students toward potential careers.

**Factors to consider:**
- Interests (technology/healthcare/education/business/creative)
- Strengths (math/communication/problem-solving/creativity)
- Work-life balance preference (high/moderate/flexible)
- Education plans (college/trade school/straight to work)

**Sample outcomes:** Career suggestions with brief descriptions

---

### Option 6: Recipe Suggester 
Recommend recipes based on available ingredients and preferences.

**Factors to consider:**
- Main ingredient available (chicken/beef/vegetarian/pasta)
- Cooking time (under 15min/30min/60min+)
- Skill level (beginner/intermediate/advanced)
- Meal type (breakfast/lunch/dinner/snack)

**Sample outcomes:** Specific recipes with brief descriptions

---

### Option 7: Pet Adoption Matcher 
Match people with appropriate pets.

**Factors to consider:**
- Living situation (apartment/house with yard)
- Activity level (low/moderate/very active)
- Time available (limited/moderate/lots)
- Experience with pets (none/some/experienced)

**Sample outcomes:** Pet recommendations (specific breeds/types) with care requirements

---

### Option 8: Weekend Activity Planner 
Suggest activities based on conditions and preferences.

**Factors to consider:**
- Weather (sunny/rainy/cold/hot)
- Budget (free/under $20/under $50/no limit)
- Group size (alone/couple/small group/large group)
- Energy level (low/medium/high)

**Sample outcomes:** Specific activity recommendations

---

### Option 9: Phone/Laptop Purchase Advisor 
Help people decide which device to buy.

**Factors to consider:**
- Budget (under $500/$500-$1000/over $1000)
- Primary use (gaming/work/social media/creative)
- Brand preference (Apple/Android/Windows/no preference)
- Priority (performance/battery/camera/storage)

**Sample outcomes:** Specific device recommendations

---

### Option 10: Your Own Idea! 
**Get teacher approval first!**

Your idea must:
- Solve a real problem
- Have at least 3 factors to consider
- Lead to at least 4 different outcomes
- Be school-appropriate

---

## Code Template

```python
"""
Decision Tree Program: [YOUR TITLE]
Team Members: [Name 1] and [Name 2]
Date: [Date]
Description: [Brief description of what this program does]
"""

print("=" * 60)
print("[YOUR PROGRAM TITLE]")
print("=" * 60)
print()

# Gather information (at least 3 inputs)
input1 = input("Question 1: ").lower()
input2 = input("Question 2: ").lower()
input3 = input("Question 3: ")

print()  # Blank line for formatting
print("-" * 60)
print("RECOMMENDATION:")
print("-" * 60)

# Decision tree logic (at least 2 levels of nesting, 4 outcomes)
if condition1:
    if condition2:
        # Outcome 1
        print("Recommendation: [Outcome 1]")
        print("Reason: [Why this recommendation]")
    else:
        if condition3:
            # Outcome 2
            print("Recommendation: [Outcome 2]")
            print("Reason: [Why this recommendation]")
        else:
            # Outcome 3
            print("Recommendation: [Outcome 3]")
            print("Reason: [Why this recommendation]")
else:
    if condition2:
        # Outcome 4
        print("Recommendation: [Outcome 4]")
        print("Reason: [Why this recommendation]")
    else:
        # You can add more outcomes here
        print("Recommendation: [Another outcome]")
        print("Reason: [Why this recommendation]")

print()
print("=" * 60)
print("Thank you for using [Your Program Name]!")
print("=" * 60)
```

---

## **Testing Requirement:**  
Before submitting, run your program multiple times using different inputs.  
Make sure you test every branch of your decision tree -- all possible outcomes.


---

## Flowchart Requirements

- Create the flowchart in PowerPoint

- Here is an example of a decision tree in flowchart format: https://creately.com/diagram/example/j20af6gl7/decision-flowchart-template


### Flowchart Shape Guide

| Shape          | Meaning                               | Common Use                             |
|----------------|---------------------------------------|----------------------------------------|
| Oval / Terminator | Start / End of process                | “Start”, “End” nodes                   |
| Rectangle       | Process or action step                | “Do this”, “Compute value”, etc.       |
| Diamond         | Decision or branching point           | “Is this true?”, “Y/N” forks           |
| Parallelogram   | Input / Output (data in/out)          | “Enter number”, “Display result”       |
| Arrow           | Flow line                              | Shows direction of the process         |

**Tip:** Always label arrows (e.g., “YES”, “NO”) and keep branches neat and parallel.

---

### How to use in your flowchart  
1. Use an **oval** to mark the starting point (e.g., “Start”).  
2. Use a **rectangle** for each action or step.  
3. Use a **diamond** when a question or decision must be made (Yes or No part).  
4. Use a **parallelogram** when data is entered or results are shown such as an input in the program, like "enter age".  
5. Connect all shapes with **arrows**, and label arrow-paths clearly (YES/NO or with values).

**Keep it clean:** Top to bottom or left to right, avoid crossing lines, and ensure each branch ends in a rectangle (outcome/action).  


---

## Submission Checklist

Each team member must submit the same files in their individual GitHub repositories with:

1. **Python file (.py)** with:
   - Header comment with team members and description
   - Working code meeting all requirements
   - Comments explaining key decisions/points/whatever you think is helpful to clarify things in your code

2.  Flowchart in PowerPoint
    - Submit the flowchart along with your program in an `ai02` folder in `artificialIntelligence` repository on your GitHub. 

**Demo**: Be prepared to demonstrate your program in class

---

## Grading Rubric

| Category            | Points | Criteria |
|---------------------|--------|----------|
| Code Functionality  | **10**  | Program runs without errors; meets all requirements |
| Decision Tree Logic | **6**  | Proper nesting (2+ levels), 4+ outcomes, logical flow |
| Code Quality        | **4**  | Clean code, comments, indentation, good variable names |
| User Experience     | **3**  | Clear questions, helpful output, good formatting |
| Flowchart           | **2**  | Accurate diagram showing all decision paths |

**TOTAL = 25 points**

---

## Tips for Success

### Planning Phase
1. **Choose your project** together
2. **Brainstorm factors** - what information do you need to ask?
3. **Sketch the flowchart** on paper first
4. **List all possible outcomes** - aim for 4-6
5. **Decide on roles** for initial work

### Coding Phase
1. **Start with the template** above
2. **Write one branch at a time** - test as you go
3. **Add formatting** (lines, emojis, spacing) to make output clear
4. **Test frequently** - don't wait until the end!
5. **Use comments** to explain complex logic
6. **Ask questions** if you get stuck

### Testing Phase
2. **Try to break your program** - test extreme values
3. **Make sure all 4+ outcomes are reachable**
4. **Fix any bugs** you discover
5. **Clean up formatting** and add final touches

### Documentation Phase 
1. **Create final flowchart** in PowerPoint using appropriate shapes.  

    - Oval = Start / End
    - Diamond = Decision / Question (branches with “Yes” and “No”)
    - Rectangle = Action / Outcome (what happens after Yes/No)
    - Arrows = Flow direction (Yes → one path, No → the other)

---

## Pitfalls to Avoid

❌ **Mistake:** One person does all the work
✅ **Solution:** Divide initial tasks, then review together

❌ **Mistake:** Decision tree is too shallow (not enough if statements)
✅ **Solution:** Add nested conditions for more sophisticated decisions

❌ **Mistake:** Forgot to use .lower() on text input
✅ **Solution:** Add .lower() to all text comparisons

❌ **Mistake:** Not testing all paths
✅ **Solution:** Create test plan BEFORE coding, ensure every outcome is tested

❌ **Mistake:** Poor formatting makes output hard to read
✅ **Solution:** Use blank lines, clear labels, and comments if helpful

---
