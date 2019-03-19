#include <iostream>
#define ll long long int
using namespace std;

ll power(ll n, ll p) {
    ll result = 1LL;
    for (ll i = 0; i < p; i++)
        {result = result*n;}
    return result;
}

ll bintod(ll binary) {
    ll result = 0LL;
    for (ll i = 38LL; i >= 0; i--) {
        if ((1LLU<<i)&binary) {
            result += power(2LL, i);
            cout << result;
        }
    }
    return result;
}
int main() {
    int T;
    ll binary = 0LL, ternary = 0LL;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> binary >> ternary;
        ll result = bintod(binary);
        cout << result;
    }

    return 0;
}
