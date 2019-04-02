#include <iostream>
using namespace std;
const int Y=400, X=400;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
struct cell{
    int maxHp;
    int hp;
    int status;
};
cell grid[Y][X];
void hour() {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (grid[y][x].status == 0 || grid[y][x].status == 1) continue;
            grid[y][x].hp--;
            if (grid[y][x].hp == -1) {
                //TODO spread
                for (int i = 0; i < 4; i++) {
                    int ny = y+dy[i];
                    int nx = x+dx[i];
                    if(grid[ny][nx].maxHp == grid[ny][nx].hp && grid[ny][nx].maxHp < grid[y][x].maxHp) {
                        grid[ny][nx].maxHp = grid[ny][nx].hp = ny > y || nx > x ? grid[y][x].maxHp + 1 :grid[y][x].maxHp ;
                        grid[ny][nx].status = 3;
                    }
                }
            }
            if (grid[y][x].hp == 0) grid[y][x].status = 2;
            if (grid[y][x].hp == -grid[y][x].maxHp) {
                //TODO dead
                grid[y][x].status = 1;
            }

        }
    }

    for( int y = 0; y < 40; y++ ) {

        for (int x = 0; x < 40; x++) {
            cout << grid[160+y][160+x].status << " ";
        }
        cout << endl;
    }
    cout << endl;


}

int getResult() {
    int result = 0;
    for(int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            if (grid[y][x].status >= 2) result++;

    return result;
}


int main() {
    freopen("cell_input.txt", "r", stdin);
    int T, N, M, K, temp; 
    cin >> T;
    for(int tc = 0; tc < 1; tc++) {
        cin >> N >> M >> K;
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++)
                grid[y][x] = {0, 0, 0};
        for (int y = 0; y < N; y++)
            for (int x = 0; x < M; x++) {
                cin >> temp;
                if (temp == 0) continue; //this thing resolves the problem
                grid[175+y][175+x].maxHp = temp;
                grid[175+y][175+x].hp = temp;
                grid[175+y][175+x].status = 3;
            }
        for (int i = 0; i < K; i++) {
            hour();
        }
        int result = getResult();
        cout << "#" << tc+1 << " " << result << endl;



    }


    return 0;
}
