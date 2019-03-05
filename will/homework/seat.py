R, C = map(int, input().split())
K = int(input())

turn = [(-1,0), (0,1), (1,0), (0, -1)]
turns = dict(zip(turn, turn[1:] + turn[:1]))
grid = [[0 for _ in range(C)] for _ in range(R)]
direction = (0, 1)
frontier = (0,0)
def isvalid(tuple, r, c):
    a , b = tuple[0], tuple[1]
    return a >= 0 and b >= 0 and a < r and b< c

for k in range(K):
    if k == K-1 : break
    grid[frontier[0]][frontier[1]] = 1
    next = tuple(map(sum, zip(frontier, direction)))
    if isvalid(next,R,C):
        if grid[next[0]][next[1]]:
            direction = turns[direction]
            frontier = tuple(map(sum, zip(frontier, direction)))
        else:
            frontier = next
    else: 
        direction = turns[direction]
        frontier = tuple(map(sum, zip(frontier, direction)))
r=1
if K == R*C:
    next = tuple(map(sum, zip(frontier, turns[turns[direction]])))
    r=0
if K > R*C:
    print(0)
elif K ==1:
    print(1,1)
else:
    print(next[0]+r, next[1]+r)
