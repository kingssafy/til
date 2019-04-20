#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
const int MAXN = 202;
int abs(int a) {
    return a > 0 ? a : -a;
}
int arr[MAXN] = {};
int main() {
    int n;
    scanf("%d", &n);
    set<int> s, kind;
    int arr[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    kind.emplace(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) continue; 
        s.emplace(arr[i] - arr[i-1]); 
        kind.emplace(arr[i]);
    }
    int result = -1;
    if (s.size() == 1 && kind.size() == 2) {
        int sum = 0;
        for (auto x: kind) {
            sum += x;
        }
        if (sum %2 == 0) {
            result = sum/2-*kind.begin();
        } 
        else {
            result = *s.begin();
        }
    } else if (s.size() == 1 && kind.size() == 3) {
        result = *s.begin();
    } else if (s.size() == 0) {
        result = 0;
    }
    printf("%d\n", result);

    return 0;
}
