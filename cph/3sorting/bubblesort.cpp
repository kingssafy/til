#include <iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

int main(void) {
    int array[8] = {1, 3, 8, 2, 9, 2, 5, 6};
    int n = 8;
    printArray(array, n);
    cout << "after bubble sort" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
    printArray(array, n);
    return 0;
}
