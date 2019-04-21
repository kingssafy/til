#include <iostream>
using namespace std;
int const MAXSIZE = 501;
int grid[MAXSIZE][MAXSIZE] {};
int ans[MAXSIZE] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> grid[y][x];
        }
    }
    int res = 0;
    for (int y = 0; y < n; y++) {
        res ^= grid[y][0];
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++)
            if (res^grid[y][x]^grid[y][0]) {
                ans[y] = x;
                printf("TAK\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", ans[i]+1);
                }
                return 0;
            }
    }
    printf("NIE\n");

    
    return 0;
}
