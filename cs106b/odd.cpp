#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input;
    input.open("odd_input.txt");
    int tc;
    input >> tc;
    for (int t=1; t <= tc; t++) {
        int sum = 0;
        int num;
        for (int i = 0; i < 10; i++) {
            input >> num;
            if (num % 2) sum += num;
        }
        cout << "#" << t << " " << sum << endl;
    }
    return 0;
}

