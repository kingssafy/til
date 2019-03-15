#include <iostream>
#include <fstream>
using namespace std;

int thesum(int grid[5][20], int a, int b, int x, int y) {
    if (a == 0 && b == 0) { return grid[x][y];}
    
    return thesum(grid, 0, 0, x, y) - thesum(grid, 0, 0, x, b) - thesum(grid, 0, 0, a,y) + thesum(grid, 0, 0, a, b);
}
void makesumq(int grid[][20]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 20; c++) {
            if (r==0 && c == 0) {
                continue;
            } else if (r == 0) {
                grid[r][c] += grid[r][c-1];
            } else if (c == 0) {
                grid[r][c] += grid[r-1][c];
            } else {
                grid[r][c] += -grid[r-1][c-1] + grid[r-1][c] + grid[r][c-1];
            }
        }
    }
}
void print(int grid[][20]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 20; c++) {
            cout << grid[r][c] << " "; 
        }
        cout << endl;
    }
}
int main() {
    ifstream cin("100array.txt");
    int N, grid[5][20];
    cin >> N;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 20; x++) {
            cin >> grid[y][x];
        }
    } 
    
    print(grid);
    cout << endl;
    makesumq(grid);
    cout << endl;
    print(grid);
    cout << thesum(grid, 0, 1, 3, 3);


    return 0;
}
