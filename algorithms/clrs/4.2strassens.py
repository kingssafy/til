#SQUARE-MATRIX-MULTIPLY
def square_matrix_multiply(A,B):
    len_row = len(A)
    len_col = len(A[0])

    C = [[0 for _ in range(len(A))] for _ in range(len(B[0]))]
    for i in range(len_row):
        for j in range(len(B[0])):
            for k in range(len_col):
                C[i][j] += A[i][k] * B[k][j]

    return C

A = [[1,2,3], [5,6,7]]
B = [[1,1],[2,2],[3,3]]

print(square_matrix_multiply(A,B))
