#include <iostream>
using namespace std;

void bitize(char x) {
    for (char i = 7; i >=0; i--) {
        if(x&(1<<i)) cout << 1;
        else cout << 0;
    }
    cout << endl;
}


int main() {
    char b = 0;
    char x = (1<<3) | (1<<2) | (1<<1);
    do {
        cout << "b" << "   ";
        bitize(b);
        cout << "x" << "   ";
        bitize(x);
        cout << "-x" << "  ";
        bitize(-x);
        cout << "b-x" << " ";
        bitize(b-x);

        // proess subset b
        for (int i = 7; i >=0; i--) {
            if(b&(1<<i)) cout << i << " ";
        }
        cout << endl;
    } while ((b=(b-x)&x));
}

