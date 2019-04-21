#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int const MAXN = 1e5+1;
vector<pair<ll, ll>> v(MAXN);

bool comp(const pair<ll, ll>& lhs, const pair<ll, ll>& rhs) {
    return lhs.first-lhs.second > rhs.first-rhs.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    v.resize(n);
    sort(v.begin(), v.end(), comp);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i+1;
        ans += (v[i].first - v[i].second)*j - v[i].first + v[i].second*n;
    }
    printf("%lld", ans);
    return 0;
}
