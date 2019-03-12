#include <iostream>
#include <fstream>
using namespace std;

ifstream input("least_sum_input.txt");
int ammax = 9999999;
void leastSumHelper(int grid[][10], int k, int N, bool subset[10], int current) {
    if (current > ammax) { return; }
    if (k == N) {
        //TODO
        if (current <  ammax) { ammax = current;}
    } else {
        for(int j = 0; j <N; j++) {
            if (subset[j]) {
                continue;
            } else {
                subset[j] = true;  
                leastSumHelper(grid, k+1, N, subset, current+grid[k][j]);
                subset[j] = false;
            }
        }
    }
}

void leastSum(int grid[10][10], int N) {
    bool subset[10] = {};
    for (int i = 0; i < 10; i++) {
        subset[i] = false;
    }
    leastSumHelper(grid, 0, N, subset, 0);
    
}


int main(void) {
    int T, N;
    input >> T;
    for (int i = 0; i < T; i++) {
    input >> N;
    int grid[10][10];
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            input >> grid[r][c];
        }
    }
    ammax = 999999;
    leastSum(grid, N);
    cout << "#"<< i+1 << " " << ammax << endl;
    }

    
    return 0;
}
