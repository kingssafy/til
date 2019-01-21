import sys
sys.stdin = open("matrix_sum.txt")
for _ in range(10):
    test_case = int(input())
    matrix = []
    for _ in range(100):
        matrix.append(list(map(int, input().split())))
    max = 0
    temp1, temp2 = 0, 0
    for i in range(100):
        if sum(matrix[i]) > max:
            max = sum(matrix[i])
        temp = 0
        for j in range(100):
            temp +=  matrix[j][i]
        else:
            if temp > max:
                max = temp
        
        temp1 += matrix[i][i]
        temp2 += matrix[i][99-i]
    if temp1 > max:
        max = temp1
    if temp2 > max:
        max = temp2
    print(f"#{test_case} {max}")
