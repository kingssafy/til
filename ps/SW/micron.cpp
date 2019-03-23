#include <iostream>
#include <fstream>
using namespace std;
struct gridder {
    int cnt;
    int dir;
    int maxCnt;
};
int N, M, K;
gridder grid[100][100] = {};
gridder nextgrid[100][100] = {};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void move() {
    for (int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            if (grid[y][x].cnt > 0) {
                int dele = grid[y][x].dir;
                int ny = y+dy[dele];
                int nx = x+dx[dele];
                if (min(ny, nx) == 0 || max(ny, nx) == N-1) { // max(ny, nx) == N gave me wrong answer so sad...
                    grid[y][x].cnt = grid[y][x].cnt/2;
                    grid[y][x].dir = (grid[y][x].dir+2)%4;}
                if (nextgrid[ny][nx].maxCnt == 0) {
                    nextgrid[ny][nx].cnt = grid[y][x].cnt;
                    nextgrid[ny][nx].dir = grid[y][x].dir;
                    nextgrid[ny][nx].maxCnt = grid[y][x].cnt;
                    
                } else if (nextgrid[ny][nx].maxCnt > 0) {
                    if(grid[y][x].cnt > nextgrid[ny][nx].maxCnt) {
                        nextgrid[ny][nx].cnt += grid[y][x].cnt;
                        nextgrid[ny][nx].dir = grid[y][x].dir;
                        nextgrid[ny][nx].maxCnt = grid[y][x].cnt;
                    } else {
                        nextgrid[ny][nx].cnt += grid[y][x].cnt;
                    }
                }
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            grid[y][x] = nextgrid[y][x];
            nextgrid[y][x] = {0,0,0};
        }
    }
}

int getAnswer() {
    int ret = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            ret += grid[y][x].cnt; 
        }
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("micron_input.txt");
    int T; 
    int tempY, tempX, tempCnt, tempDir;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N >> M >> K;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                grid[y][x] = {0, 0, 0};
            }
        }
        for (int i = 0; i < K; i++) {
           cin >> tempY >> tempX >> tempCnt >> tempDir; 
           if (tempDir == 1) {
               tempDir = 0;
           } else if (tempDir == 2) {
               tempDir = 2;
           } else if (tempDir == 3) {
                tempDir = 3;
           } else {
               tempDir = 1;
           }
           grid[tempY][tempX] = {tempCnt, tempDir, 0};
        } 


        
        for (int i = 0; i < M; i++) {
            move();
        }
        cout << "#" << tc+1 << " " << getAnswer() << endl;
    }
    return 0;
}
