import sys
sys.stdin = open("5250_input.txt")

T = int(input())
for tc in range(T):
    N = int(input())
    grid = [list(map(int, input().split())) for _ in range(N)]
    results = [[0 for _ in range(N)] for _ in range(N)]
    for y in range(N):
        for x in range(N):
            if y == 0 and x == 0: continue
            elif y == 0:
                results[y][x] = results[y][x-1]+1 + (grid[y][x]-grid[y][x-1]  if grid[y][x] > grid[y][x-1] else 0)
            elif x == 0:
                results[y][x] = results[y-1][x] + 1 +(grid[y][x]-grid[y-1][x] if grid[y][x] > grid[y-1][x] else 0)
            else:
                results[y][x] = min(results[y][x-1]+1 + (grid[y][x]-grid[y][x-1]  if grid[y][x] > grid[y][x-1] else 0), results[y-1][x] + 1 +(grid[y][x]-grid[y-1][x] if grid[y][x] > grid[y-1][x] else 0))
    print(f"#{tc+1} {results[N-1][N-1]}")
