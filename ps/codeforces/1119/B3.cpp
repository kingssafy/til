#include <cstdio>
#include <algorithm>
#define ll unsigned long long
using namespace std;
ll n;
bool ok(ll brr[], ll size, ll h) {
    int arr[1001] = {};
    for (ll i = 0; i < size; i++) arr[i] = brr[i];
    ll temp = 0;
    sort(arr, arr+size);    
    for (int i = size - 1; i >= 0; i = i-2) {
        temp += arr[i];
    }
    return size <= n && temp <= h;

}


int main() {
    ll h, arr[1001] = {};
    //freopen("B_input.txt", "r", stdin);
    scanf("%llu %llu", &n, &h); 
    for (ll i = 0; i < n; i++) {
        scanf("%llu", &arr[i]);
    }
    int x = -1;
    for (int b = n; b >= 1; b /= 2) {
        while (ok(arr, x+b, h)) x += b;
    }
    int k = x;
    printf("%d", k);

    return 0;
}
