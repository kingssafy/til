import sys
sys.stdin = open("security_input.txt")

def fee(K):
    return K*K + (K-1)*(K-1)

def ingrid(grid, co):
    R = len(grid)
    C = len(grid[0])
    return 0 <= co[0] < R and 0 <= co[1] < C

def insquare(center, co, k):
    return abs(center[0] - co[0]) + abs(center[1] - co[1]) < k


def availables(grid, center, k):
    result = []
    for x in range(center[0] - (k-1), center[0] + k):
        for y in range(center[1] - (k-1), center[1] +k):
            now = (x, y)
            if ingrid(grid, now) and insquare(center, now, k):
                result.append(now)
    return result

def adder(grid, center, fr, to=0):
    if to:
        return len(availables(grid, center, to)) - len(availables(grid, center, fr))
    else:
        return len(availables(grid, center, fr)) - len(availables(grid, center, k-1))

def profit(grid, center, k, M):
    count = 0
    for available in availables(grid, center, k):
        if grid[available[0]][available[1]]:
            count += 1
    return count * M

def isblack(grid, center, k, M):
    return profit(grid, center, k, M) - fee(k) >= 0

def potential(grid, center, k, M, totalhouse):
    counter = min(len(availables(grid, center, k)), totalhouse)
    pros = counter*M
    minus = fee(k)
    return pros - minus >= 0




for tc in range(int(input())):
    N, M = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]

    totalhouse = sum(sum(row) for row in grid)
    maximum = 0
    for r in range(N):
        for c in range(N):
            center = (r, c)
            k = 1
            while potential(grid, center, k, M, totalhouse):
                prof = profit(grid, center, k, M)
                if prof - fee(k) >= 0:
                    maximum = max(maximum, int(prof/M))
                k +=1

    print("#{} {}".format(tc+1,maximum))
