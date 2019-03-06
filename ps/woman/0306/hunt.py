import sys
sys.stdin = open("hunt_input.txt")



directions = [(-1,0), #up
             (1, 0), #down
             (0, -1), #left
             (0, 1), #right
             (1, 1), #down and right
             (1, -1), #down and left
             (-1, -1), #up and left
             (-1, 1), #up and right
             ]
def ingrid(grid, center):
    R = len(grid)
    C = len(grid[0])
    return 0 <= center[0] < R and 0 <= center[1] < C

def isrock(grid, center):
    if ingrid(grid, center):
        return grid[center[0]][center[1]] == 0
    else:
        print("isrock error")

def israbbit(grid, center, rabbit=2):
    if ingrid(grid, center):
        return grid[center[0]][center[1]] == rabbit
    else:
        print("israbbit error")
        return False

def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))


def getrabbit(grid, center, direction, rabbit=2, after=-1):
    next = getnext(center, direction)
    count = 0
    while ingrid(grid, next) and not isrock(grid, center):
        if israbbit(grid, next):
            grid[next[0]][next[1]] = -1
            next = getnext(next, direction)
            count += 1
            continue
        if grid[next[0]][next[1]] == -1: #if dead
            next = getnext(next, direction)
            continue
        if grid[next[0]][next[1]] == 1 : #hunter
            break
        if grid[next[0]][next[1]] == 0:
            break
    return count

def letshunt(grid, center, directions):
    count = 0
    for direction in directions:
        count += getrabbit(grid, center, direction)
    return count



def main():
    N = int(input())
    grid = [list(map(int, input())) for _ in range(N)]
    result = 0
    for x in range(N):
        for y in range(N):
            if grid[x][y] == 1:
                center = (x, y)
                result += letshunt(grid, center, directions)
    print(result)

main()