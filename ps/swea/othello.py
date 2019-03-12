import sys
sys.stdin = open("othello_input.txt")

up = (-1, 0)
down = (1, 0)
left = (0, -1)
right = (0, 1)
upright = (-1, 1)
downright = (1, 1)
downleft = (1, -1)
upleft = (-1, -1)
directions = [up, down, left, right, upright, downright, downleft, upleft]

T = int(input())
def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))

def getbefore(center, direction):
    return center[0] - direction[0], center[1] - direction[1]

def isvalid(N, center):
    return 0 < center[0] <= N and 0 < center[1] <= N

def magicmethod(N, center, color):
    grid[center[0]][center[1]] = color;
    for direction in directions:
        flag = 0
        next = getnext(center, direction)
        while isvalid(N, next):
            if grid[next[0]][next[1]] == 0:
                break
            elif grid[next[0]][next[1]] == color:
                flag = 1;
                break
            next = getnext(next, direction);

        if flag:
            next = getbefore(next, direction);
            while grid[next[0]][next[1]] != color:
                grid[next[0]][next[1]] = color;
                next= getbefore(next, direction);
        flag = 0;

        

for tc in range(1, T+1):
    N, M = map(int, input().split())
    grid = [[0 for _ in range(N+1)] for _ in range(N+1)]
    n = int(N/2)
    grid[n][n] = 1
    grid[n+1][n+1] = 1
    grid[n+1][n] = 2
    grid[n][n+1] = 2

    for _ in range(M):
        c, r, color = map(int, input().split())
        center = (r, c)
        magicmethod(N, center, color)
    countwhite = 0
    countblack = 0
    for x in range(1, N+1):
        for y in range(1, N+1):
            if grid[x][y] == 1: countblack +=1
            elif grid[x][y] == 2: countwhite += 1
    print(f"#{tc}",countblack, countwhite)
