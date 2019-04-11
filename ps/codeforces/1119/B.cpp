#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e3+1;
const int MAXH = 1e9+1;
int bottles[MAXN];
int N, H;
int arr[MAXN];
bool ok(int N) {
    for (int i = 0; i < N; i++) {
        arr[i] = bottles[i];
    }
    sort(arr, arr+N);
    int remain = H;
    for (int i = N-1; i >=0; i -= 2) {
        if (remain < arr[i]) return false;
        remain -= arr[i]; 
    }
    return true;
}

int main() {
    //freopen("B_input.txt", "r", stdin);
    scanf("%d %d", &N, &H);
    for (int i = 0; i < N; i++) scanf("%d", &bottles[i]);
    bottles[N] = 2e9;
    int x = -1;
    for (int b = N; b >= 1; b /= 2) {
        while (ok(x+b)) x += b;

    }
    printf("%d", x);

    return 0;
}
