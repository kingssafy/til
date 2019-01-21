import sys
sys.stdin = open("matrix_sum.txt")
for i in range(10):
    test_case = int(input())
    matrix = []

    for _ in range(100):
        matrix.append(list(map(int, input().split())))
    max = 0
    for i in range(100):
        #colum
        temp = 0
        for j in range(100):
            temp +=  matrix[j][i]
        else:
            if temp > max:
                max = temp

    print(max)

