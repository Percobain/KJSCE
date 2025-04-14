a <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 3, ncol = 2, byrow = TRUE)
print(a)


# Row Operations

# Create augmented matrix by combining matrices using cbind
augmented <- cbind(matrix(c(1,2), nrow = 2), matrix(c(3,4), nrow = 2), matrix(c(5,6), nrow = 2)) # nolint
print(augmented)

augmented[1, ] <- augmented[1, ] / augmented[1, 1]
augmented[2, ] <- augmented[2, ] * augmented[2, 1]
augmented[2, ] <- augmented[2, ] / augmented[2, 2]
augmented[1, ] <- augmented[1, ] * augmented[1, 2]

sol <- augmented[, 3]
print(sol)

