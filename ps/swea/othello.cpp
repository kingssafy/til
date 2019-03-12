#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
// up right down left upright, downright, downleft, upleft,
int dr[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dc[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool isvalid(int N, int r, int c) { 
    return 1 <= c && c <= N && 1 <= r && r <= N;
}

void othello(int grid[][9], int N, int c, int r, int team) {
    int j;
    grid[r][c] = team;
    for (int i = 0; i < 8; i++) {
        j = 1; 
        while (j <= N && isvalid(N, r+dr[i]*j, c+dc[i]*j) && grid[r+dr[i]*j][c+dc[i]*j] != 0 && grid[r+dr[i]*j][c+dc[i*j]] !=team) {
        j++;
        }
        if (isvalid(N, r+dr[i]*j, c+dc[i]*j) && grid[r+dr[i]*j][c+dc[i]*j] == team) {
            for (int temp = j; j > 0; j--) {
                grid[r+dr[i]*temp][c+dc[i]*temp] =team; 
            }
        } 
}
}

int main(void) {
    ifstream input;
    input.open("othello_input.txt");

    int T;
    int c, r, team, N, M;
    int grid[9][9];
    input >> T;
    int black, white;
    
    for (int i = 0; i < T; i++) {
        input >> N >> M;
        for (int a = 1; a <= 8; a++) {
            for(int b = 1; b <= 8; b++) {
                grid[a][b] = 0;
            }
        }
        int a = N/2;
        grid[a][a] = 1;
        grid[a][a+1] = 2;
        grid[a+1][a+1] = 1;
        grid[a+1][a] = 2;

        for (int j = 0; j < M; j++) {
            input >> c >> r >> team;
            grid[r][c] = team;
            othello(grid, N, c, r, team); 
        }
        black = 0;
        white = 0;

        for (int s = 1; s <= N; s++) {
            for (int q =1; q <= N; q++) {
                if (grid[s][q] == 1) white++;
                if (grid[s][q] == 2) black++;
            }
        }
        cout << black << white;

        
    }


    return 0;
}
