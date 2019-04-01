#include <iostream>
using namespace std;
const int MAX = 50;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int pipes[7][4] = {
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1},
    {1, 1, 0, 0},
};
int N;
int grid[MAX][MAX] = {};
int bfs() {
    int Qy[99999] = {};
    int Qx[99999] = {};
    int Qb[99999] = {};
    int Qd[99999] = {};
    bool visit[MAX][MAX][4] = {};
    int rear = 0, front = 0;
    Qy[rear] = 0;
    Qx[rear] = 0;
    Qb[rear] = 1;
    Qd[rear++] = 1;
    visit[0][0][0] = true;
    visit[0][0][1] = true;
    visit[0][0][2] = true;
    visit[0][0][3] = true;
    while (front < rear) {
        int y = Qy[front];
        int x = Qx[front];
        int b = Qb[front];
        int nb = (b+2)%4;
        int d = Qd[front++];
        int curPipe = grid[y][x]; 
        printf("y: %d, x: %d, b: %d, d: %d\n", y, x, b, d);
        if (y == N-1 && x == N-1) {
            if(curPipe == 1 || curPipe == 2) {
                for (int i = 0; i < 2; i++) {
                    int rotatePipe = (curPipe-1+i)%2 +1;
                    if (pipes[rotatePipe][nb] && pipes[rotatePipe][1]) return d;
                } 
            } else {
                for (int i = 0; i < 4; i++) {
                    int rotatePipe = (curPipe-3+i)%4 +3;
                    if (pipes[rotatePipe][nb] && pipes[rotatePipe][1]) return d;
                }
            }
        } else {
            if (curPipe == 1 || curPipe == 2) {
                for (int i = 0; i < 2; i++) {
                    int rotatePipe = (((curPipe-1)+i) % 2) + 1; 
                    if (!pipes[rotatePipe][nb])  continue;
                    for (int j = 0; j < 4 ; j++) {
                        if (nb != j && pipes[rotatePipe][j] && y+dy[j] < N && y+dy[j] >= 0 &&
                                x+dx[j] >= 0 && x+dx[j] < N && grid[y+dy[j]][x+dx[j]] != 0 && !visit[y+dy[j]][x+dx[j]][j]) {
                            visit[y+dy[j]][x+dx[j]][j] = true;
                            //visit[y+dy[j]][x+dx[j]] = true;
                            Qy[rear] = y+dy[j];
                            Qx[rear] = x+dx[j];
                            Qb[rear] = j;
                            Qd[rear++] = d+1;
                        }
                    }
                }
            } else {
                for (int i = 0; i < 4; i++) {
                    int rotatePipe = (((curPipe-3)+i) % 4) + 3; 
                    if (!pipes[rotatePipe][nb])  continue;
                    for (int j = 0; j < 4 ; j++) {
                        if (nb != j && pipes[rotatePipe][j] && y+dy[j] < N && y+dy[j] >= 0 &&
                                x+dx[j] >= 0 && x+dx[j] < N &&  grid[y+dy[j]][x+dx[j]] != 0 && !visit[y+dy[j]][x+dx[j]][j]) {// !visit[y+dy[j]][x+dx[j]]gives me wrong answer;
                            //visit[y+dy[j]][x+dx[j]] = true;
                            visit[y+dy[j]][x+dx[j]][j] = true;
                            Qy[rear] = y+dy[j];
                            Qx[rear] = x+dx[j];
                            Qb[rear] = j;
                            Qd[rear++] = d+1;
                        }
                    }
                }
            }


        }
    }
    return -1;    
}


int main() {
    freopen("minimize_pipe.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
                cin >> grid[y][x];
        int result = bfs();
        cout << "#" << tc+1 << " " << result << endl;

    }

    return 0;
}
