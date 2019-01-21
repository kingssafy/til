import sys
sys.stdin = open("matrix_sum.txt")

test_case = int(input())
matrix = []

for _ in range(100):
    matrix.append(list(map(int, input().split())))
max = 0
for i in range(100):
    # row
    if sum(matrix[i]) > max :
        max = sum(matrix[i])
    
    #colum
    temp = 0
    for j in range(10):
        temp +=  matrix[j][i]
    else:
        if temp > max:
            max = temp
    #diagnal \
    temp_rtl = 0
    temp_ltr = 0
    x = int(i)
    y = 0
    while x >= 0 and y >= 0 and x < 10 and y < 10:
        temp_rtl += matrix[y][len(matrix[y]) -1 - x]
        temp_ltr += matrix[len(matrix[y])-1 -x][y]
        x += 1
        y += 1
    else:
        if temp_rtl > max:
            max = temp_rtl
        if temp_ltr > max:
            max = temp_ltr
    
    #dignal /
    temp_rtl = 0
    temp_ltr = 0
    x = int(i)
    y = 0
    while x >= 0 and y >= 0 and x < 10 and y < 10:
        temp_ltr += matrix[x][y]
        temp_rtl += matrix[9-x][9-x]

        x -= 1
        y += 1
    else:
        if temp_rtl > max:
            max = temp_rtl
        if temp_ltr > max:
            max = temp_ltr
print(max)       
