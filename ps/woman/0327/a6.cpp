#include <iostream>
using namespace std;
const int MAX = 101;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int grid[MAX][MAX] = {};
int visit[MAX][MAX] = {};
int sx, sy, ex, ey;
int X, Y;
int y, x, d;
int ny, nx, nd;
int bfs() {
    int Qy[10001] = {sy};
    int Qx[10001] = {sx};
    int Qd[10001] = {0};
    int front = 0, rear = 1; 
    visit[sy][sx] = true;
    while (front < rear) {
        y = Qy[front];
        x = Qx[front];
        d = Qd[front++];
        if (y == ey && x == ex) return d;
        for (int i = 0; i < 4; i++) {
            ny = y+dy[i];
            nx = x+dx[i];
            nd = d+1;
            if (min(ny, nx) >= 0 &&
                ny < Y && nx < X && !visit[ny][nx] && grid[ny][nx] != 1 ) 
            {
                visit[ny][nx] = true;
                Qy[rear] = ny;
                Qx[rear] = nx;
                Qd[rear++] = nd;
            }
            
        }
         
    }
    return 0;

}

int main() {
    freopen("a6.txt", "r", stdin);
    scanf("%d %d", &X, &Y);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    sx--;sy--;ex--;ey--;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            scanf("%1d", &grid[y][x]);
        }
    }
    cout << bfs();


}

