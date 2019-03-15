#include <iostream>
using namespace std;





int main() {
    int array[8] = {6, 2, 5, 1, 7, 4, 8, 3};
    int length[8] = {};
    length[0] = 1;
    int n = 8;
    for (int k = 0; k < n; k++) {
        length[k] = 1;
        for (int i = 0; i < k; i++) {
            if (array[i] < array[k]) {
                length[k] = max(length[k], length[i]+1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << length[i] << endl;
    }
}
