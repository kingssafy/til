import sys
sys.stdin = open("grid.txt")

R, C = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(R)]
for r in range(R):
    for c in range(C):
        if c >= 1 and grid[r][c-1] and grid[r][c]:
            grid[r][c] = grid[r][c-1]+1

for line in grid:
    print(*line)
