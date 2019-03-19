#include <iostream>
using namespace std;

int main() {
    int T, N, temp, grid[101][101];
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> temp;
                grid[i][j] = temp;
            }
        }
    }
    return 0;
}
