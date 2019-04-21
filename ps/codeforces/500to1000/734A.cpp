#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a = 0, d = 0;
    char temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 'A') a++;
        else d++;
    }
    if (a == d) {
        cout << "Friendship" << "\n";
    } else if (a > d) {
        cout << "Anton" <<"\n";
    } else {
        cout << "Danik" << "\n";
    }
    return 0;
}
