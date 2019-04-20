#include <vector>
#include <iostream>
using namespace std;
int const INF= 1e9;
int main() {
    freopen("F_input.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    a.resize(k);
    reverse(a.begin(), a.end());
    for(auto x: a) {
        printf("%d ", x);

    }
    printf("\n");

    vector<int> offers(k+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= k) {
            offers[x] = max(offers[x], y);
        }
    }

    vector<int> pref(k+1);
    for (int i = 0; i < k; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    vector<int> dp(k+1, INF);
    dp[0] = 0;
    for (int i = 0; i < k; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + a[i]);
        for (int j = 1; j <= k; ++j) {
            if (offers[j] == 0) continue;
            if (i + j > k) break;
            dp[i+j] = min(dp[i+j], dp[i] + pref[i+j-offers[j]] - pref[i]);
        }
    }
    cout << dp[k] << "\n";
    return 0;
}
