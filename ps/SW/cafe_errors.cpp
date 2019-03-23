#include <iostream>
#include <fstream>
using namespace std;
int dy[4] = {1, 1, -1, -1};
int dx[4] = {1, -1, -1, 1};
int eat[500] = {};
int visited[20][20] = {};
int result = 0;

bool eated(int eat[500], int d, int k) {
    for (int i = 0; i <= d; i++) {
        if (eat[d] == k) return true;
    }
    return false;
}
int dfs(int grid[][20], int N, int sy, int sx, int y, int x, int l = 0, int d=0) {
    eat[d] = grid[y][x];
    for (int i = l; i < min(l+2,4); i++) {
        if (y+dy[i] >= 0 && y+dy[i] < N &&
                x+dx[i] >= 0 && x+dx[i] < N &&
                !visited[y+dy[i]][x+dx[i]] &&
                !eated(eat, d, grid[y+dy[i]][x+dx[i]]) ) {
            visited[y+dy[i]][x+dx[i]] = true;
            dfs(grid, N, sy, sx, y+dy[i], x+dx[i], i, d+1);
            visited[y+dy[i]][x+dx[i]] = false;
        } else if (y-1 == sy && x+1 == sx) {
            result = max(result, d); 
        } 
    }
    return 1;
}


int main() {
    ifstream cin("cafe_input.txt");
    int T, N, grid[20][20], temp;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> temp;
                grid[y][x] = temp;
            }
        }
        result = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                visited[y][x] = true;
                dfs(grid, N, y, x, y,  x, 0, 1);
                visited[y][x] = false;
            }
        }
        cout << result << endl;
    }
    return 0;
}
