#include <cstdio>
#include <algorithm>
#define ll long long int
using namespace std;

int main() {
    //freopen("E_input.txt", "r", stdin);
    ll n, x, remain = 0, ans = 0;
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld", &x);
        int q = min(x/2, remain);
        ans += q;
        remain -= q;
        x -= 2*q;
        ans += x/3;
        x = x%3;
        remain += x;
    }
    printf("%lld\n", ans);
    return 0;
}
