#include <iostream>
using namespace std;

int ok(int x) {
    return x > 13;
}

int main(void) {
    int x = -1;
    for (int b = 200; b >= 1; b /= 2) {
        while (!ok(x+b)) x += b;
    }
    int k = x+1;
    cout << k;
    return 0;
}
