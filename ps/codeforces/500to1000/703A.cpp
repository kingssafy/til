#include <iostream>
using namespace std;

int main() {
    int n, a = 0, b = 0;
    int l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        if (l > r) a++;
        else if (l < r) b++;
    }
    if (a == b) {
        cout << "Friendship is magic!^^" << "\n";
    } else if (a > b) {
        cout << "Mishka" << "\n";
    } else {
        cout << "Chris" << "\n";
    }

    return 0;
}
