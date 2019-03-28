#include <cstdio>
using namespace std;
int grid[10][10] = {};
int N;

int main() {
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &grid[y][x]);
        }
    }

    return 0;
}
