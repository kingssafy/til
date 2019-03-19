// problem: 1121B
// ID: INMAK
// email: jchrys@me.com
// feel free to contact me
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("1121B_input.txt");
    int N;
    cin >> N;
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    int l, r, count, result;
    result = 1;
    sort(array, array+N);
    for (int i = array[0]; i < array[N-1]*2; i++) {
        l = 0, r = N-1;
        count = 0; 
        while (l < r) {
            if (array[l] + array[r] == i) {
                count++;
                l++;
                r--;
            } else if (array[l] + array[r] > i) {
                r--;
            } else {
                l++;
            }
        }
        result = max(result, count);
    } 
    cout << result;
    return 0;
}
