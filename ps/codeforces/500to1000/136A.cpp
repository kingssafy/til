#include <iostream>
using namespace std;

int main() {
    int const MAXN = 101;
    int n;
    cin >> n;
    int ans[MAXN] = {};
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp; 
        ans[temp] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
