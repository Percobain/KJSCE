#Arithmatic operators
#Addition
x<-10
y<-5
print(x+y)

#Substraction
print(x-y)

#Multplication
print(x*y)

#Division
print(x/y)

#Exponent
print(x^y)

#Modulus
print(x%%y)

#Integer Division
print(x%/%y)



fruits <- c("banana", "apple", "orange", "mango", "lemon")
numbers <- c(13, 3, 5, 7, 20, 2)

sort(fruits)  # Sort a string
sort(numbers) # Sort numbers


x <- c(1, 2, 3, 4, 5)
y <- c(6, 7, 8, 9, 10)

# Concatenate two vectors
z <- c(x, y)
print(z)

ls()

thislist <- list("apple", "banana", "cherry")
for 
for (x in thislist) {
  print(x)
}

rm(list = ls())

ls()


# Create a matrix
thismatrix <- matrix(c(1,2,3,4,5,6), nrow = 3, ncol = 3)

# Print the matrix
thismatrix


thismatrix <- matrix(c("apple", "banana", "cherry", "orange","grape", "pineapple", "pear", "melon", "fig"), nrow = 3, ncol = 3)

newmatrix <- cbind(thismatrix, c("strawberry", "blueberry", "raspberry"))

# Print the new matrix
newmatrix