#include <iostream>
#include <cstdio>
using namespace std;
struct pipe {
    int v;
    int h;
    int d;
    int wall;
};

pipe dp[16][16] = {{}};
int N;

int main() {
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &dp[y][x].wall);
        }
    }
    for (int x = 1; x < N; x++) {
        if (dp[0][x].wall == 1) break;
            dp[0][x].h = 1; 

    }

    for (int y = 1; y < N; y++) {
        for (int x = 1; x < N; x++) {
            if (dp[y][x].wall == 1) continue;
                dp[y][x].h = dp[y][x-1].d + dp[y][x-1].h;
                dp[y][x].v = dp[y-1][x].v + dp[y-1][x].d;
                dp[y][x].d = (dp[y-1][x].wall ==1 || dp[y][x-1].wall ==1 ) ? 0 : dp[y-1][x-1].d+dp[y-1][x-1].h+dp[y-1][x-1].v;
        }
    }
    cout << dp[N-1][N-1].d + dp[N-1][N-1].h+dp[N-1][N-1].v << endl;
    return 0;
}
