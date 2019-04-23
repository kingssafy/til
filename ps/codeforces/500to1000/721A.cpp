#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char temp;
    int counter = 0;
    int arr[101] = {};
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 'B') {
            arr[counter]++;
        } else if (temp == 'W' && arr[counter] != 0) {
           counter++; 
        }
    }
    if (arr[counter] != 0) counter++;
    cout << counter << "\n";
    for (int i = 0; i < counter; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
