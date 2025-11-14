import random

def display_welcome():
    """Display a welcome banner for the Magic 8-Ball."""
    print("============================")
    print("Welcome to the Magic 8-Ball!")
    print("============================")
    pass

def get_question():
    """Get a question from the user. Return the question."""
    return input("Ask the Magic 8-Ball a question: ")

def get_fortune():
    """Return a random fortune from a list of possible answers."""
    answers = [
        "It is certain.",
        "Ask again later.",
        "Don't count on it.",
        "Yes, definitely.",
        "My sources say no.",
        "Outlook good.",
        "Very doubtful.",
        "Yes, in due time.",
        "Cannot predict now.",
        "Absolutely!"
    ]
    return random.choice(answers)

def display_fortune(answers):
    """Display the fortune in a fancy way."""
    print("\nThe Magic 8-Ball says:")
    print("----------------------------")  
    print(answers)
    print("----------------------------\n")

def play_again():
    """Ask user if they want to ask another question. Return True or False."""
    print("Do you want to ask another question? (yes/no)")
    response = input().strip().lower()
    return response == "yes"

# Main program
display_welcome()
question_count = 0
while True:
    get_question()
    fortune = get_fortune()
    display_fortune(fortune)
    if not play_again():
        break