#include <iostream>
#include <cstdio>
using namespace std;

int abs(int a) {
    if (a > 0) return a;
    return -a;
}

int dis(int sy, int sx, int ey, int ex) {
    int dy = abs(sy - ey);
    int dx = abs(sx - ex);
    return dy+dx;
}
struct P {
    int y;
    int x;
};

const int MAXN = 51, MAXM = 14;
int grid[MAXN][MAXN] ={};
int N, M;
P homes[2*MAXN] = {};
P chickens[MAXM] = {};
int H = 0, C = 0;
int result;
int subset[MAXN] = {};
void dfs(int depth = 0, int select = 0) {
    if (depth > C) return; 
    if (select == M) {
        int temp = 0;
        for (int i = 0; i < H; i++) {
            int hy = homes[i].y;
            int hx = homes[i].x;
            int curMin = 1e9;
            for (int j = 0; j < C; j++) {
                if (!subset[j]) continue;
                curMin = min(curMin, dis(hy, hx, chickens[j].y, chickens[j].x));
            }
            temp += curMin;
        }
        result = min(result, temp);
    } else {
        subset[depth] = 1;
        dfs(depth+1, select+1);
        subset[depth] = 0;
        dfs(depth+1, select);
    }
}

int main() {
    freopen("chicken_input.txt", "r", stdin);
    int temp;
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &temp);       
            if (temp == 1) {
                homes[H++] = {y, x};
            } else if (temp == 2) {
                chickens[C++] = {y, x};
            }
        }
    }
    result = 2e9;
    dfs(0, 0);
    cout << result << endl;

    return 0;
}
