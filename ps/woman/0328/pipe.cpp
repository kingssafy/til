#include <cstdio>

const int MAX = 10;

int N;
int grid[MAX][MAX] = {};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int pipes[13][4] = {
    {0,0,0,0},
    {0,1,0,1},
    {1,0,1,0},
    {0,1,1,0},
    {0,0,1,1},
    {1,0,0,1},
    {1,1,0,0},
    {1,1,1,0},
    {0,1,1,1},
    {1,0,1,1},
    {1,1,0,1},
    {1,1,1,1},
};



int main() {
    int sy, sx;
    scanf("%d", &N);
    scanf("%d %d", &sy, &sx);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%1x", &grid[y][x]);
    
    return 0;
}
