#include <iostream>
using namespace std;

int main() {
    bool possible[13] = {false};
    int w[] = {1, 3, 3, 5};
    int m = 0;
    for (int i = 0; i < 4; i++) {
        m += w[i];
    }
    int n = 4;
    possible[0] = true;
    for (int k = 0; k < n; k++) {
        for (int x = m-w[k]; x >= 0; x--) {
            possible[x+w[k]] |= possible[x];
        }
    }

    for (int i = 0; i < 13; i++) {
        cout << possible[i] << " ";
    }
    return 0;
}
