#include <iostream>

using namespace std;

int set[5]  = {1,2,3,4,5};
int subset1[5] = {};
int subset2[5] = {};
void dfs(int a, int b, int n) {
    if (a + b == n) {
        cout << "a: ";
        for (int i = 0; i < a; i++) {
            cout << subset1[i] << " ";
        }
        cout << "b: ";
        for (int i = 0; i < b; i++) {
            cout << subset2[i] << " ";
        }
        cout << endl;
    } else {
        subset1[a] = set[a+b];
        dfs(a+1, b, n);
        subset2[b] = set[a+b];
        dfs(a, b+1, n);

    }
}
int main() {
    dfs(0,0,5);
    return 0;
}
