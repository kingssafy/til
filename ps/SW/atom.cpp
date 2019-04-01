#include <cstdio>
using namespace std;
const int MAX = 8001;
struct atom{
    bool moved;
    int d;
    int energy;
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
atom atoms[MAX][MAX] = {};

int main() {
    int T, N;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d", &N);
        int x, y, d, K;
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d %d", &x, &y, &d, &K);
            atoms[2*x+4000][2*y+4000].d = d;
            atoms[2*x+4000][2*y+4000].energy = K;
            atoms[2*x+4000][2*y+4000].moved = false;
        }
        int result = 0;
        for (int time = 0; time < 1000; time++) {
            for (int y = 0; y < MAX; y++) {
                for (int x = 0; x < MAX; x++) {
                    if (atoms[y][x].moved == false && atoms[y][x].energy) {
                        int ny = y+dy[y+atoms[y][x].d];
                        int nx = x+dx[x+atoms[y][x].d];
                        if (atoms[ny][nx].moved == true && atoms[ny][nx].energy) {
                            result += atoms[ny][nx].energy + atoms[y][x].energy;
                            atoms[y][x] = {0, 0, 0};
                            atoms[ny][nx] = {0,0,0};
                        } else {
                            atoms[ny][nx] = atoms[y][x];
                            atoms[ny][nx].moved = true;
                            atoms[y][x] = {0,0,0};
                        }
                    }
                }
            }
            for (int y = 0; y < MAX; y++)
                for (int x = 0; x < MAX; x++)
                    atoms[y][x].moved = false;
        }
        printf("%d\n", result);
 

    }
    
    return 0;
}
