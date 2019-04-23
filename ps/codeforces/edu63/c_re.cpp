#include <iostream>
#include <algorithm>
#define ll unsigned long long

using namespace std;
int const MAXNM = 3e6;
ll const INF = 1e18;


ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
ll arr[MAXNM];
ll brr[MAXNM];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        brr[i] = arr[i+1] - arr[i];
    }
    ll target = brr[0];
    for (int i = 0; i < n-1; i++) {
        target = __gcd(target, brr[i]);
    }  
    int temp;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if ((target+temp)%temp == 0) {
            cout << "YES" << "\n";
            cout << arr[0] << " " << i+1 << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    


    return 0;
}
