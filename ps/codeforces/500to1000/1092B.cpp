#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int ans = 0;
    for (int i = 0; i < n; i+=2) {
        ans += arr[i+1] - arr[i]; 
    }
    cout << ans << "\n";
    return 0;
}
