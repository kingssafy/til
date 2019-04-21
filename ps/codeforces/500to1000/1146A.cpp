#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    char temp;
    int a = 0;
    int b = 0;
    while (cin >> temp) {
        if (temp == 'a') a++;
        else b++;
    }
    cout << min(2*a-1, a+b) << "\n";
    return 0;
}
