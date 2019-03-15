#include <iostream>
#include <string>
using namespace std;

int distance(char x[], int n,  char y[], int m) {
    int result = 999;
    int cost = 1;
    if (n == 0 && m == 0) {return 0;}
    if (n == 0) {return m;}
    if (m == 0) {return n;}
    if (x[n-1] == y[m-1]) {cost = 0;}
    result = min(distance(x, n, y, m-1) +1, result);
    result = min(result, distance(x, n-1, y, m)+1);
    result = min(result, distance(x, n-1, y, m-1)+cost);
    return result;
}

int main() {
    char x[5] = "love"; 
    char y[6] = "movie";
    int result = distance(x,5, y, 6);
    cout << result;
    return 0;
}
