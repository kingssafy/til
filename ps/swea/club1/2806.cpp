#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;

    bool diagl[10] = {0};
    bool diagr[10] = {0};
    bool column[10] = {0};

    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        for (int i = 0; i < 10; i++) {
            diagl[i] = 0;
            diagr[i] = 0;
            column[i] = 0;
        }

    }
    return 0;
}
