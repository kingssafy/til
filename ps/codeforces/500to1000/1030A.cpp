#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    bool ans = 0;
    for (int i = 0; i < n; i++) {
        bool temp;
        cin >> temp;
        ans |= temp;
    }
    if (ans) {
        cout << "HARD" << endl;
    } else {
        cout << "EASY" << endl;
    }

    return 0;
}
