#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        if (s[i-1] > s[i]) {
            cout << "YES" << "\n";
            cout << i << " " << i+1 << "\n";
            return 0;
        } 
    }
    cout << "NO" << "\n";
    
    return 0;
}
