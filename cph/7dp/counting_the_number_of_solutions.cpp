// if coins = {1, 3, 4} and x = 5,  there are total of 6ways
// 1+1+1+1+1 , 3+1+1, 1+1+3, 1+4, 1+3+1, 4+,1

#include <iostream>
using namespace std;

int main() {
    int coins[3] = {1, 3, 4};
    int count[50] = {};
    count[0] = 1;
    int n = 30;

    for (int x =1; x <=n; x++) {
        for (auto c : coins) {
            if (x-c >= 0) {
                count[x] += count[x-c];
            }
        }
    }
    for (int x = 1; x <=n; x++) {
        cout << x << " " << count[x] << endl;
    }
    
    return 0;
}

