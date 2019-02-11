import sys
sys.stdin = open("input.txt")

for _ in range(10):
    int(input())
    ladder = [list(map(int, input().split())) for _ in range(100)]
    x, y = 99, ladder[99].index(2) 
    while x > 0:
        if y+1 < 100 and ladder[x][y+1]:
            ladder[x][y] = 0
            y += 1
            continue
        if y-1 > -1 and ladder[x][y-1]:
            ladder[x][y] = 0
            y -= 1
            continue
        else:
            x -= 1
    print(f"#{_+1} {y}")
