#include <iostream>
using namespace std;

void helper(int array[], int size, int stack[]) {
    stack[0] = 0;
    stack[1] = array[0];
    int j = 1;
    for (int i = 1; i < size; i++) {
        while(array[i] < stack[j]) {
            j--;
        } 
        j++;
        stack[j] = array[i];
    }
    cout << stack[1] << stack[2];

}

void smaller(int array[]) {
    int size = 8;
    int stack[size+1];
    for (int i = 0; i < size+1; i++) {
        stack[i] = 0;
    }

    helper(array, size, stack);
}

int main() {
    int array[8] = {1, 3, 4, 2, 5, 3, 4, 2};
    smaller(array);
    return 0;
}
