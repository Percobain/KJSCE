import numpy as np

def get_max_marks(scores):
    return np.max(scores, axis=0)

def sort_students(scores):
    sorted_scores = np.sort(scores, axis=0)
    return sorted_scores[:, 0]

def read_marks(n):
    scorecard = []
    for i in range(n):
        name = input(f"Enter name of student {i+1}: ")
        marks = list(map(int, input(f"Enter marks of student {i+1}: ").split()))
        scorecard.append([name] + marks)
    return np.array(scorecard)

n = int(input("Enter the number of students: "))
scorecard = read_marks(n)

# print scorecard
print("Scorecard Table: ")
print(scorecard)

# calculate shape
shape = scorecard.shape
print(f"Shape of scorecard table: {shape}")

# calculate maximum marks in each question
max_marks = get_max_marks(scorecard[:, 1:])
print(f"Maximum marks in each question: {max_marks}")

# sort students
sorted_names = sort_students(scorecard)
print(f"Sorted Student Names: {sorted_names}")