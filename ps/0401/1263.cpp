#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int adj[MAX][MAX];
int main() {
    freopen("1263_input.txt", "r", stdin);
    int T, N, temp;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d", &N); 
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++) {
                scanf("%d", &temp);
                if (y == x) {
                    adj[y][x] = 0;
                } else if (temp) {
                    adj[y][x] = temp;
                } else {
                    adj[y][x] = 10000;
                }
            }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {

                if (i == j) continue;
                for (int k = 0; k < N; k++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[j][k]);
            }

        int result = 2147483647;
        for (int i = 0; i < N; i++) {
            temp = 0;
            for (int j = 0; j < N; j++) {
                temp += adj[i][j];
            }
            result = min(result, temp);
        }
        printf("#%d %d\n", tc+1, result);
    }

    return 0;
}
