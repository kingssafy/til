#include <iostream>
using namespace std;

int distance(char x[], int m, char y[], int n) {
    if (m == 0 && n == 0) {return 0;}
    if (m == 0) {return n;}
    if (n ==0) {return m;}
    int cost = 1;
    if (x[m-1]==y[n-1]) {cost = 0;}
    int result = min(distance(x, m-1, y, n) + 1, distance(x, m, y, n-1) + 1);
    result = min(result, distance(x, m-1, y, n-1)+cost);
    return result;
}


int main() {
    char x[5] = "love";
    char y[6] = "movie";
    int result = distance(x, 6, y, 6);
    
    cout << result;


    return 0;
}
