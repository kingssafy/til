#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int grid[25][25];

int abs(int a) {
    if (a > 0) return a;
    return -a;
}

int getDis(int sy, int  sx, int ey, int ex) {
    int dy = abs(sy - ey);
    int dx = abs(sx - ex);
    return dy+dx;
}

int color(int sy, int sx, int add) {
    for (int y = min(sy- K, 0); y < max(sy+K+1, N); y++) {
        for (int x = min(sx-K, 0); x < max(sx+K+1, N); x++) {
            if (getDis(sy, sx, y, x) <= K && )
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("paint_input.txt", "r", stdin);
    cin >> N >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> grid[y][x];
        }
    }
    

    return 0;
}
