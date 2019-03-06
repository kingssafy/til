import sys
sys.stdin = open("river_input.txt")

def isingrid(grid, co):
    R = len(grid)
    C = len(grid[0])
    return 0 <= co[0] < R and 0 <= co[1] < C

def getnext(co, direction):
    return tuple(map(sum, zip(co, direction)))
def howfar(grid, co, direction):

    next = getnext(co, direction)
    count = 1
    if isingrid(grid, next):
        while grid[next[0]][next[1]] == 1:
            count += 1
            next = getnext(next, direction)
    return count

def depth(grid, co):
    directions = [(1,0), (-1, 0), (0,-1), (0,1)]
    results = []
    for direction in directions:
        results.append(howfar(grid, co, direction))
    return min(results)

def main():
    N = int(input())
    grid = [list(map(int, input().split())) for _ in range(N)]
    count = 0
    for r in range(N):
        for c in range(N):
            if grid[r][c]:
                count += depth(grid, (r,c))
    print(count)

main()