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
        } else if (before < arr[i]) {
            if (count >= X) {
                count = 0;
                before = arr[i];
            } else {
                //TODO false!
            }
        } else {
            int checker = before -1;
            int downcount = 0;
            for (int j = 0; j < X; j++) {
               //TODO when goes down  
            }
        } 
    } 
}


int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d", &N, &X);
        for (int y = 0; y < N; y++)
            for (int x = 0; x <N; x++)
                scanf("%d", &grid[y][x]);


    }
    return 0;
}
