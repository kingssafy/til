#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    char before = 'o';
    char now;
    int counter = 1;
    for (int i = 0; i < n; i++) {
        cin >> now;
        if (before == 'x' && now == 'x') {
            counter++;
        } else if (now != 'x') counter = 1;

        if (counter > 2) ans++;
        before = now;
    }
    cout << ans << "\n";

    return 0;
}
