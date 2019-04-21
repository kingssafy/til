#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag = false;
    if (n % 2) {
        flag = true;
        n -= 3;
    }
    cout << n / 2 + flag << "\n";
    if (flag) {
        cout << "3 ";
    }
    for (int i = 0; i < n/2; i++) {
        cout << "2 ";
    }
    return 0;
}
