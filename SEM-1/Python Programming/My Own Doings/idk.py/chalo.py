# x = int(input("Enter a number: "))
# y = int(input("Enter a number: "))
# try:
#     print(x/y)
# except ZeroDivisionError:
#     print("Cannot Divide by Zero")
    
# print("end")

import random

def generate_quiz(questions, answers):
    question_number = 1
    correct_answers = 0
    for question, options, correct_option in zip(questions, answers, correct_option):
        print("\nQuestion {}: {}".format(question_number, question))
        for i, option in enumerate(options):
            print("{}) {}".format(i+1, option))
        user_input = int(input("Choose the correct answer (1-4): ")) - 1
        correct_answer = options[correct_option]
        if user_input == correct_option:
            print("Correct! The correct answer is: {}".format(correct_answer))
            correct_answers += 1
        else:
            print("Incorrect. The correct answer is: {}".format(correct_answer))
        question_number += 1
    print("\nQuiz complete! You got {} out of {} questions correct.".format(correct_answers, len(questions)))

def main():
    with open("Questions.txt", "r") as file:
        questions = file.readlines()
    with open("Answers.txt", "r") as file:
        answers = file.readlines()

    # Strip newline characters from the end of each line
    questions = [question.strip() for question in questions]
    answers = [answer.strip() for answer in answers]

    # Generate random indices for each question
    indices = list(range(len(questions)))
    random.shuffle(indices)

    # Randomly assign options to each question and correct answers
    options = [list("ABCD") for _ in questions]
    correct_options = [random.randint(0, 3) for _ in questions]

    # Combine all data into one list of tuples
    quiz_data = list(zip(questions, options, correct_options))

    # Extract the data corresponding to the random indices
    quiz_data = [quiz_data[i] for i in indices]

    generate_quiz(quiz_data, answers)

if __name__ == "__main__":
    main()