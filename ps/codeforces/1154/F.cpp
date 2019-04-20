#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int const INF = 2e8;

int main() {
    //freopen("F_input.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    arr.resize(k);
    vector<int> pref(k+1);
    for (int i = 0; i < k; i++) {
        pref[i+1] = pref[i] + arr[i];
    }
    vector<int> offers(k+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= k) {
            offers[x] = max(offers[x], y);
        }
    }

    vector<int> dp(k+1, INF);
    dp[0] = 0;
    for (int i = 0; i < k; i++) {
        dp[i+1] = min(dp[i+1], dp[i]+arr[i]);
        for (int j = 1; j <= k; j++) {
            if (offers[j] == 0) continue;
            if (i+j > k) break;
            dp[i+j] = min(dp[i+j], dp[i] + pref[i+j] - pref[i+offers[j]]);
        }
    }
    printf("%d\n", dp[k]);

    return 0;
}
