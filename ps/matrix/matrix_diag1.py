import sys
sys.stdin = open("matrix_sum.txt")
for k in range(4):
    test_case = int(input())
    matrix = []
    for _ in range(100):
        matrix.append(list(map(int,input().split())))
    max = 0
    for i in range(100):
        dj=0
        di=0
        tempr = 0
        templ = 0
        check = []
        while 99 + di >= 1 and 99-i+dj <98:
            tempr += matrix[99+ di][99-i+dj]
            templ += matrix[i+di][dj] 
            di -= 1
            dj += 1
        if tempr > max:
            max = tempr
        if templ > max:
            max = templ

    print(max)
