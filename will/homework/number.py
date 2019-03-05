import sys
sys.stdin = open("number_input.txt")
n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

for c in range(3):
    only = []
    double = []
    for r in range(n):
        if grid[r][c] in only:
            if grid[r][c] not in double:
                double.append(grid[r][c])
        else:
            only.append(grid[r][c])
    result = [item for item in only if item not in double ]
    for r in range(n):
        if grid[r][c] not in result:
            grid[r][c] = 0
for player in grid:
    print(sum(player))
