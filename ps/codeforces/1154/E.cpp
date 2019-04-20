#include <cstdio>
#include <algorithm>
using namespace std;
int const MAXN = 200001; 

struct idxv {
    int v;
    int idx;
};
bool comp(const idxv& lhs, const idxv& rhs) {
    return lhs.v > rhs.v;
}
idxv maxlist[MAXN];


int arr[MAXN] = {};
int _next[MAXN] = {};
int before[MAXN] = {};
int start = 0;
void pop(int idx) {
    if (idx == -1) return;
    if (start == idx) {
        start = _next[idx];
    }
    if (before[idx] != -1) {
        _next[before[idx]] = _next[idx];
    }
    if (_next[idx] != -1) {
        before[_next[idx]] = before[idx];
    }
}


int maxstart = 0;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        _next[i] = i+1;
        before[i] = i-1;
        maxlist[i] = {arr[i], i};
    }
    sort(maxlist, maxlist+n, comp);
    _next[n-1] = -1;
    int team = 0;
    int maxstart = 0;
    while (start != -1) {
        int maxidx = -1;
        while (maxstart < n) {
            if (arr[maxlist[maxstart].idx] > 0) break;
            maxstart += 1;
        }
        maxidx = maxlist[maxstart].idx;

    
        int target = maxidx; 
        for (int i = 0; i < k; i++) {
            if (target == -1) break;
            target = _next[target];
            arr[target] = -team;
            pop(target);
        }
        target = maxidx;
        for (int i = 0; i < k; i++) {
            if (target == -1) break;
            target = before[target];
            arr[target] = -team;
            pop(target);
        }
        arr[maxidx] = -team;
        pop(maxidx);
        team ^= 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%d", -arr[i]+1);
    }
    
    return 0;
}
