#include <iostream>

using namespace std;
int abs(int a) {
    return a > 0 ? a: -a;
}

int main() {
    int grid[5][5] = {};
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cin >> grid[y][x];
            if (grid[y][x] == 1) {
                cout << abs(y-2) + abs(x-2) << "\n";
                return 0;
            }
        }
    }

    return 0;
}
