import sys
sys.stdin = open("ball_input.txt")

directions = {
    1: (-1, 0),
    2: (1, 0),
    3: (0, -1),
    4: (0, 1),
}
def isingrid(grid, center):
    R = len(grid)
    C = len(grid[0])
    return 0 <= center[0] < R and 0 <= center[1] < C

def isbar(grid, center, bar=1):
    return grid[center[0]][center[1]] == bar

def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))


def roll(grid, center, direction):
    count = 0
    if isingrid(grid, center) and grid[center[0]][center[1]] == 2:  ## at startpoint
        grid[center[0]][center[1]] = -1
        count +=1
    next = getnext(center, direction)
    before = center
    while True:
        if isingrid(grid, next):
            if not isbar(grid, next):
                if grid[next[0]][next[1]] == 0:
                    grid[next[0]][next[1]] = -1
                    count += 1
                before = next
                next = getnext(next, direction)
                continue
        break
    return count, (before)



def main():
    R, C = map(int, input().split())
    grid = [list(map(int, input())) for _ in range(R)]
    N = int(input())
    array = list(map(int, input().split()))
    for x in range(R):
        for y in range(C):
            if grid[x][y] == 2:
                start = (x, y)
                break
    total = 0
    while array:
        count, now = roll(grid, start, directions[array.pop(0)])
        total += count
        start = now
    print(total)

main()