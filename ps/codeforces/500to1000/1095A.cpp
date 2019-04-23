#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int k = 1;
    char ans[100];
    int counter = 0;
    int i = 0;
    while (i < n) {
        ans[counter++] = s[i];
        i += k;
        k++;
    }
    for (int i = 0; i < counter; i++) {
        cout << ans[i];
    }
    cout << "\n";
}
