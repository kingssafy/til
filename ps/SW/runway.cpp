#include <iostream>
#include <cstdio>
using namespace std;
int grid[20][20] = {};
int N, X;

bool check(int arr[]) {
    int before = arr[0];
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (before == arr[i]) {
            count ++;
        } else if (before+1 == arr[i]) {
            if (count >= X) {
                count = 1;
                before = arr[i];
            } else {
                return false;
            }
        } else {
            if (i+X > N) return false;  //gives me pass ;;
            int checker = before - 1;
            for (int j = 0; j < X; j++) {
                if (arr[i+j] != checker) {
                    return false;
                }
            }
            count = -X+1;  // -x+1 ->30 48
            before = arr[i];
        } 
    } 
    return true;
}


int main() {
    freopen("runway_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d", &N, &X);
        for (int y = 0; y < N; y++)
            for (int x = 0; x <N; x++)
                scanf("%d", &grid[y][x]);
        
        int result = 0;
        for (int y = 0; y < N; y++) {
            result += check(grid[y]);
        }
        for (int y = 0; y < N; y++) {
            int arr[20] = {};
            for (int x = 0; x < N; x++) {
                arr[x] = grid[x][y];
            }
            result += check(arr);
        }
        printf("#%d %d\n", tc+1, result);

    }
    return 0;
}
