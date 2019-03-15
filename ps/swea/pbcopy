#include <iostream>
using namespace std;

int main() {
    int T, N;
    int input, temp, max;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        max = 0;
        temp = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> input;
            temp += input;
            if (temp > max) {
                max = temp;
            } else if (temp < 0) {
                temp = 0;
            }
        }
    cout << "#" << tc << " " << max << endl;
    }
    return 0;
}
