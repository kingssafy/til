#include <iostream>
#include <fstream>
using namespace std;

int dy[4] = {1, 1, -1, -1};
int dx[4] = {1, -1, -1, 1};
bool eat[101] = {};
int result;
void dfs(int grid[20][20], bool visit[20][20], int N, int sy, int sx, int y, int x, int k, int d) {

    for (int i = k; i < min(k+2, 4); i++) {
        if (y+dy[i] < N && y+dy[i] >= 0 &&
                x+dx[i] < N && x+dx[i] >= 0 &&
                !visit[y+dy[i]][x+dx[i]] &&
                !eat[grid[y+dy[i]][x+dx[i]]]) {
            visit[y+dy[i]][x+dx[i]] = true;
            eat[grid[y+dy[i]][x+dx[i]]] = true;
            dfs(grid, visit, N, sy, sx, y+dy[i], x+dx[i], i, d+1);
            eat[grid[y+dy[i]][x+dx[i]]] = false;
            visit[y+dy[i]][x+dx[i]] = false;
        } else if (y+dy[i] == sy && x+dx[i] == sx) {
            result = max(result, d);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("cafe_input.txt");
    int T, N, grid[20][20]={};
    bool visit[20][20] = {};
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> grid[y][x];
            }
        }
        result = -1;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                visit[y][x] = true;
                eat[grid[y][x]] = true;
                dfs(grid, visit, N, y, x, y, x, 0, 1);
                visit[y][x] = false;
                eat[grid[y][x]] = false;
                }
            }
        cout << "#" << tc+1 << " " << result << endl;
        }
        return 0;
    }
