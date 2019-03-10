//Motivation
//
//syntax for creating array
// type* name = new type[length];
// * a dynamically allocated array.
// * the variable that refers to the array is a pointer
// * The memory allocated for the array must be mau



// c++ has manual memory management
// delete [] name;
// * Releases the memory associated with the given array.
// * Must be done for all arrays created with new
//  - Or else the program has a memory leak. (No garbage collector like Java)
//  - Leaked memory will be released when the program exits, but for long-running programs,
//  memory leaks are bad and will eventually exhaust your RAM
//  
#include <iostream>
using namespace std;

int main(void) {
    int* nums = new int[10](); // () to initialize with 0s
    
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << ",  ";
    }
    cout << endl;

    delete[] nums; // memory leak
    return 0;
}
