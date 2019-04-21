#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll const mod = 1e9+7;
ll f(ll x) {
    ll ans = 0, even = 0, odd = 0;
    ll e = 0;
    ll cur = 1;
    while (x > 0) {
        if (e%2) {
            even += min(x, cur);
            even %= mod;
        } else {
            odd += min(x, cur);
            odd %= mod;
        }
        x -= cur;
        cur *= 2;
        e += 1;
    }
    ans = (even*(even+1))%mod + (odd*odd)%mod;
    return ans%mod;

}

int main() {
    ll l, r;
    cin >> l >> r;
    cout << (f(r) - f(l-1)+mod)%mod << endl;
    
    return 0;
}
