# AI Lesson 02a: Decision Trees - Visual Thinking

## Learning Objectives
- Understand what decision trees are and how they work
- Read and interpret decision tree diagrams
- Create decision trees for real-world problems
- Trace through decision paths manually
- Recognize when decision trees are the right tool

## What's the Point of This Lesson?

While decision trees can be human-developed/coded, there are decision trees that are developed using supervised machine learning/AI techniques.  Humans just provide the labels / inputs and outputs.  These supervised machine learning models are everywhere.

Netflix recommendations, spam filters, fraud detection, medical diagnosis apps, and even self-driving car braking systems all use decision tree AI. They're the foundation of machine learning because they're fast, transparent, and actually work better than fancy neural networks for many real-world problems. Once you understand how decision trees make decisions, you understand the core concept behind ALL AI.

## So although this lesson isn't "AI" yet, we will soon start the process of training AI using data in our upcoming lessons - this is just our first exploration into machine learning!

## What is a Decision Tree?

A **decision tree** is a flowchart-like structure that helps make decisions by asking yes/no questions.

**Real-world example:** How a doctor diagnoses a patient
```
Do you have a fever?
├─ YES → Is your throat sore?
│        ├─ YES → Probably strep throat
│        └─ NO → Probably flu
└─ NO → Are you coughing?
         ├─ YES → Probably common cold
         └─ NO → Do you have a rash?
                  ├─ YES → Probably allergic reaction
                  └─ NO → Probably just tired
```

## Anatomy of a Decision Tree

```
        ┌─────────────┐
        │  Question   │  ← Decision Node (asks a question)
        └──────┬──────┘
               │
        ┌──────┴──────┐
        │             │
    ┌───▼───┐    ┌───▼───┐
    │  YES  │    │  NO   │  ← Branches (possible answers)
    └───┬───┘    └───┬───┘
        │            │
    ┌───▼────┐   ┌──▼─────┐
    │Answer 1│   │Answer 2│  ← Leaf Nodes (final decisions)
    └────────┘   └────────┘
```

**Key Terms:**
- **Root:** The first question at the top
- **Node:** Any question or decision point
- **Branch:** A path you can take (YES or NO)
- **Leaf:** The final answer (no more questions)

## Example 1: Should You Wear a Jacket?

Let's build a decision tree for choosing whether to wear a jacket:

```
              Is it raining?
                   │
         ┌─────────┴─────────┐
         │                   │
        YES                 NO
         │                   │
         │            Is temp < 60°F?
         │                   │
         │         ┌─────────┴─────────┐
         │         │                   │
         │        YES                 NO
         │         │                   │
    Wear jacket    │              No jacket needed
              Wear jacket
```

### Tracing Through the Tree

**Scenario 1:** It's raining and 55°F
1. Is it raining? → **YES** → Wear jacket ✓

**Scenario 2:** Not raining and 45°F
1. Is it raining? → **NO**
2. Is temp < 60°F? → **YES** → Wear jacket ✓

**Scenario 3:** Not raining and 75°F
1. Is it raining? → **NO**
2. Is temp < 60°F? → **NO** → No jacket needed ✓

## Example 2: Movie Rating System

Decide if a movie is appropriate for someone to watch:

```
                 Age >= 13?
                     │
           ┌─────────┴─────────┐
           │                   │
          YES                 NO
           │                   │
    Contains violence?    Contains scary
           │              scenes?
    ┌──────┴──────┐           │
    │             │      ┌────┴────┐
   YES           NO      │         │
    │             │     YES       NO
    │             │      │         │
Age >= 17?    Approved   │     Approved
    │                   Not        
┌───┴───┐            Approved      
│       │                          
YES    NO                          
│       │                          
Approved  Not Approved              
```

### Practice Tracing

**Person 1:** Age 15, Movie has violence but no scary scenes
1. Age >= 13? → YES
2. Contains violence? → YES
3. Age >= 17? → NO → **Not Approved**

**Person 2:** Age 10, Movie has no scary scenes
1. Age >= 13? → NO
2. Contains scary scenes? → NO → **Approved**

## Example 3: Video Game Character AI

Decide what a game character should do:

```
                Player nearby?
                     │
           ┌─────────┴─────────┐
           │                   │
          YES                 NO
           │                   │
    Health < 30%?         Patrol area
           │
    ┌──────┴──────┐
    │             │
   YES           NO
    │             │
Run away    Has weapon?
                 │
          ┌──────┴──────┐
          │             │
         YES           NO
          │             │
       Attack     Find weapon
```

**This is how simple game AI works!**

## Building Your Own Decision Tree

### Step 1: Define the Goal
*What decision are you trying to make?*

Example: "What should I eat for lunch?"

### Step 2: List All Factors
*What information matters?*
- How much time do I have?
- How much money do I have?
- Am I very hungry?

### Step 3: Order Questions by Importance
*Which question matters most?*

1. How much time? (Most important - can't eat if no time!)
2. How much money?
3. How hungry?

### Step 4: Draw the Tree

```
           Have > 30 minutes?
                  │
        ┌─────────┴─────────┐
        │                   │
       YES                 NO
        │                   │
   Have > $10?         Grab snack
        │               from bag
  ┌─────┴─────┐
  │           │
 YES         NO
  │           │
Restaurant  Very hungry?
               │
        ┌──────┴──────┐
        │             │
       YES           NO
        │             │
    Cafeteria    Pack sandwich
                  from home
```

## When Are Decision Trees Useful?

✅ **Good for:**
- Medical diagnosis
- Customer service routing ("Press 1 for..., Press 2 for...")
- Game AI (simple enemies)
- Troubleshooting ("Is it plugged in? Is it turned on?")
- Classification (sorting things into categories)

❌ **Not ideal for:**
- Recognizing faces (too many variations)
- Understanding language (too complex)
- Predicting stock prices (too many unknown factors)

## Decision Trees vs. If/Else

**They're the same thing!** A decision tree is just a visual way to show if/else logic.

**Decision Tree:**
```
    Is it raining?
    ├─ YES → Umbrella
    └─ NO → No umbrella
```

**Python code:**
```python
if is_raining:
    print("Bring umbrella")
else:
    print("No umbrella needed")
```

**Complex Decision Tree:**
```
         Raining?
    ├─ YES → Cold?
    │        ├─ YES → Coat + Umbrella
    │        └─ NO → Just umbrella
    └─ NO → Cold?
             ├─ YES → Just coat
             └─ NO → Nothing
```

**Python code:**
```python
if is_raining:
    if is_cold:
        print("Coat + Umbrella")
    else:
        print("Just umbrella")
else:
    if is_cold:
        print("Just coat")
    else:
        print("Nothing needed")
```

## Real-World Decision Tree Example

**Tech Support Troubleshooting:**

```
              Device won't turn on?
                      │
            ┌─────────┴─────────┐
            │                   │
           YES                 NO
            │                   │
    Is it plugged in?     Device is working
            │             (user confused)
      ┌─────┴─────┐
      │           │
     YES         NO
      │           │
Is battery    Plug it in!
charged?      Problem solved
      │
┌─────┴─────┐
│           │
YES        NO
│           │
Faulty  Charge battery
device  Problem solved
Call repair
```

## Advantages of Decision Trees

1. **Easy to understand** - Anyone can follow a flowchart
2. **Easy to explain** - Show exactly why a decision was made
3. **Fast** - Computer can follow rules instantly
4. **Transparent** - You see every decision point
5. **No "black box"** - Unlike neural networks, you know exactly what's happening

## Limitations of Decision Trees

1. **Can get very large** - Too many branches become unmanageable
2. **Rigid** - Can't adapt to new situations without reprogramming
3. **Oversimplified** - Real world is rarely just yes/no questions
4. **Manual effort** - Someone has to design the entire tree

## Key Points

1. **Decision trees visualize if/else logic** as flowcharts
2. **Nodes ask questions**, branches show answers, leaves give final decisions
3. **Trace through** a tree by answering each question in order
4. **Order matters** - more important questions come first
5. **Decision trees are transparent** - you can see the reasoning
6. **Python if/elif/else** implements decision trees in code

## Vocabulary Check

Make sure you understand these terms:
- **Root node:** First question
- **Decision node:** Any question
- **Branch:** Path from one node to another
- **Leaf node:** Final answer/outcome
- **Depth:** How many questions before reaching an answer