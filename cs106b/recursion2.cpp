#include <iostream>
#include <fstream>
using namespace std;

void printBinary(int n) {
    cout << " printbinary(" << n << ")" << endl;
    if (n < 0) {
        cout << "-";
        printBinary(-n);
    } else if (n < 2) {
        cout <<"2x" << n;
    } else {

        // Binary of 43
        // ==
        // Binary of 21 (43/2)
        // + followed by
        // binary of 1 (43%2)
        printBinary(n/2);
        cout << n%2;
    }

}

void reverseLines(ifstream& input) {
    string line;
    if (getline(input, line)) {
        // there was a line
        reverseLines(input); 
        cout << line << endl;
    } else {
        //no lines
        
    }
}



int main(void) {
    printBinary(148);
    cout << endl;
    printBinary(-50);
    cout << endl;
    // reverseLines
    ifstream input;
    input.open("poem.txt");
    reverseLines(input);
    return 0;
}
