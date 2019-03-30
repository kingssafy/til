#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main() {
    int arr[5] = {3,1,3,5,6}, sum=20;
    set<int> s;
    s.emplace(sum);
    for (auto x : arr) {
        auto end = s.end();
        for (auto it = s.begin(); it != end; it++) {
            s.emplace(*it-x);
        }
    }
    return 0;
}
