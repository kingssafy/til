#include <iostream>
using namespace std;

int result = 0;
void search(int N, int depth, bool diag1[],bool diag2[], bool col[]) {
    if (N == depth) {
        result++;
    } else {
        for (int i = 1; i <= N; i++) {
            if (diag1[N-depth+i] || diag2[i+depth] || col[i]) continue;
            col[i] = diag1[N-depth+i] = diag2[i+depth] = true;
            search(N, depth+1, diag1, diag2, col);
            col[i] = diag1[N-depth+i] = diag2[i+depth] = false;
        }
    }
}


int main() {
    int T, N; 
    bool diag1[21]={false}, diag2[21]={false}, col[11] ={false};
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            diag1[i] = 0;
            diag2[i] = 0;
            col[i] = 0;
        }
        result = 0;
        search(N, 0, diag1, diag2, col);
        cout << "#" << tc+1 << " " << result << endl;
    }
}
