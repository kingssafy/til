#include <iostream>
using namespace std;

int main() {
    int first[100] ={};
    int value[1000] = {};
    value[0] = 0;
    int coins[3] = {1, 3, 4};
    int N = 50;
    for (int x = 1; x < N; x++) {
        value[x] = 99999;
        for (int c : coins) {
            if(x - c >= 0 && value[x-c] + 1 < value[x]) {
                value[x] = value[x-c] + 1;
                first[x] = c;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << i << ":" << value[i] << " ";
    }
    cout << endl;
    N = 19; 
    while (N > 0) {
        cout << first[N] << "\n";
        N -= first[N];
    }
    

    return 0;
}
