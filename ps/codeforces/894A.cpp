#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    int Q = 0 , A = 0, result = 0, before = 0;
    cin >> str;
    for (auto temp: str) {
        if (temp == 'Q') {
            result += Q*A +before;
            before += Q*A;
            A = 0;
            Q++;
        } else if (temp == 'A') {
            A++;
        }
    }
    printf("%d", result);
    return 0;
}

