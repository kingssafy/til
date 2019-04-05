#include <cstdio>
using namespace std;
const int MAXSIZE = 101;
struct P {
    int x;
    int y;
};

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int N;
P curves[2000] = {};
int grid[MAXSIZE][MAXSIZE] = {};



int main() {
    freopen("dragon_input.txt", "r", stdin);
    scanf("%d", &N);  
    int x, y, d, g;
    for (int u = 0; u < N; u++) {
        scanf("%d %d %d %d", &x, &y, &d, &g);
        P temp[2000];
        int rear = 0;
        // 0 gen;
        temp[rear].x = x;
        temp[rear++].y = y;
        temp[rear].x = x+dx[d];
        temp[rear++].y = y+dy[d];
        for (int k = 0; k < g; k++) {
            //printf("%dgen\n", k);
            int end = rear-1;
            for (int i = end; i > 0; i--) {
                int cx = temp[i].x;
                int cy = temp[i].y;
                int bx = temp[i-1].x;
                int by = temp[i-1].y;
                int ax = cx-bx;
                int ay = cy-by;
                if (ax) {
                    temp[rear].y = temp[rear-1].y-ax;
                    temp[rear].x = temp[rear-1].x;
                    rear++;
                } else {
                    temp[rear].y = temp[rear-1].y;
                    temp[rear].x = temp[rear-1].x+ay;
                    rear++;
                }
            }

        }
        for (int i = 0; i < rear; i++) {
            grid[temp[i].y][temp[i].x] = 1;
        }
    }
    int result = 0;
    for (int y = 0; y < MAXSIZE-1; y++) {
        for (int x = 0; x < MAXSIZE-1; x++) {
            if (grid[y][x] == 1 && grid[y+1][x] == 1 && grid[y][x+1] == 1 && grid[y+1][x+1] == 1) result++;
        }
    }
    printf("%d\n", result);
    return 0;
}
