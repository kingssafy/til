#include <stdio.h>
const int HMAX = 10;
const int WMAX = 25;

int grid[HMAX][WMAX] = {};

bool ff(int y, int x) {

    for (int dy = 0; dy < 2; dy++) {
        for (int dx = 0; dx < 2; dx++) {
            if (grid[y+dy][x+dx] == 1 || grid[y+dy][x+dx] == 2) {
                return false;
            }
        }
    }
    for (int dy = 0; dy < 2; dy++) {
        for (int dx = 0; dx < 2; dx++) {
            grid[y+dy][x+dx] = 2;
        }
    }
    return true;

}


int main() {
    freopen("chip_input.txt", "r" , stdin);
    int T;
    int H, W;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d", &H, &W);
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                scanf("%d", &grid[y][x]);
            }
        }
        int count = 0;
        for (int y = 0; y < H-1; y++) {
            for (int x = 0; x < W-1; x++) {
                if (grid[y][x] == 0) {
                    count += ff(y, x); 
                }
            }
        }

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                printf("%d ", grid[y][x]);
            }
            printf("\n");
        }
        printf("\n");

        printf("#%d %d\n", tc+1, count);
    }

    return 0;
}

