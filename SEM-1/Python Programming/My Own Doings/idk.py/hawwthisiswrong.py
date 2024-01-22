def cube_numbers():
    while True:
        try:
            number = int(input("Enter a positive integer: "))
            if number < 0:
                raise ValueError("Negative numbers are not allowed.")
            print(f"The cube of {number} is {number**3}.")
        except ValueError as ve:
            print(f"Error: {ve}")
            break

cube_numbers()