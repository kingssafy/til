#include <cstdio>
#include <iostream>
#define size 100
using namespace std;
int N;
int grid[size][size] = {}; 
int visit[10] = {};
int result = 9999;

void dfseasy(int k, int curSum) {
    if (k == N) {
        printf("%d\n", curSum);
    } else {
        int temp = grid[k][0];
        for (int x = 0; x < N; x++) {
            temp = min(temp, grid[k][x]);
        }
        dfseasy(k+1, curSum+temp);

    }
}

void dfs(int r = -1, int curSum = 0) {
    if (r+1 == N) {
        result = min(curSum, result); 
    } else {
        for (int i = 0; i < N; i++) {
            if (!visit[i]) {
                visit[i] = true;
                dfs(r+1, curSum+grid[r+1][i]);
                visit[i]=false;
            }
        }
    }
}


int main() {
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &grid[y][x]);
        }
    }
    dfseasy(0, 0);
    dfs(-1, 0);
    cout << result << endl;
    return 0;
}
