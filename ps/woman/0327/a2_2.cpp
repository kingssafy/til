#include <cstdio>
using namespace std;
const int MAX = 50000;
int N, T, temp, a, b;
int arr[MAX] = {};
int lowerbound(int arr[], int target, bool mode=false) {
    int s = 0, e = N;
    while (s < e) {
        int m = (s+e)/2;
        if (arr[m] < target) {
            s = m+1;
        } else {
            e = m; 
        }
    }
    if (arr[e] == target || mode) {
        return e;
    } else {
        return -1;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    scanf("%d", &T); 
    for (int i = 0; i < T; i++)  {
        scanf("%d", &temp);
            a = lowerbound(arr, temp);
        if (a != -1) {
            printf("%d\n", a+1);
        } else {
            printf("0\n");
        }

    }
    return 0;
}
