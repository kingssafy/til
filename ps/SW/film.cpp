#include <iostream>
#include <fstream>

using namespace std;

bool check(bool grid[13][20], int D, int W, int K) {
    bool flag = false;
    for (int x = 0; x < W; x++) {
    int counter = 0;
        for (int y = 0; y < D; y++) {
            if (flag == grid[y][x]) {
                counter++;
                if (counter >= K) break;
            } else {
                flag = grid[y][x];
                counter = 1;
            }
            if (y == D-1) {
                return false;
            }
        }
    }
    return true; 
}

void bfs(int grid[13][20], int D, int W, int K) {
    int selected[10000][14] = {};
    int applied[14];
    int front = 0;
    int rear = 0;
    for (int i = 0; i < D; i++) {
        selected[rear][0] = i;
        selected[rear++][1] = -1;
    }
    while (front < rear) {
         
    }
    

}



int main() {
    ifstream cin("film_input.txt");
    int T, D, W, K;
    bool grid[13][20];
    bool crid[13][20];
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> D >> W >> K;
        for (int y = 0; y < D; y++) {
            for (int x = 0; x < W; x++) {
                cin >> grid[y][x];
            }
        }
        bool result = check(grid, D, W);
        cout << result << endl;
    }
    return 0;
}
