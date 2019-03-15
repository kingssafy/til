#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        cout << "#" << tc+1 << " ";
        for (int i = 0; i < N; i++) {
            cout << 1 << "/" << N << " ";
        }
        cout << endl;
    }
}
