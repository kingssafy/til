import sys
sys.stdin = open("matrix_sum.txt")

test_case = int(input())
matrix = []
for _ in range(100):
    matrix.append(list(map(int, input().split())))
max = 0
for i in range(100):
    if sum(matrix[i]) > max:
        max = sum(matrix[i])

    #colum
    temp = 0
    for j in range(100):
        temp +=  matrix[j][i]
    else:
        if temp > max:
            max = temp

    dj=0
    di=0
    tempr = 0
    templ = 0
    while 99+di >= 0 and 99-i+dj<100: 
        tempr += matrix[99+ di][99-i+dj]
        templ += matrix[i+di][dj] 
        di -= 1
        dj += 1
    if tempr > max:
        max = tempr
    if templ > max:
        max = templ

    di, dj, templ, tempr = 0, 0, 0, 0
    while di < 100 and i+di < 100:
        templ += matrix[di][i+dj]
        tempr += matrix[i+di][dj]
        di += 1
        dj += 1
    if templ > max:
        max = templ
    if tempr > max:
        max = tempr
print(max)
