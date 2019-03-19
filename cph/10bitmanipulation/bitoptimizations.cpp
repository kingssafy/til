//Many algorithms can be optimized using bit operations.
//Such optimizations do not change the time complexity of the algorithm, but they may have a large impact on the actual running time.

/*
 * Hamming distances
 * The hamming distance hamming(a, b) between two strings a and b of equal length
 * is the number of positions where the strings differ.
 */
//straight forward algo O(n^2 k)
#include <iostream>
#include <string>
using namespace std;

int hamming(string a, string b) {
    int d = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] != b[i]) d++;
    }
    return d;
}

// if k is small we can optimize the code by storing the bit string as Integer
// s and calculating hamming distance using bit operations.
int hamming(int a, int b) {
    return __builtin_popcount(a^b);
}

int main() {
    
    return 0;
}
