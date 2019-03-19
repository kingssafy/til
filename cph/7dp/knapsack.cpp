#include <iostream>
using namespace std;

int main() {
    bool possible[5][13] = {{false}};
    int weights[4] = {1, 3, 3, 2}; 
    int k = 4;
    int n = 0;
    for (int x : weights) {
        n += x;
    }
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 13; x++) {
            cout << possible[y][x]<< " ";
        }
        cout << endl;
    }

    possible[0][0] = true;
    for (int i = 1; i <= k; i++) {
        for (int x = 0; x <= n; x++) {
            if (x-weights[i-1] >= 0) {
                possible[i][x] |= possible[i-1][x-weights[i-1]] ;
            } 
            possible[i][x] |= possible[i-1][x];
        }
    }
     
    cout << endl;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 13; x++) {
            cout << possible[y][x]<< " ";
        }
        cout << endl;
    }



    return 0;
}
