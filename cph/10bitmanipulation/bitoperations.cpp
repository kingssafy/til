#include <iostream>
using namespace std;

void and_operation(void) {
    // 'And' operation
    int x = 22;          //   10110
    int y = 26;          // & 11010
    int result = x&y;    //   10010
    cout << result << endl; 
}
void or_operation(void) {
    // 'or' operation
    int x = 22;                 //   10110
    int y = 26;                 // | 11010
    int result = x|y;           //   11110
    cout << result << endl;
}

void xor_operation(void) {
    // 'xor' operation x^r produces a number that has one bitsin positions where
    // exactly one of x and y have one bits
    int x = 22;                 //   10110
    int y = 26;                 // ^ 11010
    int result = x^y;           //   01100 
    cout << result << endl;
}

void not_operation(void) {
    // 'not' operation ~x produces a number where all the bits of x have been inverted.
    // ~x = -x-1 for example ~29 = -30
    int x = 29; //         0000000000000000000000000011101
    cout << ~x << endl; // 1111111111111111111111111100010
}

void bitshifts(void) {
    //left bit shift x << k appends k zero bits to the number, and right bit shift x >> k removes the
    //k last bits from the number x>>k coresponds to divide x by 2power tothe k rounded down to an integer.
    int x = 14;
    cout << (x<<2) << endl; //56;
} 



int main() {
    or_operation();
    xor_operation();
    bitshifts();
    return 0;
}
