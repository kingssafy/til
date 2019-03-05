//Exhaustive search
//: Exploring every possible combination from a set of choices or values;
// often implemented recursively
// Generic code:
// Search(decisions):
// if there are no more decisions to make: Stop.
// else, let's handle one decision ourselves, and the rest by recursion.
// for each available choice C for this decision:
// -Choose C
// search the remaining decisions that could follow C
// Exercise: printBinary
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printBinary(int digits, string prefix) {
    cout << "printBinary(" << digits << ", " << prefix << ")" << endl;
    if (digits == 0) {
        cout << prefix << endl;
    } else {
        printBinary(digits - 1, prefix + "0");
        printBinary(digits - 1, prefix + "1");

    }
}

void printDecimal(int digits, int prefix) {
    if (digits == 0) {
       cout << prefix << endl; 
    } else {
        for (int i = 0; i < 10; i++) {
            printDecimal(digits -1, prefix*10+i);
        }
    }
}

void printDice(int digits, int prefix = 0) {
    if (digits == 0) {
        cout << prefix << endl;
    } else {
        for (int i = 1; i <= 6; i++) {
            printDice(digits-1, prefix*10+i);
        }
    }
}

int main(void) {
    printBinary(5,"");    
    printDecimal(2,0);
    printDice(3);
    return 0;
}
