#include <cstdio>
using namespace std;
int a[16][16];
int ans;
int dyx[4][2] = { {0, -1}, {0, 1 }, {-1, 0}, {1, 0} };

void dfs(int y, int x) {
    if (a[y][x] == 3) {
        ans = 1;
        return;
    }
    a[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dyx[i][0], nx = x+dyx[i][1];
        if (a[ny][nx] != 1) dfs(ny, nx);
    }
}

int main(int t) {
    while (t<10) {
        scanf("%d", &t);
        for (int i = 0; i < 16; i++) for (int j=0; j < 16; j++) scanf("%1d", &a[i][j]);
    ans = 0;
    dfs(1,1);
    printf("#%d %d\n", t, ans);
    }
w
