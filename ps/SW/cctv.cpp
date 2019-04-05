#include <cstdio>
const int MAXSIZE = 8;
using namespace std;
struct P {
    int y;
    int x;
};
P cctvs[8] = {};
void ff(int sy, int sx, int d) {
    for (int i = 0; i < 8; i++) {
         
    } 
}


const P end = {-1,-1};
P sights[8][4][20] = {}; // #cctv, #directions, #coordinates
int grid[MAXSIZE][MAXSIZE];
int Y, X;
int CCTV = 0;
int main() {
    scanf("%d %d", &Y, &X);
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            scanf("%d", &grid[y][x]);
        }
    }
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (grid[y][x] != 6 && grid[y][x] != 0) {
                 
            }
        }
    }

    
     

    return 0;
}
