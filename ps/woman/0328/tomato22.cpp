#include <iostream>
using namespace std;
const int MAX=100;
int grid[MAX+1][MAX+1] = {};
int nextgrid[MAX+1][MAX+1] = {};
int Y, X, togo = 0;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int day(void) {
    int temp;
    int ny, nx;
    int hm =0;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            temp = grid[y][x];
            if (temp == 0) {
                for (int i = 0; i < 4; i++) {
                    ny = y+dy[i];
                    nx = x+dx[i];
                    if (ny >=0 && ny < Y && nx >=0 && nx < X && grid[ny][nx] ==1 && grid[y][x] == 0) {
                        nextgrid[y][x] = 1;
                        hm++;
                        break;
                    } else  {
                        nextgrid[y][x] = temp;
                    }
                }
            } else {
                nextgrid[y][x] = temp;
            } 
        }
    }
    for (int y = 0; y < Y; y++) {

        for (int x = 0; x < X; x++) {
            grid[y][x] = nextgrid[y][x];
        }
    }
    
    return hm;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X >> Y;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            cin >> grid[y][x];
            if (grid[y][x] == 0) togo++; 
        }
    }
    int days = 0;
    int before = -1;
    int flag =1;
    while (togo != 0 && flag) {
        days++;
        togo -= day();
        if (togo == before) {
            flag = 0;
        }
        before = togo;
    }
    if (flag == 0) {
        cout << -1;
    } else {
        cout << days;
    }
     

    
    
    


    return 0;
}
