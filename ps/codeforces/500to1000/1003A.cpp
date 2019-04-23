#include <iostream>
using namespace std;

int main() {
    int arr[101] = {};
    int n, temp;
    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++) {
       cin >> temp;
       arr[temp]++;
       if (arr[temp] > max) {
           max = arr[temp];
       }
    }
    cout << max << "\n";
    return 0;
}
