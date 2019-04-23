#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1001] = {};
    int counter = -1;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 1) {
            counter++;
        }
        arr[counter]++;
    }
    counter++;
    cout << counter << "\n";
    for (int i = 0; i < counter; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}
