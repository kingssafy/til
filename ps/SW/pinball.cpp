#include <iostream>
using namespace std;

const int MAXN = 102;
int N;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int grid[MAXN][MAXN] = {};

int wall[6][4] = {
    {0, 1, 2, 3},
    {2, 3, 1, 0},
    {1, 3, 0, 2},
    {3, 2, 0, 1},
    {2, 0, 3, 1},
    {2, 3, 0, 1}
};

void wormhole(int &i, int&j, int wormhole) {
    for (int y = 1; y < N + 1 ; y++) {
        for (int x = 1; x < N + 1; x++) {
            if ((i != y || j != x) && grid[y][x] == wormhole) {
                i = y;
                j = x;
                return;
            }
        }
    }
}

int simulation(int sy, int sx, int d) {
    int count = 0; 
    int y = sy;
    int x = sx;
    while (true) {
        y = y+dy[d];
        x = x+dx[d];
        if (grid[y][x] == -1 || (y == sy && x == sx)) {
            break;
        } 
        if (grid[y][x] == 0 ) {
            continue;
        }
        if (grid[y][x] < 6) {
            d = wall[grid[y][x]][d];
            count++;
        } else {
            wormhole(y, x, grid[y][x]);
        }

    }
    return count;
}
int solve() {
    int result = 0;
    for (int y = 1; y < N+1; y++) {
        for (int x = 1; x < N + 1; x++) {
            if (grid[y][x] == 0) {
                for (int i = 0; i < 4; i++) {
                    result = max(simulation(y, x, i), result);
                }
            } 
        }
    }
    return result;
}

int main() {
    freopen("pinball_input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;    
        for (int y = 0; y < N + 2; y++) 
            for (int x = 0; x < N + 2; x++)  {
                if (x == 0 || y == 0 || x == N+1 || y == N+1) { 
                    grid[y][x]=5;
                    continue;
                }
                cin >> grid[y][x];
            }
        cout << "#" << tc+1 << " " << solve() << endl; 

        //        for (int y = 0; y < N + 2; y++) {
        //            for (int x = 0; x < N + 2; x++) {
        //                cout << grid[y][x] << " ";
        //            }
        //            cout << endl;
        //        }

    }



    return 0;
}
