#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double n, m, a, b, c, out;
    cin >> n >> m >> a;
    out = ceil(n/a)*ceil(m/a);
    cout << scientific << out << endl;
}
