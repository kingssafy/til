#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    long long x = 1;
    int n = 21;
    int m = 555;
    for (int i = 2; i <= n; i++) {
        x = (x*i)%m;
    }
    cout << x%m << "\n";
    return 0;
}
