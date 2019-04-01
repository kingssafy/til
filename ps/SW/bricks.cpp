#include <iostream>
using namespace std;
const int MAXH = 15, MAXW=12;
int N, W, H;
int dy[4] = {-1,0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int grid[MAXH][MAXW];
int minimum;
int getY(int grid[MAXH][MAXW], int x) {
    for (int y = 0; y < H; y++) {
        if (grid[y][x]) return y;
    }
    return H-1; // all 0
}

void bomb(int grid[MAXH][MAXW], int y, int x) {
    int range = grid[y][x];
    grid[y][x] = 0;
    if (range>1) {

        for (int d = 0; d < 4; d++) {
            for (int k = 1; k < range; k++) {
                int ny = y+dy[d]*k;
                int nx = x+dx[d]*k;
                if (ny >=0 && ny < H && nx >= 0 && nx < W &&
                        grid[ny][nx] != 0) {
                    bomb(grid, ny, nx);
                }
            }
        }
    }

}

void cleanUp(int grid[MAXH][MAXW]) {
    for (int x = 0; x < W; x++) {
        for (int y = H-1; y >=0; y--) {
            if (!grid[y][x]) {
                for (int k = y-1; k >=0; k--) {
                    if (grid[k][x]) {
                        swap(grid[y][x], grid[k][x]);
                        break;
                    }
                }
            }
        }
    }
}

int getScore(int grid[MAXH][MAXW]) {
    int result = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (grid[y][x]) result++; 
        }
    }
    return result;
}


void dfs(int grid[MAXH][MAXW], int arr[4], int N, int depth) {
    if (depth == N) {
        int cgrid[MAXH][MAXW];
        for (int y = 0; y < H; y++)
            for (int x = 0; x < W; x++)
                cgrid[y][x] = grid[y][x];
        for (int i = 0; i < N; i++) {
            bomb(cgrid, getY(cgrid, arr[i]), arr[i]);
            cleanUp(cgrid);
        }
        minimum = min(minimum, getScore(cgrid));
        

    } else {
        for (int x = 0; x < W; x++) {
            arr[depth] = x;
            dfs(grid, arr, N, depth+1);
        }
    }
}


int main() {
    freopen("bricks_input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N >> W >> H;
        for (int y = 0; y < H; y++) 
            for (int x = 0; x < W; x++) 
                cin >> grid[y][x]; 
        minimum = 9999999;
        int arr[4] = {};
        dfs(grid, arr, N, 0);
        cout << "#" << tc+1 << " " << minimum << endl;
    }
    return 0;
}
