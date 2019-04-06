#include <stdio.h>
const int MAXDSIZE = 13;
const int MAXWSIZE = 20;
int D, W, K;
int minChemicalCnt;
int chemical[MAXDSIZE];
int film[MAXDSIZE][MAXWSIZE];


void solve(int curD, int chemicalCnt, int prevContinuum[MAXWSIZE], int prevMaxContinuum[MAXWSIZE]) {

    if (chemicalCnt >= minChemicalCnt) return;
    if (curD == D) {
        bool isSatisfied = true;
        for (int i = 0; i < W; i++) {
            if (prevMaxContinuum[i] < K) {
                isSatisfied = false;
                break;
            }
        }
        if (isSatisfied && chemicalCnt < minChemicalCnt) {
            minChemicalCnt = chemicalCnt;
        } 
    } else {
        int continuum[MAXWSIZE], maxContinuum[MAXWSIZE];
        int prev, cur;
        for (int i = 2; i >=0; i--) {
            chemical[curD] = i;
            for (int j = 0; j < W; j++) {
                cur = chemical[curD] == 2 ? film[curD][j] : chemical[curD];
                prev = chemical[curD-1] == 2 ? film[curD-1][j] : chemical[curD-1];
                continuum[j] = cur == prev ? prevContinuum[j]+1 : 1;
                if (continuum[j] > prevMaxContinuum[j]) {
                    maxContinuum[j] = continuum[j];
                } else {
                    maxContinuum[j] = prevMaxContinuum[j];
                }
            }
            solve(curD + 1, chemicalCnt + (i == 2 ? 0 : 1), continuum, maxContinuum);
        }

    }
}

int main() {
    freopen("film_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d %d", &D, &W, &K);
        for (int y = 0; y < D; y++) {
            for (int x = 0 ; x < W; x++) {
                scanf("%d", &film[y][x]);
            }
        }
        minChemicalCnt = K;
        int continuum[MAXWSIZE], maxContinuum[MAXWSIZE];
        for (int i = 0; i < W; i++) {
            continuum[i] = maxContinuum[i] = 1;
        }
        chemical[0] = 2;
        solve(1, 0, continuum, maxContinuum);

        chemical[0] = 1;
        solve(1, 1, continuum, maxContinuum);

        chemical[0] = 0;
        solve(1, 1, continuum, maxContinuum);
        printf("#%d %d\n", tc+1, minChemicalCnt);
    }
    return 0;
}
