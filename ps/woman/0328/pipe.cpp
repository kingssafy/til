#include <cstdio>

const int MAX = 10;

int N;
int grid[MAX][MAX] = {};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int pipes[13][4] = {
    {0,0,0,0},
    {0,1,0,1},
    {1,0,1,0},
    {0,1,1,0},
    {0,0,1,1},
    {1,0,0,1},
    {1,1,0,0},
    {1,1,1,0},
    {0,1,1,1},
    {1,0,1,1},
    {1,1,0,1},
    {1,1,1,1},
};

int bfs(int sy, int sx) {
    int used = 0;
    int Qy[101], Qx[101], Qp[101], front = 0, rear = 0;
    Qy[rear] = sy;
    Qx[rear] = sx;
    Qp[rear++] = grid[sy][sx];
    grid[sy][sx] = 0;
    used ++;
    while (front < rear) {
        int y = Qy[front];
        int x = Qx[front];
        int p = Qp[front++];
        for (int i = 0; i < 4; i++) {
            if (pipes[p][i]) {
                int ny = y+dy[i];
                int nx = x+dx[i];
                if (ny >= 0 && nx >= 0 && ny < N && nx < N && pipes[grid[ny][nx]][(i+2)%4]) {
                    Qy[rear] = ny;
                    Qx[rear] = nx;
                    Qp[rear++] = grid[ny][nx];
                    grid[ny][nx] = 0;
                    used++;
                }
            } 
        }
    }
    return used;
}

int main() {
    int sy, sx, total = 0;
    scanf("%d", &N);
    scanf("%d %d", &sy, &sx);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++) {
            scanf("%1x", &grid[y][x]);
            if (grid[y][x]) total++;
        }

    int used = bfs(sx, sy); // swaped sy and sx to get the right answer
    printf("%d", total - used);
  
    return 0;
}
