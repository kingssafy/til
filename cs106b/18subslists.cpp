// write a rfunction sublists that finds every possible sub-list of a given vector.
// A sub-list of a vector,, you can print the sub-lists out in any order, one per line.
#include <vector>
#include <iostream>
#include <string>
using namespace std;


void sublistsHelper(vector<String>& v, vector<string>& chosen) {
    if (v.empty()) {
        for (auto x : chosen) {
            cout << x;
        } 
        cout << endl;

    } else {
        string first = v[0];
        v.erase()

    }
}


void sublists(vector<string> & v) {
    vector<string> chosen;
    sublistsHelper(v, chosen);
}


int main(void) {
    vector<string> group = {"jane", "Bob", "Matt", "Sara"};
    return 0;
}
