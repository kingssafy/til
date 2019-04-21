#include <iostream>
using namespace std;

int main() {
    int const MAXN = 10;
    int n;
    cin >> n;
    int grid[MAXN][MAXN] = {};
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (x == 0 || y == 0) {
                grid[y][x] = 1;
                continue;
            }
            grid[y][x] = grid[y-1][x] + grid[y][x-1];
        }
    }
    cout << grid[n-1][n-1] << "\n";

    return 0;
}
