#include <iostream>
using namespace std;
int arr[5];
int main() {
    cin >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    int n;
    int ans = 0;
    while(scanf("%1d", &n) != EOF) {
        ans += arr[n]; 
    } 
    cout << ans << "\n";
    return 0;
}
