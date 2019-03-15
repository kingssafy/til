#include <iostream>
using namespace std;

int solve(int coins[3], int N);

int solveHelper(int coins[], int size, int N, bool ready[], int value[]) {
    if (N < 0) return 99999;
    if (N == 0) return 0;
    if (ready[N]) return value[N];
    int best = 99999;
    for (int i = 0; i < size; i++) {
        best = min(best, solve(coins, N-coins[i]) + 1);
    }
    value[N] = best;
    ready[N] = true;
    return best;
}

int solve(int coins[3], int N) {
    bool ready[1001] = {};
    int value[1001] = {};
    int size = 3;
    return solveHelper(coins, size, N, ready, value); 
}


int main() {
    int coins[3] = {1, 3, 4};
    int N = 35;
    int result = solve(coins, N);
    cout << result << endl;

    return 0;
}
