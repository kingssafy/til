#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << "I hate";
    for (int i = 0; i < n - 1; i++) {
        if (i%2) {
            cout << " that I hate";
        } else {
            cout << " that I love";
        }
    }
    cout << " it";

    return 0;
}
