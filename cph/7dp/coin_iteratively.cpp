#include <iostream>
using namespace std;

int main() {
    int value[1000] = {};
    value[0] = 0;
    int coins[3] = {1, 3, 4};
    int N = 50;
    for (int x = 1; x < N; x++) {
        value[x] = 99999;
        for (int c : coins) {
            if(x - c>= 0) {
                value[x] = min(value[x], value[x-c]+1);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << i << ":" << value[i] << " ";
    }
    cout << endl;


    return 0;
}
