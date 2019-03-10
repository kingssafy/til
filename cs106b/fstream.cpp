#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ifstream input;
    input.open("poem.txt");
    while (!input.eof()) {
        char a;
        input >> a;
        if (input.eof()) break;
        cout << a << " ";
    }
    return 0;
}
