#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    ll result = 0;
    ll k = 4;
    int cur=2;
    for (int i = n-2; i > 0; i--) {
        cur += k;
        k += 2;
        result += cur;
    }
    cout << result;
}
