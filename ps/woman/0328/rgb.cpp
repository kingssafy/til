#include <cstdio>
using namespace std;
char grid[60][60];
char grid2[60][60];
int N;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(char grid[][60], int sy, int sx, char c, bool checker) {
    int Qy[3600] = {};
    int Qx[3600] = {};
    int front=0, rear = 0;
    Qy[rear] = sy;
    Qx[rear++] = sx;
    grid[sy][sx] = 0;
    while (front < rear) {
        int y = Qy[front];
        int x = Qx[front++];
        for (int i = 0; i < 4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (checker && (c == 'R' || c == 'G' )) {
                if (ny >= 0 && nx >= 0 && ny < N && nx < N && (grid[ny][nx] == 'G' || grid[ny][nx] == 'R')) {
                    grid[ny][nx] = 0;
                    Qy[rear] = ny;
                    Qx[rear++] = nx;
                }
            } else if (ny >= 0 && nx >= 0 && ny < N && nx < N && grid[ny][nx] == c)  {
                grid[ny][nx] = 0;
                Qy[rear] = ny;
                Qx[rear++] = nx;
            }
        }
    }
}

int main() {
    char temp;
    scanf("%d", &N);
    for (int y = 0; y < N; y++) 
        for (int x = 0; x < N; x++) {
            scanf(" %c", &temp);
            grid[y][x] = temp;
            grid2[y][x] = temp;
        }
    int a = 0, b = 0;
    for (int y = 0 ; y < N; y++)
        for (int x = 0; x <N; x++) {
            if (grid[y][x] != 0) {
                bfs(grid, y, x, grid[y][x], false);
                a++;
            }
            if (grid2[y][x] != 0) {
                bfs(grid2, y, x, grid2[y][x], true);
                b++;
            }
        }
    printf("%d %d", a, b);
    
    
    return 0;
}
