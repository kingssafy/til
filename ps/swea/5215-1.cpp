#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("5215.txt");
    int T, N, L, s, c;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        bool possible[10001] = {false};
        int maxscore[10001] = {false};
        cin >> N >> L;
        possible[0] = true;
        for (int i = 0; i < N; i++) {
            cin >> s >> c;
            for (int l = L - c; l >= 0; l--) {
                possible[l+c] |= possible[l];
                if (possible[l+c]) {
                    maxscore[l+c] = max(maxscore[l+c], maxscore[l] + s);
                }
            }
        }
        int result = 0;
        for (int i = 0; i <= L; i++) {
            result = max(result, maxscore[i]);
        }
        cout << "#" << tc+1 << " " << result << endl;
    }




    return 0;
}
