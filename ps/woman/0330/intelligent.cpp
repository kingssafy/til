#include <iostream>
#include <cstdio>
using namespace std;
const int MAXY = 31, MAXX = 8;
int grid[MAXY][MAXX] = {};
int Y, X;
int maximum = 0;
void dfs(int k, int curSum, int curProfit) {
    if (curSum > Y) return;
    if (k == X+2) return;
    maximum = max(curProfit, maximum);
        for (int y = 0; y < Y; y++) {
            if (curSum+y+1 <= Y) {
                dfs(k+1, curSum+y+1, curProfit+grid[y][k]);
            }
    }
    dfs(k+1, curSum, curProfit);
}

int main() {
    scanf("%d %d", &Y, &X); 
        for (int y = 0; y < Y; y++) {
            for(int x = 0; x < X+1; x++) {
                scanf("%d", &grid[y][x]);
            }
        }
        dfs(1,0,0);
    printf("%d", maximum);
    
    
    

    return 0;
}
