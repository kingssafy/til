#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int before;
    cin >> before;
    int temp;
    int ans = 1;
    for (int i = 0; i < n-1; i++) {
        cin >> temp;
        if (before != temp) ans++;
        before = temp;
    }
    cout << ans << "\n";
}
