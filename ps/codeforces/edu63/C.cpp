#include <iostream>
#include <algorithm>
#define ll unsigned long long

using namespace std;
int const MAXNM = 400000;
ll const INF = 1e18;


ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, (a+b)%b);
}

ll arr[MAXNM] = {};
ll brr[MAXNM] = {};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n-1; i++) {
        brr[i] = arr[i+1]-arr[0];
    }
    
    for (int j = 1; j <= m; j++) {
        bool flag = true;
        ll temp;
        cin >> temp;
        for (int i = 0; i < n-1; i++) {
            if (brr[i]%temp) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << "\n";
            cout << arr[0] << " " << j << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";

    return 0;
}
