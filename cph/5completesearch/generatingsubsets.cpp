#include <iostream>
#include <vector>
using namespace std;
// Method 1 
// an elegant way to go through all subsets of a set is to use recursion
void search(int k, vector<int>& subset) {
    if (k == 3) {
        for (auto x : subset) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        search(k+1, subset);
        subset.push_back(k);
        search(k+1, subset);
        subset.pop_back();
    }
}

// Method 2
// following code goes through the subset of n elements;
void method2(void) {
    for (int b = 0; b < (1<<n); b++) {
        //process subset
        //using bit representation
    }
}

void method2a(void) {
    for (int b = 0; b < (1<<n); b++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)) subset.push_back(i);
        }
    }
}

int main(void) {
    /*
     */
    /* int k = 0;
     * vector<int> subset;
     *search(k, subset);
     */



}
