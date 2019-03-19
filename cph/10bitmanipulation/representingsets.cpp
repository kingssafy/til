#include <iostream>
using namespace std;

//Every subset of a set {0,1,2,..., n-1} can be represented as an n bit integer
//Set implementation

void set_implementation(void) {
    /*
     * the following code declares an int variable x that can contain
     * a subset of {0,1,2,...,31}. After this, the code adds the elements 1,3,4 and 8 tothe set
     * and prints the size of the set.
     */
    int x = 0;
    x |= (1<<1);
    x |= (1<<3);
    x |= (1<<4);
    x |= (1<<8);
    cout << __builtin_popcount(x) << "\n"; //4
    // Then, the following code prints all elements that belong to the set;
    for (int i = 0; i < 32; i++) {
        if (x&(1<<i)) cout << i << " ";
    } // output: 1 3 4 8

}

void set_operations() {
    /*
     * set operations can be implemented as follows as bit operations
     * intersection ==> a & b
     * union        ==> a | b
     * complement   ==> ~a
     * difference   ==> a & (~b)
     * for example, the following code first constructs the set x = {1,3,4,8} and y ={3,6,8,9}
     * and then constructs the set z = x(union)y = {1,3,4,6,8,9};
     */
    int x = (1<<1) | (1<<3) | (1<<4) | (1<<8);
    int y = (1<<3) | (1<<6) | (1<<8) | (1<<9);
    int z = x|y;
    cout << __builtin_popcount(z) << "\n"; // 6
    for (int i = 0; i <32; i++) {
        if (z&(1<<i)) cout << i << " ";
    }
    cout << endl;


}

void iter_subsets() {
    //the following code goes through the subsets of {0,1,...,n-1};
    for(int b = 0; b< (1<<n); b++) {
        // process subset b
    }

    //The following code goes through the subsets with exactly k elements:
    for(int b = 0; b < (1<<n); b++) {
        if (__builtin_popcount(b) == k) {
            // process subset b
        }
    }

    //following code goes through the subsets of a set x
    int b = 0;
    do {
        // proess subset b
        for (int i = 31; i >=0; i--) {
            if(b&(1<<i)) cout << i << " ";
        }
        cout << endl;
    } while (b = (b-x) &x);
}

int main() {
    set_operations();    
    return 0;
}
