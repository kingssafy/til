import sys
sys.stdin = open("micron_input.txt")

directions = {
    1: (-1, 0),
    2: (1, 0),
    3: (0, -1),
    4: (0, 1),
}
def backward(num):
    if num ==1:
        return 2
    if num == 2:
        return 1
    if num == 3:
        return 4
    if num == 4:
        return 3

def directiontonum(direction):
    for key, value in directions:
        if value == direction:
            return key
    raise Error

def ingrid(grid, center):
    R = len(grid)
    C = len(grid[0])
    return 0 <= center[0] < R and 0 <= center[1] < C

def iswall(grid, center):
    return not ingrid(grid, center)

def invaccine(grid, center):
    R = len(grid)
    C = len(grid[0])
    return 0 in center or R-1 in center or C-1 in center

def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))

def each(grid, center, virus):
    howmany = virus[0]
    direction = directions[virus[1]]
    next = getnext(center, direction)
    if not ingrid(grid, next):
        virus[0] //= 2
        virus[1] = backward(virus[1])
        if virus[0]:
            return center, virus
        else:
            print("virus gone")
            return None
    if ingrid(grid, next) and invaccine(grid, next):
        virus[0] //= 2
        virus[1] = backward(virus[1])
        if virus[0]:
            return next, virus
        else:
            print("virus gone22")
            return None
    return next, virus
def merge(grid):
    n = len(grid)
    for x in range(n):
        for y in range(n):
            if len(grid[x][y]) >= 2:
                center = (x, y)
                newvirus = []
                summation = 0
                maximum = 0
                afterdirection = -1
                while grid[x][y]:
                    virus = grid[x][y].pop()
                    summation += virus[0]
                    if virus[0] > maximum:
                        maximum = virus[0]
                        afterdirection = virus[1]
                grid[x][y].append([summation, afterdirection])


def main():
    for tc in range(int(input())):
        N, M, K = map(int, input().split())
        grid = [[[] for _ in range(N)] for _ in range(N)]
        for _ in range(K):
            a, b, c, d = map(int, input().split())
            grid[a][b].append([c,d])
        for _ in range(M):
            next = [[[] for _ in range(N)] for _ in range(N)]
            for r in range(N):
                for c in range(N):
                    if grid[r][c]:
                        center = (r,c)
                        while grid[r][c]:
                            virus = grid[r][c].pop(0)
                            co, virus = each(grid, center, virus)
                            next[co[0]][co[1]].append(virus)

            merge(next)
            grid, next = next, grid

        result = 0
        for x in range(N):
            for y in range(N):
                if grid[x][y]:
                    result += grid[x][y][0][0]
        print("#{} {}".format(tc+1,result))


main()