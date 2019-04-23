#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int eights = 0;
    char temp;
    for (int i = 0; i < n-10; i++) {
        scanf(" %c", &temp);
        if (temp == '8') eights++;
    }
    if (eights>((n-11)/2)) {
        cout << "YES" << endl;
        return 0;
    }   
    cout << "NO" << "\n";
    return 0;
}
