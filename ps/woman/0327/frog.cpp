#include "bits/stdc++.h"
using namespace std;

int N;
int arr[1001] = {};
int search(int target) {
    int x = -1;
    for (int i = N; i >= 1; i/=2) {
        while (x+i < N && arr[x+i]<target) x+= i;

    }     
    return x;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]); 
    }

    int result = 0; 
    sort(arr, arr+N);
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            int jump = arr[j]-arr[i];
            result += search(arr[j]+2*jump+1) - search(arr[j]+jump);

        }
    }
    cout << result;

    return 0;
}
