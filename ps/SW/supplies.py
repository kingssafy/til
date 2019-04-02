import sys
sys.stdin = open("supplies_input.txt");

from heapq import heappush, heappop;
dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]

def djik():
    Q = []
    heappush(Q, (0,0,0))
    d[0][0] = 0
    while Q:
        b, y, x = heappop(Q);
        if p[y][x]: continue;
        if y == N-1 and x == N-1: return d[N-1][N-1]
        p[y][x] = 1
        for i in range(4):
            ny = y+dy[i]
            nx = x+dx[i]
            if (min(ny, nx) < 0 or max(ny, nx) >= N): continue
            if (d[ny][nx] > d[y][x]+grid[ny][nx]):
                d[ny][nx] = d[y][x]+grid[ny][nx]
                heappush(Q, (d[ny][nx], ny, nx))
    return -1
        


T = int(input())
for tc in range(T):
    N = int(input()) 
    grid = [list(map(int, input())) for _ in range(N)]
    d = [[99999 for _ in range(N)] for _ in range(N)] 
    p = [[ 0 for _ in range(N) ] for _ in range(N)]
    print(f"#{tc+1} {djik()}")
