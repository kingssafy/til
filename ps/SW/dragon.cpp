#include <iostream>
using namespace std;
const int MAXN = 20, MAXP = 2000;
int grid[101][101] = {};

struct P {
    int y;
    int x;
};

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

P curves[MAXN][MAXP];

int N;


int main() {
    freopen("dragon_input.txt", "r", stdin);
    int y, x, d, G;
    cin >> N; 
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> G; 
        int rear=0;
        curves[i][rear++] = {y, x};
        curves[i][rear++] = {y+dy[d], x+dx[d]};
        for (int g = 1; g < G; g++) {
            int endidx = rear-1;
            cout << endidx << endl;
            for (int p = endidx; p > 0; p--) {
                int cy = curves[i][p].y;
                int cx = curves[i][p].x;
                int by = curves[i][p-1].y;
                int bx = curves[i][p-1].y;
                int ny = by-cy;
                int nx = bx-cx;
                if (ny != 0) {
                    curves[i][rear] = {curves[i][rear-1].y, curves[i][rear-1].x - ny};
                    rear++;
                } else {
                    curves[i][rear] = {curves[i][rear-1].y + nx, curves[i][rear-1].x};
                    rear++;
                }
            }
        }
        for (int idx = 0; idx < rear; idx++) {
            int cy = curves[i][idx].y;
            int cx = curves[i][idx].x;
            if (cx < 0 || cy < 0 || cy > 100 || cx >100) continue;
            grid[cy][cx] = 1;
        }
    }
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            cout << grid[y][x] << " ";
        }
        cout << endl;
    }

    return 0;
}
