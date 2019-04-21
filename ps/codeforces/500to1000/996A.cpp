#include <iostream>
using namespace std;

int hit(int& n, int dollar) {
    int res;
    res = n/dollar;
    n %= dollar;
    return res;
}


int main() {
    int n;
    cin >> n;
    int ans = 0;
    ans += hit(n, 100);
    ans += hit(n, 20);
    ans += hit(n, 10);
    ans += hit(n, 5);
    ans += hit(n, 1);
    cout << ans << "\n";
    

    return 0;
}
