#include <iostream>
using namespace std;
const int MAXN = 15;
int grid[MAXN][2];
int N;
int result = 0;

int dp() {
    int arr[MAXN] = {};
    int result = 0;
    for (int i = N-1; i >= 0; i--) {
        int temp = 0; 
        for (int j = i+grid[i][0]; j < N; j++) {
            //cout << j << endl;
            temp = max(temp, arr[j]);
        }
        arr[i] = temp + (grid[i][0]+i <= N ? grid[i][1] : 0);
        //cout << "whee" << endl;
        result = max(result, arr[i]);
    }
    return result;
}

int main() {
    freopen("counsel_input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> grid[i][j];
        } 
    }
    cout << dp() << endl;
    return 0;
}
