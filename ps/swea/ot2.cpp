#include <iostream>
#include <stdio.h>
#include <fstream>
#define black 1
#define white 2
using namespace std;
ifstream input("othello_input.txt");

int direction[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
using namespace std;
int board[10][10] = {{ 0 }};

void init(int N) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }
    N = N/2;
    board[N][N] = white;
    board[N+1][N+1] = white;
    board[N+1][N] = black;
    board[N][N+1] = black;
}

void findSameColor(int curh, int curw, int color, int N) {
    int nexh, nexw;
    bool find = false;
    for (int dir = 0; dir < 8; dir++) {
        nexw = curw + direction[dir][0];
        nexh = curh + direction[dir][1];
        while (nexw>0 && nexh>0 && nexw<=N && nexh <=N) {
            if (board[nexw][nexh] == 0) {
                break;
            } else if (board[nexw][nexh] == color) {
                find = true; 
                break;
            }
            nexw += direction[dir][0];
            nexh += direction[dir][1];
        }
        if (find == true) {
            nexw -= direction[dir][0];
            nexh -= direction[dir][1];
            while (nexw != curw || nexh != curh) {
                board[nexw][nexh] = color;
                nexw -= direction[dir][0];
                nexh -= direction[dir][1];
            }
        }
        find =false;
    }
}

int main() {
    int TC;
    input >> TC;
    for (int test = 1; test <=TC; test++) {
        int N, M;
        input >> N >> M;
        init(N);
        int hei, wei, color;
        for (int i = 0; i < M; i++) {
            input >> hei >> wei >> color;
            board[wei][hei] = color;
            findSameColor(hei, wei, color, N);
        }
        int countb = 0, countw = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[i][j] == black) countb++;
                else if(board[i][j] == white) countw++;
            }
        }
        printf("#%d %d %d\n", test, countb, countw);
    }
    return 0;
}
