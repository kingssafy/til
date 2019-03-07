import sys
sys.stdin = open("circle_input.txt")


N = int(input())
grid = [list(map(int, input())) for _ in range(N)]
for x in range(N):
    for y in range(N):
        if grid[x][y] == 2:
            start = (x, y)
            break
circumference = 0
for x in range(N):
    for y in range(N):
        value = grid[x][y]
        if value==1:
            d = ((start[0] - x)**2 + (start[1] - y)**2) ** 0.5
            if d > circumference:
                circumference = d
print(int(circumference) + (circumference % int(circumference)>0))