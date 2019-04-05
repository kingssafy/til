#include <iostream>
using namespace std;
const int SIZE = 20;
int Y, X, sy, sx, K;
int grid[SIZE][SIZE];
int dice[4][3] = {};
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

void right() {
    int temp = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = dice[3][1];
    dice[3][1] = dice[1][2];
    dice[1][2] = temp;
}
void up() {
    int temp = dice[0][1];
    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = temp;
}

void left() {
    right();
    right();
    right();
}
void down() {
    up();
    up();
    up();
}
void floor(int y, int x) {
    // dice bottom >> dice[1][3]
    int temp = grid[y][x];
    if (temp == 0) {
        grid[y][x] = dice[3][1]; 
    } else {
        dice[3][1] = temp;
        grid[y][x] = 0;
    }
}
void printTop() {
    cout << dice[1][1] << endl;
}

int main() {
//    freopen("roll_input.txt", "r", stdin);
    int temp;
    cin >> Y >> X >> sx >> sy >> K;
//    cout << "Y: " << Y << " X: " << X << endl;
    //cout << K << endl;
    //cout << "y: " << sy << " x: " << sx << endl;
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            cin >> grid[y][x];
    for (int i = 0; i < K; i++) {
        cin >> temp;
//        cout << "y: " << sy << " x: " << sx << endl;
//        cout << "temp" << temp << endl;
        int ny = sy+dy[temp];
        int nx = sx+dx[temp];
//        cout << "ny: " << ny << " nx: " << nx << endl;
        if (ny < 0 || nx < 0 || ny >= Y || nx >= X) continue;
        if (temp == 1) right();
        if (temp == 2) left();
        if (temp == 3) up();
        if (temp == 4) down();
        sy = ny;
        sx = nx;
        floor(sy, sx);
        printTop();
    }

    return 0;
}
