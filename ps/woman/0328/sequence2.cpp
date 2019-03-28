#include <cstdio>
#include <algorithm>

using namespace std;
struct dp {
    int n;
    int ri;
    int rd;
    int ci;
    int cd;
};
dp grid[1000][1000] = {};

int main() {
    int N;
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x< N; x++) {
            scanf("%d", &grid[y][x].n);
            grid[y][x].ri = 1;
            grid[y][x].rd = 1;
            grid[y][x].ci = 1;
            grid[y][x].cd = 1;
        }
    }
    int result = 1;
    for (int y= 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (x >0 ) {
                grid[y][x].ri += grid[y][x-1].n + 1 == grid[y][x].n ? grid[y][x-1].ri : 0;
                grid[y][x].rd += grid[y][x-1].n - 1 == grid[y][x].n ? grid[y][x-1].rd : 0;
            }
            if (y > 0) {
                grid[y][x].ci += grid[y-1][x].n + 1 == grid[y][x].n ? grid[y-1][x].ci: 0;
                grid[y][x].cd += grid[y-1][x].n - 1 == grid[y][x].n ? grid[y-1][x].cd: 0;
            }
            result = max({result, grid[y][x].ri, grid[y][x].rd, grid[y][x].ci, grid[y][x].cd}); // better put result in max;;;

        }
    }

    printf("%d\n", result);

}
