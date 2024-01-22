#1. Write a program to read the contents of the file 'messages' one character at a time. Print each character that is read.

# f = open("demofile.txt", "r")

# while f:
#     char = f.read(4)
#     if not char:
#          break
#     print(char)
    
# f.close()


#2. Write a program to read a file and display its contents along with line numbers before each line.

# L = ["Geeks\n", "for\n", "Geeks\n"]
 
# # writing to file
# file1 = open('demofile.txt', 'w')
# file1.writelines(L)
# file1.close()
 
# # Using readlines()
# file1 = open('demofile.txt', 'r')
# Lines = file1.readlines()
 
# count = 0
# # Strips the newline character
# for _ in Lines:
#     count += 1
#     print("Line{}: {}".format(count, _.strip()))

#3. Write a program to append the contents of one file at the end of another.

# Function to append contents
# def append_file(file_path_1, file_path_2):
#     with open(file_path_1, 'a') as file1:
#         with open(file_path_2, 'r') as file2:
#             file1.write(file2.read())

# # Provide the file paths to append
# file_path_1 = "file1.txt"
# file_path_2 = "file2.txt"

# # Call the function to append
# append_file(file_path_1, file_path_2)
# print(file_path_2)