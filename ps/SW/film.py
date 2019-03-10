import sys
sys.stdin = open("film_input.txt")


def combinations():
    return True


def check(grid, R, C, K):
    result = 1
    for c in range(C):
        count = 1
        before = grid[0][c]
        for r in range(1, R):
            now = grid[r][c]
            if now == before:
                count +=1
            else:
                before = now
                count = 1
            if count == K:
                break
        else:
            result = 0
            break
    return result


def drug(grid, applied, subset):
    temp =[]
    for row, kind in zip(applied, subset):
        temp.append(grid[row])
        grid[row] = [kind] * len(grid[0]) # length of column

    result = check(grid, R, C, K)

    for row in applied:
        grid[row] = temp.pop(0)
    if result:
        return len(applied)
    else:
        return -1

def search(grid, applied, R, C, K, subset):
    global hack
    if len(subset) == len(applied):
        result = drug(grid, applied, subset)
        if result != -1:
            if hack > result:
                hack = result
                return True
    else:
        subset.append(1);
        search(grid, applied, R, C, K, subset);
        subset.pop();
        subset.append(0)
        search(grid, applied, R, C, K, subset);
        subset.pop();
        if hack != 999:
            return True
    return False


def bfs(grid, R, C, K):
    frontier = []
    for i in range(R):
        frontier.append([i])
    while frontier:
        next = []
        for applied in frontier:
            subset = []
            result = search(grid, applied, R, C, K, subset)
            if result:
                return
            for x in range(R):
                if x > max(applied):
                    icopy = applied.copy()
                    icopy.append(x)
                    next.append(icopy)
        frontier = next



for tc in range(int(input())):
    R, C, K = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(R)]
    hack = 999
    if check(grid, R, C, K):
        print("#{} {}".format(tc+1, 0))
    else:
        resulta = bfs(grid, R, C, K)
        print("#{} {}".format(tc+1, hack))
