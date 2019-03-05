n = int(input())
K = n*n
turn = [(-1,0), (0,1), (1,0), (0, -1)]
turns = dict(zip(turn, turn[1:] + turn[:1]))
grid = [[0 for _ in range(n)] for _ in range(n)]
direction = (0, 1)
frontier = (0,0)
def isvalid(tuple, r, c):
    a , b = tuple[0], tuple[1]
    return a >= 0 and b >= 0 and a < r and b< c

for k in range(K):
    grid[frontier[0]][frontier[1]] = k+1
    next = tuple(map(sum, zip(frontier, direction)))
    if isvalid(next,n,n):
        if grid[next[0]][next[1]]:
            direction = turns[direction]
            frontier = tuple(map(sum, zip(frontier, direction)))
        else:
            frontier = next
    else: 
        direction = turns[direction]
        frontier = tuple(map(sum, zip(frontier, direction)))

for row in grid:
    print(*row)
