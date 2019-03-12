#include <iostream>
#include <vector>
#include <string>
using namespace std;
// It is also possible to give an external comparison function to the sort function as a callback function.
// For example, the following comparison function comp sorts strings primarily by length and the secondarily
// by alphabetical order

bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
