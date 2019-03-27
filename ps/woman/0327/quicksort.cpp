#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 5000

int N;
int arr[MAX];

void quicksort(int s, int e) {
    if (s < e) {
        int pv=arr[e];
        int t = s;
        for (int i = s; i < e; i++) {
            if (arr[i] < pv) {
                swap(arr[i], arr[t++]);
            }
        }
        swap(arr[e], arr[t]);
        quicksort(s, t-1);
        quicksort(t+1, e);
    } 
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(0, N-1); 
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }



    return 0;
}
