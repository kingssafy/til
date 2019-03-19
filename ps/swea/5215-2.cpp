#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, N, L, s, c;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        bool h[10001] = {0};
        int o[10001] = {0};
        cin >> N >> L;
        h[0] = true;
        for (int i = 0; i < N; i++) {
            cin >> s >> c;
            for (int l = L - c; l >= 0; l--) {
                h[l+c] |= h[l];
                if (h[l+c]) {
                    o[l+c] = max(o[l+c], o[l] + s);
                }
            }
        }
        int result = 0;
        for (int i = 0; i <= L; i++) {
            result = max(result, o[i]);
        }
        cout << "#" << tc+1 << " " << result << endl;
    }




    return 0;
}
