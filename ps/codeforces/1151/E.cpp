#include <iostream>
#define ll long long
using namespace std;
int const MAXN = 1e5+1;
ll arr[MAXN] = {};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; 
        if (arr[i-1] < arr[i]) {
            ans += (arr[i] - arr[i-1]) * (n-arr[i]+1);
        } else if (arr[i-1] > arr[i]) {
            ans += arr[i] * (arr[i-1] - arr[i]);
        }
    }
    printf("%lld", ans);
    return 0;
}
