import sys
sys.stdin = open("maze_input.txt")

directions = {
    1: (1, 0),
    2: (0, -1),
    3: (-1, 0),
    4: (0, 1),
}
def ingrid(grid, center):
    R = len(grid)
    C = len(grid[0])
    return 0 <= center[0] < R and 0 <= center[1] < C

def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))

def iswall(grid, center, wall=1):
    if ingrid(grid, center):
        return grid[center[0]][center[1]] == wall
    else:
        print("center not ingrid")
        return None

def isme(grid, center, me=2):
    if ingrid(grid, center):
        return grid[center[0]][center[1]] == me
    else:
        print("is me error")
        return None

def main():
    N = int(input())
    grid = [list(map(int, input())) for _ in range(N)]
    a, b, c, d = map(int, input().split())
    sequence = [a, b, c, d]
    turn = {directions[key]: directions[value] for key, value in zip(sequence, sequence[1:] + sequence[:1])}
    start = (0, 0)
    direction = directions[a]
    counter = 0
    while True:
        next = getnext(start, direction)
        if not ingrid(grid, next) or iswall(grid, next):
            direction = turn[direction]
            continue
        if ingrid(grid, next) and isme(grid, next):
            break
        if ingrid(grid, next) and grid[next[0]][next[1]] == 0:
            grid[next[0]][next[1]] = 2
            counter += 1
            start = next
    print(counter)

main()