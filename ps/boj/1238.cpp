#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int const MAXN = 1001, MAXNM = 10001, INF = 1e9;
    int N, M, X, u, v, w;
    int dis[MAXN][MAXN] = {};
    scanf("%d %d %d", &N, &M, &X);
    for (int u = 0; u < N; u++)
        for (int v = 0; v < N; v++)
            dis[u][v] = INF;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--;v--;
        dis[u][v] = w;
    }
    for (int t = 0; t < N; t++) {
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                if (dis[u][v] > dis[u][t] + dis[t][v]) {
                    dis[u][v] = dis[u][t] + dis[t][v];
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
        result = max(result, dis[i][X-1]+ dis[X-1][i]); 
    }
    printf("%d\n", result);
}
