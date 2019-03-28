#include <cstdio>
#include <iostream>
using namespace std;

int N;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int grid[25][25] = {};
int cc = 0;

int bfs(int sy, int sx) {
    int Qy[1000] = {};
    int Qx[1000] = {};
    int front = 0, rear = 0, result = 0;
    Qy[rear] = sy;
    Qx[rear++] = sx;
    grid[sy][sx] = 0;
    while (front < rear) {
        int y = Qy[front];
        int x = Qx[front++];
        result++; 
        for (int i = 0; i < 4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (min(ny, nx) >=0 && max(ny, nx) < N && grid[ny][nx] == 1) {
                Qy[rear] = ny;
                Qx[rear++] = nx;
                grid[ny][nx] = 0;
            }
        } 
    }
    return result;
}

int main() {
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%1d", &grid[y][x]);
        }
    }

    int counter = 0;
    int answersheet[1000];
    for (int y = 0; y < N; y++) {
        for (int x = 0; x <N; x++) {
            if (grid[y][x] == 1) {
                answersheet[counter++] = bfs(y, x);
            }
        }
    }
    printf("%d\n", counter);
    for (int i = 0; i < counter; i++) {
        cout << answersheet[i] << endl;
    }



    return 0;
}
