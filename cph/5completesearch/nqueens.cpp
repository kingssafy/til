//N-Queens problem

#include <iostream>
using namespace std;

int N = 16;
int column[16]{0};
int diag1[31]{0};
int diag2[31]{0};
int counter =0;
void search(int y) {
    int n=16;
    if (y == n) {
        counter ++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}


int main(void) {
    search(0);

    cout << counter;
    return 0;
}
