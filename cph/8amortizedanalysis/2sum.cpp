#include <iostream>
using namespace std;

int twosum(int array[], int size, int target) {
    int left = 0;
    int right = size-1;
    int sum = 0;
    bool finder = 0;
    while (left != right) {
        sum = array[left] + array[right];
        if (array[left]+ array[right] == target) {
            finder = 1;
            break;
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }

    }
    
    return finder;
}



int main() {
    //assume array is sorted in increasing order;
    int array[8] = {1, 4, 5, 6, 7, 9, 9, 10};
    int x = 12; // target
    bool result = twosum(array, 8, x);
    cout << result;
    return 0;
}
