#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main() {
    int N, K, temp;
    int arr[12] = {}, sum=0;
    set<int> s;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        sum += temp;
        arr[i] = temp;
    }
    s.emplace(sum);
    for (auto x : arr) {
        auto end = s.end();
        for (auto it = s.begin(); it != end; it++) {
            s.emplace(*it-x);
        }
    }
    int size = s.size(), which=0;
    for (auto x: s) {
        if (x == K) break;
        which++; 
    }
    cout << size-which << endl;

    
    return 0;
}
