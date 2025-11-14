def display_menu():
    """Display the main menu options."""
    # YOUR CODE HERE
    print("\n--- MENU ---")
    print("1. Add a grade")
    print("2. View grade report")
    print("3. Quit")
    print("Enter your choice (1-3): ", end="")

def add_grade(grades):
    """
    Prompt for a new grade and add it to the list.
    Return the updated list.
    """
    # YOUR CODE HERE
    try:
        grade = float(input("Enter a grade (0-100): "))
        if 0 <= grade <= 100:
            grades.append(grade)
            print(f"Grade {grade} added successfully!")
        else:
            print("Please enter a grade between 0 and 100.")
    except ValueError:
        print("Invalid input. Please enter a numeric value.")
    return grades

def calculate_average(grades):
    """Calculate and return the average of grades."""
    # Hint: Watch for empty list!
    if not grades:
        return 0
    return sum(grades) / len(grades)

def get_letter_grade(average):
    """Convert numeric average to letter grade. Return the letter."""
    if average >= 90:
        return "A"
    elif average >= 80:
        return "B"
    elif average >= 70:
        return "C"
    elif average >= 60:
        return "D"
    else:
        return "F"

def find_highest(grades):
    """Find and return the highest grade."""
    if not grades:
        return None
    return max(grades)
    

def find_lowest(grades):
    """Find and return the lowest grade."""
    if not grades:
        return None
    return min(grades)

def display_report(grades):
    """Display complete grade report with statistics."""
    # YOUR CODE HERE
    if not grades:
        print("\nNo grades to display.")
        return
    
    print("\n--- GRADE REPORT ---")
    print(f"Grades: {grades}")
    average = calculate_average(grades)
    print(f"Average: {average:.2f}")
    print(f"Letter Grade: {get_letter_grade(average)}")
    print(f"Highest: {find_highest(grades)}")
    print(f"Lowest: {find_lowest(grades)}")

# Main program
print("=== STUDENT GRADE CALCULATOR ===")
student_grades = []

while True:
    display_menu()
    choice = input()
    
    if choice == "1":
        student_grades = add_grade(student_grades)
    elif choice == "2":
        display_report(student_grades)
    elif choice == "3":
        print("Goodbye!")
        break
    else:
        print("Invalid choice. Please enter 1, 2, or 3.")

# YOUR CODE HERE - Write the main program loop
# Allow user to add grades, view report, and quit