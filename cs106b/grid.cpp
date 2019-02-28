#include <iostream>
using namespace std;

int main(void) {
    int const n = 8;
    int array[n] = {1, 3, 8, 2, 9, 2, 5, 6};
    
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j],array[j+1]);
            }
        }
    }
    for(int x: array) cout << x;
}
