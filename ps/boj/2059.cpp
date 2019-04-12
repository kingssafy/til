#include <cstdio>
using namespace std;

int const MAXN = 1001;
int grid[MAXN][MAXN] = {};
int process[MAXN] = {};
int sorted[MAXN] = {};
int rear = 0;
int N;

void dfs(int cn, int pn) {
    process[cn] = 1;
    for (int i = 0; i < N; i++) {
        if (grid[cn][i] && !process[i] && i != pn) {
            dfs(i, cn);
        }
    }
    process[cn] = 2;
    sorted[rear++] = cn;
}

int main(void) {
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &grid[y][x]);
        }
    }
    int counter = 0;
    for (int i = 0; i < N; i++) {
       if (process[i]) continue;
       dfs(i,-1);
       counter++;
    }
    printf("%d\n", counter);
    printf("%d ", rear);
    for (int i = rear-1; i >= 0; i--) {
        printf("%d ", sorted[i]+1);
    }
    
    return 0;
}
