#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[5001] = {};
    arr[0] = 0;
    arr[1] = 0;
    arr[4] = 0;
    arr[2] = 0;
    arr[3] = 1;
    arr[5] = 1;
    for (int i = 6; i < n+1; i++) {
        int temp = -1;
        if (arr[i-3]) temp = arr[i-3]+1;
        if (arr[i-5]) temp = min(temp, arr[i-5]+1);
        if (temp != -1) arr[i] = temp;
    }
    printf("%d\n", arr[n]);
    return 0;
}
