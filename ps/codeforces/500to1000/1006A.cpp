#include <iostream>
using namespace std;
int const MAXN = 1000;

int main() {
    int n;
    cin >> n;
    int temp;
    int arr[MAXN] = {};
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (!(temp%2)) {
            temp--;
        }
        arr[i] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
