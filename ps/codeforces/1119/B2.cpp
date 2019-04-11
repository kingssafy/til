#include <cstdio>
#include <algorithm>
using namespace std;
const int RUN = 32;

int min(int a, int b) {
    return a > b ? b : a;
}

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < len2; i++) {
        right[i] = arr[m + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = 1;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < len1) arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];
}

void timSort(int arr[], int n) {
    for (int i = 0; i < n; i += RUN) 
        insertionSort(arr, i, min((i+31), (n-1)));
    for (int size = RUN; size < n; size = 2*size) {
        for (int left = 0; left < n; left += 2*size) {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n - 1));
            merge(arr, left, mid, right);
        }
    }
}

bool ok(int arr[], int n, int h) {
    int crr[5001] = {}, temp = 0;
    for (int i = 0; i < n; i++) crr[i] = arr[i];
    timSort(crr, n);
    //for (int i = 0; i < n; i++) printf("%d ", crr[i]);
    for (int i = n-1; i >= 0; i -= 2) {
        temp += crr[i] ;
    }
    //printf("\n");
    //printf("%d ", temp);
    return temp > h;
    
}

int main() {
    freopen("B_input.txt", "r", stdin);
    int n, h;
    int arr[1001] = {};
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int x = 0;
    for (int b = n; b >= 1; b = b/2) {
        printf("%d\n", b);
        while (!ok(arr, x+b, h)) x += b;
    }
    printf("%d", x);

    return 0;
}
