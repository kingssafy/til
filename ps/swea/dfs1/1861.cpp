#include <iostream>
#include <fstream>
using namespace std;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool ingrid(int y, int x, int N) {
    if (min(y, x) < 0 and max(y, x) >= N) {
        return false;
    }
    return true;
}
int maximum = 0;
void dfs(int grid[][201], int marker[][201], int N, int y, int x, int ny, int nx, int depth=1) {  
    maximum = max(depth, maximum);
    if (marker[y][x] < depth) marker[y][x] = depth;
    for (int d = 0; d < 4; d++) {
        int my = ny+dy[d];
        int mx = nx+dx[d];  
        if (ingrid(ny, nx, N) && grid[my][mx] == grid[ny][nx]+1) {
            dfs(grid, marker, N, y, x, my, mx, depth+1);
        }
    }
}
int main() {
    ifstream cin("1861.txt");
    int T, N, temp, grid[201][201] ={{}};
    int marker[201][201] = {{}}; 
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> temp;
                grid[i][j] = temp;
                marker[i][j] = 0;
            }
        }
        maximum = 0;
        int minimum = 40001;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dfs(grid, marker, N, i, j, i, j, 1);
            }
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (marker[y][x] == maximum) {
                    minimum = min(minimum, grid[y][x]);
                }
            }
        }
        cout << "#" << tc+1 << " " << minimum << " " << maximum << endl;
    
    }

    return 0;
}
