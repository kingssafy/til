// recursion: The definition of an operation in terms of it self.
// - Solving a problem using recursion depends on solving smaller occurrences of the same problem.
// recursive programming: writing functions that call themselves to solve problems recursively.
// - An equally powerful substitute for iteration(loops)
// - Particularly well-suited to solving certain types of problems
// - Leads to `elegant`, simplistic, short code(when used well)
// - Many programming languages("functional" languages such as Scheme, ML, and Haskell) use recursion exclusively
// - A key component of the rest of our assign assignments in this course

#include <string>
#include <iostream>
using namespace std;

int power(int base, int exp) {
    if (exp < 0) {
        throw "Hey don't do that"; //kaboom
    }
    if (exp == 0) {
        return 1;
    } else {
        return power(base, exp-1) * base;
    }
}

int ispal(string s) {
    int size = s.size();
    if (size < 2) {
        return true;
    } else {
        char first = s[0];
        char last = s[s.length() -1];
        if (first == last) {
            string rest = s.substr(1, s.length() - 2);
            return ispal(rest);
        } else {
            return 0;
        }
    }
}

int main(void) {
    cout << power(3,5) << endl;
    cout << power(3,4) << endl;
    cout << power(3, 0) << endl;
    cout << ispal("hellolleh") << endl;
    cout << ispal("he") << endl;
    string s = "hellllo";
    cout << "start >>"<< s.substr(1,0) << "<< end";
    return 0;
}
