#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int l = 0; l < t; l++) {
        ll a, b, k;
        cin >> a >> b >> k;
        ll ans = 0;
        ans += (k/2) * (a-b);
        if (k%2) {
            ans += a;
        }
        cout << ans << "\n";
    }

    return 0;
}
