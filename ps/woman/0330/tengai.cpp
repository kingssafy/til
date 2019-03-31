#include <cstdio>
#include <algorithm>
using namespace std;
int grid[13][5] = {};
int bombgrid[13][5]= {};
int coins[13] = {};
int maximum = -9999999;

void dfs(int y, int x, int curScore) {
    if (y == 0) {
        maximum = max(maximum, curScore);
        return;
    } else {

        for (int i = -1; i < 2; i++) {
            int nx = x+i;
            if (nx >= 0 && nx < 5 && curScore+coins[y-1]*10 > maximum) {
                printf("curScore %d\n", curScore);
                dfs(y-1, nx, curScore+bombgrid[y-1][nx]);
            }
        }
    }

}


int main() {
    freopen("tengai_input.txt", "r", stdin);
    int T;
    char temp;
    int temp2;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        for (int y = 0; y < 13; y++) {
            for (int x = 0; x < 5; x++) {
                scanf(" %1c", &temp);
                if (temp == '0') temp2 = 0;
                if (temp == 'X') temp2 = -7;
                if (temp == '*') temp2 = 10;
                grid[y][x] = temp2;
                if (temp == '*') coins[y]++;
            }
        }
        maximum = -999999;
        for (int i = 1; i < 13; i++) coins[i] += coins[i-1];
        for (int i = 0; i < 9; i++) {
            for(int y = 0; y < 13; y++)
                for (int x = 0; x< 5; x++)
                    bombgrid[y][x] = grid[y][x];
            for (int k = 0; k < 5; k++) {
                for (int x = 0; x < 5; x++)
                    if (bombgrid[i+k][x] == -7) bombgrid[i+k][x] = 0;
            }
            for (int y = 0; y < 13; y++) {
                for (int x = 0; x < 5; x++) {
                    printf("%d ", bombgrid[y][x]);
                }
                printf("\n");
            }
            printf("\n");
            dfs(12, 2, 0);

        }

        printf("%d\n", maximum);




    }

    return 0;
}
