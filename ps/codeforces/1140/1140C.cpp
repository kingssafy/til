#include <cstdio>
#include <algorithm> //sorting
#include <iostream>
#include <set>
using namespace std;

#define ll long long
const int N = 300001;
pair<int, int> a[N];

int main() {
    freopen("1140C.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a, a+n);
    ll res = 0;
    ll lengthsum =0;
    set<pair<int, int>> s;
    for (int i = n-1; i >= 0; i--) {
        s.insert(make_pair(a[i].second, i));  // if element doubles set contain only one of them so
                                              // we add pair to set!
        lengthsum += a[i].second;
        while((int) s.size() > k) {
            auto it = s.begin();
            lengthsum -= it->first;
            s.erase(it);
        }
        res = max(res, lengthsum * a[i].first);
    }

    cout << res << endl;

    return 0;
}
