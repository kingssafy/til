#include <iostream>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int temp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp > h) ans++;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
