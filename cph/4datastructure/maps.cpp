#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
    map<string, int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;
    cout << m["banana"] << "\n"; //3
    cout << m["aybabtu"] << "\n"; // 0
    cout << m["aybabtu"] << "\n";
// iterator
// The element which an iterator points can be accessed using the * symbol.
//following code prints all the elements in increasing order:
    for (auto it = s.begin(); it != s.end; it++) {
        cout << *it << "\n";
    }
// following code prints the largest element in the set:
    auto it = s.end9); it--;
    cout << *it << "\n";

// The function find(x) returns an iterator that points to an element whose value is x
// However, if the set does not contain x, the iterator will be end.
    auto it = s.find(x);
    if (it == s.end()) {
        // x is not found
    }
// The function lower_bound(x) returns an iterator to the smallest element in the set whose
// value is at least x, and the function upper_bound(x) returns an iterator to the
// smallest element in the set whose value is larger than x.
// In both function if such an element does not exist, the return value is end.


// the following code finds the element nearst to x;
    auto it = s.lower_bound(x);
    if (it == s.begin()) {
        cout << *it << "\n";
    } else if (it == s.end()) {
        it --;
        cout << *it << "\n";
    } else {
        int a = *it; it--;
        int b = *it;
        if (x - b < a - x) cout << b << "\n";
        else cout << a << "\n";
    }
    return 0;
}
