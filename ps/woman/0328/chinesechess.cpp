#include <cstdio>
using namespace std;
const int MAX = 100;
int Y, X;
int sy, sx, ey, ex;
int dy[12] = {-1, -1, -1, 0, -1, 1, 1, 1, 1, 0, 1, -1};
int dx[12] = {0, -1, 1, 1, 1, 1, 0, 1, -1, -1, -1, -1};
bool visit[MAX][MAX] = {};

void bfs() {
    int Qy[10000] = {};
    int Qx[10000] = {};
    int Qd[10000] = {};
    int front = 0, rear = 0;
    Qy[rear] = sy;
    Qx[rear] = sx;
    Qd[rear++] = 0;
    visit[sy][sx] = true;
    while (front < rear) {
        int y = Qy[front];
        int x = Qx[front];
        int d = Qd[front++];
        if (y==ey && x == ex) {
            printf("%d\n", d);
            return;
        }
        for (int i = 0; i < 12; i += 3) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (!(ny == ey && nx==ex) && ny < Y && nx < X && ny>=0 && nx >= 0) {
                for (int j = 1; j <= 2;j++) {
                    int nny = ny+dy[i+j];
                    int nnx = nx+dx[i+j];
                    if (!visit[nny][nnx] && nny < Y && nnx < X && nny>=0 && nnx >= 0) {
                        visit[nny][nnx] = true;
                        Qy[rear] = nny;
                        Qx[rear] = nnx;
                        Qd[rear++] = d+1;
                    }
                }
            }
        }
    }
    printf("-1");
}


int main() {
    scanf("%d %d", &Y, &X); 
    scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
    bfs();
    return 0;
}
