#include <iostream>
#include <string>
using namespace std;
int k;
int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++)
        result *= a;
    return result;

}
string a, b;
int arr[200001];
int brr[200001];
int main() {  // 26-ary
    cin >> k >> a >> b;
    for (int i = 1; i < k+1; i++) {
        arr[i] = a[i-1]-'a';
        brr[i] = b[i-1]-'a';
        arr[i] += brr[i];
    }
    for (int i = k; i >= 1; i--) {
        arr[i-1] += arr[i]/26;
        arr[i] %= 26;
    }

    for (int i = 0; i < k; i++) {
        int temp = arr[i] % 2;
        arr[i] /= 2;
        arr[i+1] += 26*temp;
    }
    arr[k] /= 2;
    for (int i = 1; i < k+1; i++) {
        cout << char(arr[i]+'a');
    } 
    return 0;
}
