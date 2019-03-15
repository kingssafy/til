#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int grid[50][50] = {{0}};
    int T, N, temp, mid, result;
    cin >> T;
    for (int tc = 0; tc < 1; tc++) {
        cin >> N;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                scanf("%1d", &temp);
                grid[r][c] = temp;
            }
        }
        mid = N/2;
        result = 0;
        for (int y = 0; y < mid +1; y++) {
            for (int x = mid-y; x <= mid+y; x++) {
                result += grid[y][x];
                if (y != mid) {
                    result += grid[N-y-1][x]; // grid[N-y][x] -> grid[N-y-1][x]
                }
            }
        }
        cout << "#" << tc+1<< " " << result << endl;
    }

    return 0;
}

