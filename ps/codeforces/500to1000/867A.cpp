#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char temp;
    char before;
    cin >> before;
    int StoF = 0;
    int FtoS = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> temp;
        if (before == 'S' && temp =='F') StoF++;
        else if (before == 'F' && temp =='S') FtoS++;
        before = temp;
    }
    if (StoF>FtoS) {
        cout << "YES" << "\n";
        return 0;
    }
    cout << "NO" << "\n";
    return 0;
}
