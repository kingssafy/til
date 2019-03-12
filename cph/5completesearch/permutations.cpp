/*
 * Generating permutations
 */

//Method1 Recursion
#include <vector>
#include <iostream>
using namespace std;

void search(int n, vector<int>& permutation, vector<bool>& chosen) {
    int size = permutation.size();
    if (size == n) {
        //process permutation
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search(n, permutation, chosen);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

void searchcaller() {
    
}

