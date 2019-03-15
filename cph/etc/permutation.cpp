#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void permute(char* a, int l, int r) {
    int i;
    if (l == r) {

        cout << a << endl;
    } else {
        for (i = l; i <=r; i++) {
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i));
        }
    }
}

int main() {
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n);
    return 0;
}
