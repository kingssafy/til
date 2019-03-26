#include <bits/stdc++.h>

using namespace std;
const int N = 100;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int grid[N][N] = {};
int result;
int x,y,d;
int ny, nx, nd;
int Y, X;
int counter=0;
//y,x,d
int bfs(int sy, int sx) {
    int Q[10001][3] = {};
    bool visited[N][N] = {};
    int rear=0, front=0;
    visited[sy][sx] = true;
    Q[rear][0]=sy;
    Q[rear][1]=sx;
    Q[rear++][2]=0;
    while (front < rear) {
        y = Q[front][0];
        x = Q[front][1];
        d = Q[front++][2];
        counter++;
        for (int i = 0; i < 4; i++) {
            ny =  y+dy[i];
            nx = x+dx[i];
            nd = d+1;
            if (
                    min(ny, nx) >= 0 && ny < Y && nx < X  &&
                    !visited[ny][nx] && grid[ny][nx] == 1
               ) {
                visited[ny][nx]=true;
                Q[rear][0]=ny;
                Q[rear][1]=nx;
                Q[rear++][2]=nd;
            }
        }
        

    }
    result = Q[front-1][2];
    return counter;
}



int main() {
    freopen("a7.txt", "r", stdin);
    scanf("%d %d", &X, &Y);
    int total=0;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            scanf("%1d", &grid[y][x]);
            total += grid[y][x];
            
        }
    }
    int sy, sx;
    scanf("%d %d", &sx, &sy);
    bfs(sy-1, sx-1);
    cout << result+3 <<endl  << total-counter;
    return 0;
}
