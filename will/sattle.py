N = int(input())
grid = [list(map(int, input())) for _ in range(N)]

directions = [(1,0), (-1, 0), (0, 1), (0, -1)]
def up(r, c):
    min = 999
    for direction in directions:
        next = tuple(map(sum, zip((r, c), direction)))
        if next[0] >= 0 and next[1] >= 0 and next[0] < N and next[1] < N:
            value = grid[next[0]][next[1]]
            if value <= min:
                min = value
    if grid[r][c] == min+1: 
        result =False
    else: 
        result = True
    grid[r][c] = min+1 
    return result

active = 1
before = 0
while active:
    active=False
    for r in range(1, N-1):
        for c in range(1, N-1):
            if grid[r][c]:
                result = up(r,c)
                if not active and result:
                    active = result
before = max([item for items in grid for item in items])
print(before)


