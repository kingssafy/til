#include <iostream>
using namespace std;

int main() {
    int grid[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 3, 7, 9, 2, 7},
        {0, 9, 8, 3, 5, 5},
        {0, 1, 7, 9, 8, 5},
        {0, 3, 8, 6, 4, 10},
        {0, 6, 3, 9, 7, 8},
    };
    int sum[6][6] = {{}};
    sum[0][0] = grid[0][0];
    for (int y = 1; y <= 5; y++) {
        for (int x = 1; x <= 5; x++) {
            sum[y][x] = max(sum[y][x-1],sum[y-1][x])+grid[y][x];
            }
        }

    for (int r = 1; r <= 5; r++) {
        for (int c = 1; c <= 5; c++) {
            cout << sum[r][c] << " ";
        }
        cout << endl;
    }
    return 0;

}
