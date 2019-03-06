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

def ingrid(grid, center, N):
    R = N-1
    C = N-1
    return 0 <= center[0] < R and 0 <= center[1] < C

def iswall(grid, center, N):
    return not ingrid(grid, center, N)

def invaccine(grid, center, N):
    R = N
    C = N
    return 0 in center or R-1 in center or C-1 in center

def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))

def each(grid, center, virus, N):
    howmany = virus[0]
    direction = directions[virus[1]]
    next = getnext(center, direction)
    if not ingrid(grid, next, N):
        virus[0] //= 2
        virus[1] = backward(virus[1])
        if virus[0]:
            return center, virus
        else:
            return None
    if ingrid(grid, next, N) and invaccine(grid, next, N):
        virus[0] //= 2
        virus[1] = backward(virus[1])
        if virus[0]:
            return next, virus
        else:
            return None
    return next, virus

def merge(grid):
    n = len(grid)
    for x in range(n):
        for y in range(n):
            center = (x, y)
            if center in grid and len(grid[center]) >= 2:
                summation = 0
                maximum = 0
                afterdirection = -1
                for virus in grid[center]:
                    summation += virus[0]
                    if virus[0] > maximum:
                        maximum = virus[0]
                        afterdirection = virus[1]
                grid[center] = [[summation, afterdirection]]


def main():
    for tc in range(int(input())):
        N, M, K = map(int, input().split())
        grid = {}
        for _ in range(K):
            a, b, c, d = map(int, input().split())
            center = (a, b)
            if center in grid:
                grid[center].append([c,d])
            else:
                grid[center] = [[c,d]]
        for _ in range(M):
            next = {}
            for r in range(N):
                for c in range(N):
                    center = (r,c)
                    if center in grid and grid[center]:
                        for virus in grid[center]:
                            value = each(grid, center, virus, N)
                            if value:
                                co, virus = value[0], value[1]
                                if co in next:
                                    next[co].append(virus)
                                else:
                                    next[co] = [virus]
            merge(next)
            grid = next
        merge(grid)
        result = 0
        for x in range(N):
            for y in range(N):
                center = (x, y)
                if center in grid and grid[center]:
                    result += grid[center][0][0]
        print("#{} {}".format(tc+1,result))


main()