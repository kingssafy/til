#include <iostream>
#include <algorithm>
#define ll unsigned long long
using namespace std;
int solve(ll arr[], ll a, ll b, int n) {
    ll result = 0;
    result += arr[n-1] + b - (arr[n-1] + a)+1;
    cout << result << endl;
    for (int i = n-2; i >=0; i--) {
        result += min(arr[i]+b, arr[i+1]-1) - (arr[i]+a)+1;
        
    }
    return result;
}
int main() {
    freopen("D_input.txt", "r", stdin);
    int n, q;
    ll arr[100000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> q;
    ll a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b; 
        cout << solve(arr, a, b, n) << " " << end;
    } 
    

    return 0;
}
