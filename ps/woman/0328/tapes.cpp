#include <iostream>
#include <algorithm>
using namespace std;

template<typename T> void _swap(T& t1, T& t2) {
    T temp(t1);
    t1 = t2;
    t2 = temp;
}

int main() {
    int N, a = 0, b = 0;
    int arr[20];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int i = N-1 ,l = 0, r = 0;
    while (l < N/2 && r < N/2) {
        if (a < b) {
            a += arr[i--];
            l++;
        } else {
            b += arr[i--];
            r++;
        }
    }
    while (r < N/2) { 
            b += arr[i--];
            r++;
    }
    while (l < N/2) {
        a += arr[i--];
        l++;
    }

    if (a > b) _swap(a, b);
    cout << b - a << endl;
     
    return 0;
}
