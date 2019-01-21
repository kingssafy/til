import sys
sys.stdin = open("matrix_sum.txt")
for _ in range(10):
    test_case = int(input())
    matrix = []
    for _ in range(100):
        matrix.append(list(map(int, input().split())))
    max = 0
    for i in range(100):
        if sum(matrix[i]) > max:
            max = sum(matrix[i])

    print(max)
