#include <iostream>
using namespace std;
int const MAXN = 101;
int main() {
    int n, m;
    cin >> n >> m;
    int arr[MAXN] = {};
    for (int i = 0; i < n; i++) {
        int l;
        int r;
        cin >> l >> r;
        for (int j = l; j <= r; j++) {
            arr[j] = 1;
        }
    }
    int counter = 0;
    for (int i = 1; i <= m; i++) {
        if (arr[i] == 0) {
            counter++;
        }
    }
    cout << counter << "\n";
    for (int i = 1; i <= m; i++) {
        if (arr[i] ==0 ) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}
