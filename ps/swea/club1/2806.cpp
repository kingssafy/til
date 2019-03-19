#include <iostream>
#include <fstream>
using namespace std;

void search(int depth, int N, int& result, bool column[20], bool diagl[20], bool diagr[20]) {
    if (depth == N) {
        result ++;
        return;
    } 
    for (int x = 0; x < N; x++) {
        if (column[x] || diagl[x+depth] || diagr[N-1+x-depth]) continue;
        column[x] = diagl[x+depth] = diagr[N-1+x-depth] = 1;
        search(depth +1, N, result, column, diagl, diagr);
        column[x] = diagl[x+depth] = diagr[N-1+x-depth] = 0; 
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;

    bool diagl[20] = {0};
    bool diagr[20] = {0};
    bool column[20] = {0};
    int result = 0;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        result = 0;
        for (int i = 0; i < 20; i++) {
            diagl[i] = 0;
            diagr[i] = 0;
            column[i] = 0;
        }
        search(0, N, result, column, diagl, diagr);
        cout << "#"<< tc+1 << " " << result << endl; 
    }

    return 0;
}
