#include <iostream>
#include <cstdio>

using namespace std;
bool column[10] = {};
bool diag1[10] = {};
bool diag2[10] = {};


int nqueens(int k, int N) {
    if (K == N) {

    }  else {
        for (int i = 0; i < N; i++) {
            if (!column[i] && !diag1[k-i+1] && !diag2(N-1+i-k)) {

            }
        } 
    }
}



int main() {
    int N;
    scanf("%d", &N);
    nqueens(N);
    return 0;
}
