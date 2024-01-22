def create_student_file():
    student_list = [
        {"roll_number": 1601001, "name": "Abc", "department": "Computer"},
        {"roll_number": 1601003, "name": "Xyz", "department": "IT"},
        {"roll_number": 1601004, "name": "Def", "department": "Mech"},
        {"roll_number": 1601005, "name": "Ghi", "department": "CBZ"},
    ]

    student_file = open("student.txt", "w")
    for student in student_list:
        student_file.write(f"{student['roll_number']}\t{student['name']}\t{student['department']}\n")
    student_file.close()

def search_line(line):
    return line.strip().split("\t")

def search_student(roll_number):
    student_file = open("student.txt", "r")
    lines = student_file.readlines()
    student_file.close()

    for line in lines:
        student_info = search_line(line)
        if int(student_info[0]) == roll_number:
            return student_info
    return None

def main():
    create_student_file()
    roll = int(input("Enter the roll number of the student you want to search: "))
    student_info = search_student(roll)

    if student_info:
        print(f"Name: {student_info[1]}, Department: {student_info[2]}")
    else:
        print("Student not found.")

if __name__ == "__main__":
    main()