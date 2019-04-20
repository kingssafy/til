#include <cstdio>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int const MAXR = 51, MAXC = 51;
int tempy;
int cleany[5];
int cleanx[5];
int grid[MAXR][MAXC] = {};
int R, C, T;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void step1() {
    int next[MAXR][MAXC] = {};
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (grid[y][x] > 0) {
                int spreaded = 0;
                for (int i = 0; i < 4; i++) {
                    int ny = y+dy[i];
                    int nx = x+dx[i];
                    if (ny < 0 || nx < 0 || ny >= R || nx >=R || grid[ny][nx] == -1) continue;
                    next[ny][nx] += grid[y][x]/5;
                    spreaded += grid[y][x]/5;
                } 
                next[y][x] += grid[y][x] - spreaded;
            } else if (grid[y][x] == -1) {
                next[y][x] = grid[y][x];
            }
        }
    } 
    for (int y = 0; y < R; y++)
        for (int x = 0; x < C; x++) {
            grid[y][x] = next[y][x];
        }
}

void step() {
    for (int y = tempy-1-1; y > 0; y++) {
        grid[y][0] = grid[y-1][0];
    }
    for (int x = 0; x < C-1; x++) {
        grid[0][x] = grid[0][x+1];
    }
    for (int y = 0; y < tempy-1 - 1; y++) {
        grid[C][y] = grid[C][y+1];
    }
    for (int x = C; x >= 2; x--) {
        grid[tempy-1][x] = grid[tempy-1][x-1];
    }
    grid[cleany[0]][0+1] = 0;
    for (int y = tempy+1; y < R-1; y++)
        grid[y][0] = grid[y+1][0];
    for (int x = 0; x < C-1; x++) 
        grid[R][x] = grid[R][x+1];
    for (int y = tempy+1; y < R; y++) {
        grid[R][y] = grid[R][y-1];
    }
    for (int x = 2; x < C; x++)
        grid[tempy][x] = grid[tempy][x-1];
    grid[tempy][1] = 0;
}
int main() {
    scanf("%d %d %d", &R, &C, &T);
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> grid[y][x];
        }
    }

    for (int i = 0; i < T; i++) {
        step1();step();
    }
    int ans = 0;
    for (int y = 0; y < R; y++) {
        for(int x = 0; x < C; x++) {
            if(grid[y][x] > 0) ans+= grid[y][x];
        }
    }
    printf("%d\n", ans);
    return 0;
}
