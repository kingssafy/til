#include <iostream>
using namespace std;



int calculator(int coins[3], int size, int target) {
    if (target < 0 ) {return 21474;}
    if (target == 0) {return 0;}
    int best = 99999;
    for (int i = 0; i < size; i++) {
        best = min(best, calculator(coins, size, (target-coins[i]))+1);
    }
    return best; 
}



int main() {
    int coins[3] = {1, 3, 4};
    int size = 3;
    int target = 10;
    int a = calculator(coins, size, target);
    cout << a;
    return 0;
}
