#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int total;
int mini;
int grid[200][200];
bool visit[1000] = {};
int me;

void dfs(int s) {
    if (s >= me) {
        int temp;
        int a=0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                temp = grid[y][x];
                if (visit[y] && visit[x]) {
                    a += temp;
                } 
            } 
        }
        mini = min(mini, abs(total - 2*a)) ;
        return;
    }

    for (int i = s; i < N; i++) {
        if  (!visit[i]) {
            visit[i] = true;
            dfs(s+1);
            visit[i] = false;
            dfs(s);
        }
    }
}

int main() {
    freopen("cook_input.txt", "r", stdin);
    int T; 
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        total = 0;
        mini = 99999999;
        scanf("%d", &N);
        me = N/2;
        for (int y = 0; y < N; y++)
            for (int x = 0; x< N; x++) {
                scanf("%d", &grid[y][x]);
                total += grid[y][x];
            }
        for (int i = 0; i < 20; i++) {
            visit[i] = false;

        }  
        dfs(0);
        cout << mini << endl;
    }
}
