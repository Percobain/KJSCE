import numpy as np

def split_matrix(matrix):
    """Split a given matrix into 4 equal submatrices."""
    row, col = matrix.shape
    row2, col2 = row // 2, col // 2
    return matrix[:row2, :col2], matrix[:row2, col2:], matrix[row2:, :col2], matrix[row2:, col2:]

def strassen(A, B):
    """Perform matrix multiplication using Strassen's algorithm."""
    if A.shape[0] == 1:
        return A * B  # Base case: when the matrix is 1x1
    
    A11, A12, A21, A22 = split_matrix(A)
    B11, B12, B21, B22 = split_matrix(B)
    
    # Compute the 7 Strassen products
    M1 = strassen(A11 + A22, B11 + B22)
    M2 = strassen(A21 + A22, B11)
    M3 = strassen(A11, B12 - B22)
    M4 = strassen(A22, B21 - B11)
    M5 = strassen(A11 + A12, B22)
    M6 = strassen(A21 - A11, B11 + B12)
    M7 = strassen(A12 - A22, B21 + B22)
    
    # Compute the final quadrants of the result matrix
    C11 = M1 + M4 - M5 + M7
    C12 = M3 + M5
    C21 = M2 + M4
    C22 = M1 - M2 + M3 + M6
    
    # Combine submatrices into a single result matrix
    C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22))))
    return C

# Example usage
if _name_ == "_main_":
    A = np.array([[1, 2], [3, 4]])
    B = np.array([[5, 6], [7, 8]])
    result = strassen(A, B)
    print("Result of Strassen's Matrix Multiplication:")
    print(result)