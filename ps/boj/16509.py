Y = 10
X = 9
visit = [[False for _ in range(X)] for _ in range(Y)]
    #up right down left
dy = [-1, -1, -1, 0, -1, 1, 1, 1, 1,  0, 1,  -1]
dx = [0,  -1,  1, 1,  1, 1,  0, 1,  -1, -1, -1, -1]


sy, sx = map(int, input().split())
ey, ex = map(int, input().split())
blocked = [];
king = [(ey, ex)]
def bfs():
    frontier = [];
    frontier.append((sy, sx, 0))
    while frontier:
        next = []
        for y, x, d in frontier:
            if y == ey and x == ex:
                print(d)
                return;
            for i in range(0, 10, 3):
                my = y + dy[i];
                mx = x + dx[i];
                if  (my, mx) not in blocked and min(my, mx) >= 0 and my < Y and mx < X  and (my, mx) not in king:
                    for j in range(1, 3):
                        for k in range(1, 3):
                            ny = my+dy[i+j]*k
                            nx = mx+dx[i+j]*k
                            if (ny, nx) in blocked or min(ny, nx) < 0 or ny >= Y or nx >=X and (ny, nx) or (k==1 and (ny, nx) in king):
                                break
                        else:
                            if not visit[ny][nx]:
                                visit[ny][nx] = True;
                                next.append((ny, nx, d+1))
        frontier = next
    print(-1)
bfs()
