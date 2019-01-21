import sys
sys.stdin = open("matrix_sum.txt")
for k in range(4):
    test_case = int(input())
    matrix = []
    for _ in range(100):
        matrix.append(list(map(int,input().split())))
    max = 0
    for i in range(100):
        di = 0
        dj = 0
        tempr = 0
        templ = 0
        while 99-i+di<100 and 99+dj>=0 and 99-i+di >=0 and di >= 0 and di <100 and 99+dj >=0 and 99+dj<100:
            templ += matrix[di][99+dj]
            tempr += matrix[99-i+di][99+dj] 
            di += 1
            dj -= 1
        if templ > max:
            max = templ
        if tempr > max:
            max = tempr
    print(max)
