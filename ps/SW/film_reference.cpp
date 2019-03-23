#include <stdio.h>
// W width, D Depth
// K  minimum required
const int DSIZE = 13;
const int WSIZE = 20;
int D, W, K;


//film : 2dimensional array
//minChemicalCnt
//Chemical: record what kind of chemical applied
// 0 -> A, 1 -> B, 2 -> do nothing
int film[DSIZE][WSIZE];
int minChemicalCnt;
int chemical[DSIZE];

//solve: function for solve problem recursively;
//curD: time to check d th film;
//chemicalCnt: the number of chemical applied until now;
//prevContinuum
//prevMaxContinuum
void solve(int curD, int chemicalCnt, int prevContinuum[WSIZE], int prevMaxContinuum[WSIZE]) {

    if (chemicalCnt >= minChemicalCnt) return;
    //basecase
    //done with all layers of film
    if (curD == D) {
        //check if it satisfies restraint
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
        return;
    }

    int continuum[WSIZE], maxContinuum[WSIZE];
    int prev, cur;

    // 2 -> 1 -> 0;
    for (int i = 2; i >=0; i--) {

        chemical[curD] = i;
        //search entire grid horizontally
        for (int j = 0; j < W; j++) {
            //cur : current layer's cell's status
            //prev: previus layer's cell's status
            cur = chemical[curD] == 2 ? film[curD][j] : chemical[curD];
            prev = chemical[curD-1] == 2 ? film[curD-1][j] : chemical[curD-1];

            continuum[j] = cur == prev ? prevContinuum[j]+1 : 1;

            if(continuum[j] > prevMaxContinuum[j]) maxContinuum[j] = continuum[j];
            else maxContinuum[j] = prevMaxContinuum[j];
        }
        solve(curD +1, chemicalCnt + (i == 2 ? 0: 1), continuum, maxContinuum);
    }

}



int main() {
    freopen("film_input.txt", "r", stdin);
    int test_case;
    scanf("%d", &test_case);

    for (int tc = 1; tc <= test_case; tc++) {
        scanf("%d %d %d", &D, &W, &K);
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%d", &film[i][j]);
            }
        }

        minChemicalCnt = K;
        //continuum
        //maxContinuum
        int continuum[WSIZE], maxContinuum[WSIZE];
        for (int i = 0; i < W; i++) {
            continuum[i] = maxContinuum[i] = 1;
        }

        // do nothing on 0th film;
        chemical[0] = 2;
        solve(1, 0, continuum, maxContinuum);

        chemical[0] = 1;
        solve(1, 1, continuum, maxContinuum);

        chemical[0] = 0; // priviously chemical[0]=1; --> fail
        solve(1, 1, continuum, maxContinuum);

            printf("#%d %d\n", tc, minChemicalCnt);
    }
    return 0;
}
