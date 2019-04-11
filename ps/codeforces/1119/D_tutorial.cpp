#include <cstdio>
#include <algorithm>

int const MAXN = 1e5;

static int n, q;
static long long s[MAXN];
static long long t[MAXN] = {};

int main() {
    freopen("D_input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &s[i]);     // 3, 1, 4, 1, 5, 9

    std::sort(s, s + n);                                  // 1, 1, 3, 4, 5, 9
    for (int i = 0; i < n - 1; ++i) s[i] = s[i+1] - s[i]; // 0, 2, 1, 1, 4, 9

    std::sort(s, s + n - 1);                              // 0, 1, 1, 2, 4, 9
    for (int i = n - 1; i >= 1; --i) s[i] = s[i - 1];     // *, 0, 1, 1, 2, 4
    s[0] = 0;                                             // 0, 0, 1, 1, 2, 4 

    for (int i = 1; i < n; ++i)
        t[i] = t[i-1] + (s[i] - s[i -1]) * (n + 1 - i);   // t = {0, 0, 5, 5, 8, 12};

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        l = r - l + 1;
        int p = std::lower_bound(s, s + n, l) - &s[0] - 1;
        printf("%lld%c", t[p] + (l - s[p]) * (n - p), i == q -1 ? '\n' : ' ');
    }
    return 0;
    
}
