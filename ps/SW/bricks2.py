import sys
import copy
sys.stdin = open("bricks_input.txt")

up = (-1, 0)
down = (1, 0)
left = (0, -1)
right = (0, 1)
directions = [up, right, down, left]

def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))

def tupmul(tuple, times):
    return (tuple[0]*times, tuple[1]*times)

def ingrid(center, grid):
    return 0<= center[0]< len(grid) and 0<= center[1] < len(grid[0])

def hammer(grid, center):
    frontier = [center]
    while frontier:
        next_frontier = []
        for center in frontier:
            temp = grid[center[0]][center[1]]
            grid[center[0]][center[1]] = 0
            for j in range(1, temp):
                for direction in directions:
                    next = getnext(center, tupmul(direction,j))
                    if ingrid(next, grid) and grid[next[0]][next[1]]:
                        next_frontier.append(next)

        frontier = next_frontier

def cleanup(grid):
    for c in range(W):
        for r in range(H-1,-1,-1):
            if not grid[r][c]:
                for j in range(r, -1, -1):
                    if grid[j][c]:
                        grid[r][c], grid[j][c] = grid[j][c], grid[r][c]
                        break

def calculate(grid):
    result = 0
    for r in range(H):
        for c in range(W):
            if grid[r][c]:
                result += 1
    return result

def getstartpoint(grid, w):
    center = (H-1, w)
    for idx in range(H-1,-1,-1):
        if not grid[idx][w]:
            break
    result = (idx+1, w)
    if ingrid(result, grid):
        return result
    else:
        return (idx, w)


def recurse(grid, depth=0):
    global result
    if depth ==N-1:
        temp = calculate(grid)
        if temp < result:
            result = temp
    else:
        newgrid = [[0 for _ in range(W)] for _ in range(H)] 
        for x  in range(H):
            for y in range(W):
                newgrid[x][y] = grid[x][y]            
        for w in range(W):
            hammer(newgrid, getstartpoint(newgrid, w))
            cleanup(newgrid)
            recurse(newgrid, depth+1)
            
            


T = int(input())
for tc in range(1):
    N, W, H = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(H)]
    result = 9999
    recurse(grid)
    print(result)
