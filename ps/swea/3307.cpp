#include <iostream>
using namespace std;

int main() {
    int T, N, temp;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        int array[1000] = {};
        int length[1000] = { [0 ... 999] = 1 };
        for (int i = 0; i < N; i++) {
            cin >> temp;
            array[i] = temp;
        }
        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int k = i-1; k >= 0; k--) {
                if (array[k] <= array[i]) {
                    length[i] = max(length[i], length[k]+1);
                    result = max(result, length[i]);
                }
            }
        }
        cout << "#" << tc+1 << " " << result;
    }
    using namespace std;
}
