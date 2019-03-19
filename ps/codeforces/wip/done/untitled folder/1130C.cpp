//1130C
//INMAK
//feel free to contact me jchrys@me.com


#include <iostream>
#include <cstdio>

using namespace std;
struct P {
    int x, y; 
};
int cost(P s, P e) {
    int y = s.y - e.y;
    int x = s.x - e.x;
    return y*y + x*x;
}
int dy[4] = {-1, 1, 0, 0}; //up, down right, left
int dx[4] = {0, 0, 1, -1};
int counter = 1;

bool visited[51][51] = { {false} };
bool ingrid(P p, int n) {
    return (max(p.x, p.y) < n && min(p.x, p.y) >= 0);
}

void dfs(int grid[][50], int n, P start, P starts[2501]) {
    if (visited[start.y][start.x]) return;
    visited[start.y][start.x] = true;
    P next;
    for (int d = 0; d < 4; d++) {
        next.x = start.x + dx[d];
        next.y = start.y + dy[d];
        if (ingrid(next, n) && grid[next.y][next.x] == 0 && !visited[next.y][next.x]) {
            starts[counter] = next;
            counter++;
            dfs(grid, n, next, starts);
        }
    }
}

int main() {
    int n, r1, c1, r2, c2, grid[50][50];
    cin >> n >> r1 >> c1 >> r2 >> c2; 
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%1d", &grid[y][x]);
        }
    }
    r1 -= 1;
    c1 -= 1;
    r2 -= 1;
    c2 -= 1;
    P start, end;
    start.y = r1;
    start.x = c1;
    end.y = r2;
    end.x = c2;
    P starts[2501], ends[2501];
    starts[0] = start;
    ends[0] = end;
    dfs(grid, n, start, starts);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            visited[y][x] = 0;
        }
    }
    int startcounter = counter;
    counter = 1;
    dfs(grid, n, end, ends);
    int endcounter = counter;
    int result = 21000000;
    for (int i = 0; i < startcounter; i++) {
        P s = starts[i];
        for (int j = 0; j <endcounter; j++) {
            P e = ends[j]; 
            result = min(result, cost(s, e));
        }
    }
    cout << result;

    return 0;
}
