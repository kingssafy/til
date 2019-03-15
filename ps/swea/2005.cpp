#include <iostream>
using namespace std;

int main() {
    int T;
    int n;
    int array[11] = {};
    int temp;
    int temp2;
    array[1] = 1;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n; 
        cout << "#" << i+1 << " " << endl;
        for (int k =0; k < 11; k++) {
            array[k] = 0;
        }
        array[1] =1;
        for (int j = 1; j <= n; j++) {
            temp2 = 0;
            for (int k = 1; k <= j; k++) {
                temp = array[k];
                cout << array[k]+temp2 << " ";
                array[k] = array[k]+temp2;
                temp2 = temp;
            }
            cout << endl;
        }
    }
    return 0;
}
