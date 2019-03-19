#include <iostream>
using namespace std;

int main() {
    int x = 2147483647;
    cout << x << "\n"; //2147483647
    x++;
    cout << x << "\n"; // -2147483648  int overflow
    //
    x = -43;
    unsigned int y = x;
    cout << x << "\n"; // -43
    cout << y << "\n"; // 2^32-43 == 4294967253
    return 0;
}
