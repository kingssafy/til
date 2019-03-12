#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int> v) {
    int size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v[i] << ", ";
    }
    cout << endl;

}

void printVector(vector<pair<int, int>> v) {
    int size = v.size();
    for (int i = 0; i < size; i++) {
        cout << "{" << v[i].first << ", " << v[i].second << "}";
    }
    cout << endl;

}
// TODO how to print tuple??
void printVector(vector<tuple<int, int, int>> v) {
    int size = v.size();
    for (int i; i < size; i++) {
        cout << "{" << v[i] << endl;

    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << ", ";
    } 
    cout << endl;
}

int main(void) {
    // sorting a vector using built-in function
    vector <int> v = {4, 2, 5, 3, 5, 8 , 3};
    sort(v.rbegin(), v.rend());
    printVector(v);  

    //sorting ordinary array
    int n = 7; // arraysize
    int a[] = {4, 2, 5, 3, 5, 8, 3};
    sort(a, a+n);
    printArray(a, n);
    
    //sorting a string
    string s = "monkey";
    sort(s.begin(), s.end());
    cout << s << endl; // ekmnoy

    //Comparison operators
    //pair are sorted primarily acording to the first elements. and then second.
    vector<pair<int, int>> e;
    e.push_back({1, 5});
    e.push_back({2, 3});
    e.push_back({1, 2});
    sort(e.begin(), e.end());
    printVector(e);
    
    vector<tuple<int, int, int>> c;
    c.push_back({2, 1, 4});
    c.push_back({1, 5, 3});
    c.push_back({2, 1, 3});
    sort(c.begin(), c.end());

    
    return 0;
}
