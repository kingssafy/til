#include <iostream>
using namespace std;

//the kth bit of a number is one exactly when {x &(1<<k)} is not zero
//following code prints the bit representation of an type(int) number x;

void bitize(int x) {
    for (int i = 31; i >= 0; i--) {
        if (x&(1<<i)) cout << "1";
        else cout << "0";
    } 
    cout << endl;

}

void first_application(int x, int k) {
    //the formula `x | (1<<k)` sets the kth bit of x to one;
    cout << "before" << endl;
    bitize(x);
    cout << "after `x | (1<<k)`" << endl;
    int y = (x|(1<<k));
    bitize(y);

}

void second_application(int x, int k) {
    // `x & ~(1<<k)` sets the kth bit of x to zero.
    cout << "before" << endl;
    bitize(x);
    cout << "after `x & ~(1<<k)`" << endl;
    int result = x & ~(1<<k);
    bitize(result);
}

void third_application(int x, int k) {
    // `x^(1<<k)` inverts the kth bit of x
    cout << "before" << endl;
    bitize(x);
    cout << "After: `" << x << " & ~(1<<" << k << ")`" << endl;
    int result = x^(1<<k);
    bitize(result);
}

void fourth_application(int x) {
    // `x&(x-1)` sets the last one bit of x to zero.
    cout << "before" << endl;
    bitize(x);
    cout << "after x&(x-1)" << endl;
    int result = x&(x-1);
    bitize(result);
}

void fifth_application(int x) {
    // `x & -x` sets all the one bits to zero, except for the last one bit. -> odd, even test
    cout << "before" << endl;
    bitize(x);
    bitize(-x);
    cout << "after `x & -x`" << endl;
    int result = x & -x;
    cout << "x" << endl;
    bitize(result);
}

void sixth_application(int x) {
    // `x | (x-1`) inverts all the bits after the last one bit.
    cout << "before" << endl;
    bitize(x);
    bitize(x-1);
    cout << "after `x | (x-1)`" << endl;
    int result = x | (x-1);
    bitize(result);
}

void seventh_application(int x) {
    // x is power of the if and only if `x&(x-1)` = 0
    cout << "beofre" << endl;
    bitize(x);
    bitize(x-1);
    cout << "after `x&(x-1)`" << endl;
    int result(x&(x-1));
    bitize(result);
}
/*
 * additional functions
 */
int main() {
   int x = 5328;
   cout << __builtin_clz(x) << "\n"; // 19 : the number of zeros at the beginning of the number;
   cout << __builtin_ctz(x) << "\n"; // 4 : the number of zeros at the end of the number;
   cout << __builtin_popcount(x) << "\n"; // 5 : the number of ones in the number;
   cout << __builtin_parity(x) << "\n"; // 1 : the parity(even or odd) of the number of ones;
    return 0;
}
