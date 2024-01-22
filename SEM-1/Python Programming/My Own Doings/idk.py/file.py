# Function to cut all digits and replace them with X
def cut_digits_and_replace(text):
    cut_digits = ''
    new_text = ''
    
    for char in text:
        if char.isdigit():
            cut_digits += char
            new_text += 'X'
        else:
            new_text += char
    
    return new_text, cut_digits

# Function to read file and cut all digits
def cut_digits_from_file(file_name):
    with open(file_name, 'r') as file:
        text = file.read()
    
    new_text, cut_digits = cut_digits_and_replace(text)
    
    with open(file_name, 'w') as file:
        file.write(new_text)
    
    return cut_digits

# Main program
def main():
    # Cut all digits from A.txt and replace them with X
    cut_digits = cut_digits_from_file('A.txt')
    
    # Write the cut digits into B.txt
    with open('B.txt', 'w') as file:
        file.write(cut_digits)
    
    # Display both file content after operation
    with open('A.txt', 'r') as file:
        print('A consists of:\n', file.read())
    
    with open('B.txt', 'r') as file:
        print('Is file consists of:\n', file.read())

# Call the main function
if __name__ == '__main__':
    main()