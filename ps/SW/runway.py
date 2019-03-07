import sys
sys.stdin = open("runway_input.txt")

T = int(input())

def recurse(array, X, before=0):
    count = 0
    if len(array) == count:
        return True
    if not before:
        before = array[0]
    for idx, height in enumerate(array):
        if before == height:
            count += 1
            continue
        elif height == before + 1 and count >= X:
            return recurse(array[idx:], X)
        elif height == before - 1 and array[idx:idx+X] == [array[idx]]*(X):
            return recurse(array[idx+X:], X, height)
        elif height == before -1 and array[idx:] == [array[idx]] *len(array[idx:]) and len(array[idx:]) >= X:
            return True
        else:
            return False
    return True

for tc in range(1, T+1):
    N, X = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]
    count = 0
    for row in grid:
        count += recurse(row, X)
    turn = [[grid[r][c] for r in range(N)] for c in range(N)]
    for row in turn:
        count += recurse(row, X)
    print("#{} {}".format(tc,count))