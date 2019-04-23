#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int const MAXN = 3e6;
ll arr[MAXN] = {};
ll pos[MAXN] = {};
ll impos[MAXN] = {};
int main() {
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    } 
    pos[0] = max(arr[0], arr[0]*x);
    impos[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pos[i] = max(pos[i-1]+x*arr[i], arr[i]);
        impos[i] = max(impos[i-1]+arr[i], arr[i]);
        ans = max(pos[i], impos[i]);
    }
    cout << max(ans, 0) << endl;
    return 0;
}
