#include <iostream>
using namespace std;

int main(void) {
    int array[8] = {1, 3, 2, 5, 1, 1, 2, 3};
    int left = 0;
    int right = 2;
    int target = 8;
    int result = 0;
    bool wow = 0;
    for (int i = 0; i < 3; i++) {
        result += array[i];
    }
    cout << result << endl;
    for (int i = 0; i < 8; i++) {
        if (result == target) {
            wow = true; 
            cout << left << " and" << right << endl; 
            break; 
        }
        if (right == 7) {
            break;
        }
        if (result < target) {
            if (result + array[right+1] > target) {
                result -= array[left];
                left++;
                cout << "left++" << result << endl;
            } else {
                right ++;
                result += array[right];
                cout << "right++" << endl;
            }
        } 
    }
    cout << wow;
    
    return 0;
}
