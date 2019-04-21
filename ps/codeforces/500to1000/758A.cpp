#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100] = {};
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (max < arr[i]) max = arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max-arr[i];
    }
    cout << ans << "\n";
    return 0;
}
