import sys
sys.stdin = open("matrix_sum.txt")

test_case = int(input())
matrix = []
for _ in range(100):
    matrix.append(list(map(int,input().split())))
max = 0
for i in range(100):
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
