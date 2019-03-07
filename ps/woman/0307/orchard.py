import sys
sys.stdin = open("orchard_input.txt.py")


N = int(input())

def slicearray(array, r, c, x, y):
    result = 0
    for q in range(r, x):
        for r in range(c, y):
            result += array[q][r]
    return result

grid = [list(map(int, input())) for _ in range(N)]
if N > 1:
    count = 0
    for x in range(1, N):
        for y in range(1, N):
            a = slicearray(grid, 0,0,x,y)
            b = slicearray(grid, 0,y, x, N)
            c = slicearray(grid, x,0, N, y)
            d = slicearray(grid, x,y, N, N)
            if a == b == c == d:
                count += 1
    if count:
        print(count)
    else:
        print(-1)