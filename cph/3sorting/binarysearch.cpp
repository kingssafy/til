#include <iostream>
using namespace std;

//General method for searching for an element in an array O(N)
int find(int array[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (array[i] == x) {
            // x found at index i 
            return i;
        }
    }
    return -1;
}



//if the array is sorted. we can use binary search O(lgN)


// binary search method 1
int binarysearch(int array[], int size, int x) {
    int a = 0, b = size - 1;
    while (a <= b) {
        int k = (a + b) / 2;
        if (array[k] == x) {
            // x found at index k
            return k;
        }
        if (array[k] > x) b = k - 1;
        else a = k + 1;
    }
    return -1;
}

/* binary search method2
 * based on an efficient way to iterate through the elements of the array.
 * The idea is to make jumps and slow the speed when we get closer to the target element.
 * search goes through the array from left to right, and initial jump
 * length is n/2. at each step the jump, length will be havled: first n/4, then n/8...
 */

int binarysearch2(int array[], int size, int x) {
    int k = 0;
    for (int b = size/2; b >= 1; b /= 2) {
        while (k+b < size && array[k+b] <= x) k += b;
    }
    if (array[k] == x) {
        // x found at index k
        return k;
    }
    return -1;
}

/*
 * C++ functions
 *  these functions assume that the array is sorted.
 *  - lower_bound returns a pointer to the first array element whose value is at least x.
 *  - upper_bound returns a pointer to the first array element whose vlaue is larger than x.
 *  equal_range returns both above pointers.
 */

bool find2(int array[], int size, int x) {
    auto k = lower_bound(array, array+size, x) - array;
    if (k < size && array[k] == x) {
        // x found at index k
        return true;
    }
    return false;
}

/*
 * the following code counts the number of elements whose value is x
 */
int counts(int array[], int size, int x) {
    auto a = lower_bound(array, array+size, x);
    auto b = upper_bound(array, array+size, x);
    return b-a;
}
// using equal_range, the code becomes shorter
int counts2(int array[], int size, int x) {
    auto r = equal_range(array, array+size, x);
    return r.second-r.first;
}

//Finding the smallest solution
//An important use for binary search is to find the 
//position where the value of a function changes.

int find3(function ok, int k ) {
    int x = -1;
    for (int b = z; b >= 1; b/=2) {
        while (!ok(x+b)) x += b;
    }
    int k = x+1;
}

//Finding the maximum value
//Binary search can also be used to find the maximum value for 


int main(void) {
    int array[] = {1,2,4,5,6,7,9};
    int size = 7;
    int x = 3;
    cout << binarysearch(array, size, x);
    

    return 0;
}
