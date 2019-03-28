#include <iostream>
#include <cstdio>

using namespace std;
bool column[10] = {};
bool diag1[20] = {};
bool diag2[20] = {};
int ret = 0;

void nqueens(int k, int N) {
    if (k == N) {
        ret += 1;
    }  else {
        for (int i = 0; i < N; i++) {
            if (!column[i] && !diag1[N-k+i] && !diag2[i+k]) {
                column[i] = diag1[N-k+i] = diag2[i+k] = true;   
                nqueens(k+1, N);
                column[i] = diag1[N-k+i] = diag2[i+k] = false;   
            }
        } 
    }
}



int main() {
    int N;
    scanf("%d", &N);
    nqueens(0, N);
    printf("%d", ret);
    return 0;
}
