#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double orange = 0;
    double total = 0;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp; 
        total += 100;
        orange += temp;
    }
    double ans;
    ans = orange / total * 100;
    cout << ans;

    return 0;
}
