#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        if (n%10) {
            n--;
        } else {
            n /= 10;
        }
    }
    cout << n << "\n";
    return 0;
}
