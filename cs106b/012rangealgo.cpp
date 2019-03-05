#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//The following algorithm finds the range of numbers in a vector:

//returns the range of values in the given array;
//the difference between elements furthest apart
//example; range({17, 29, 11, 4, 20 , 8}) is 25

int range(vector<int>& numbers) {
    int maxDiff = 0; // look at each pair of values;
    int size = numbers.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int diff = abs(numbers[j] - numbers[i]);
            maxDiff = max(maxDiff, diff);
        }
    }
    return maxDiff;
}

// Here is a faster version. But how much faster??
//
int range2(vector<int>& numbers) {
    int hi = numbers[0];
    int lo = hi;
    int size = numbers.size();
    for (int i = 0; i < size; i++) {
        hi = max(hi, numbers[i]);
        lo = min(lo, numbers[i]);
    }
    return hi-lo;
}


