#include <iostream>
#include <cstdio>
const int MAX= 100;

using namespace std;
int X, Y, H;
int grid[MAX][MAX][MAX] = {};
int nextgrid[MAX][MAX][MAX] = {};
int dh[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dx[6] = {0, 0, -1, 1, 0, 0};

int day() {
    int done = 0;
    for (int h = 0; h < H; h++) {
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                if (grid[h][y][x] == 0) {
                    for (int i = 0; i < 6; i++) {
                        int nh = h+dh[i];
                        int ny = y+dy[i];
                        int nx = x+dx[i];
                        if (nh >= 0 && ny >= 0 && nx >= 0 && nh < H && ny < Y && nx < X && grid[nh][ny][nx] == 1) {
                            nextgrid[h][y][x] = 1;
                            done++;
                            break;
                        }
                        nextgrid[h][y][x] = grid[h][y][x];
                    }
                } else {

                nextgrid[h][y][x] = grid[h][y][x];
                }
            }
        }
    }
    for(int h = 0; h < H; h++) 
        for(int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++) {
                grid[h][y][x] = nextgrid[h][y][x];
            }
    return done;

}

int main() {
    int temp;
    int left = 0;
    scanf("%d %d %d", &X, &Y, &H);
    for (int h = 0; h < H; h++)
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++) {
                scanf("%d", &temp);
                grid[h][y][x] = temp;
                if (temp == 0) left++;
            }
    int days = 0;
    int before = -1;
    int flag =1;
    if (left == 0) {
        printf("0\n");
    } else { 
        while (left != 0 && flag) {
            days++;
            left -= day();
            if (left == before) {
                flag = 0;
            }
            before = left;
        }
    if (flag == 0) {
        printf("-1");
    } else {
        printf("%d", days);
    }
    }


    //    for(int h = 0; h < H; h++) {
    //        for (int y = 0; y < Y; y++) {
    //            for (int x = 0; x < X; x++) {
    //                printf("%d ", grid[h][y][x]);
    //            }
    //            printf("\n");
    //        }
    //        printf("\n");
    //    }

    return 0;
}
