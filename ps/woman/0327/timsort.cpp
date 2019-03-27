#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 5001
#define RUN 32

int N;
int arr[MAX];

void insertionSort(int arr[], int left, int right) { //TODO
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    //original array is broken in twoparts
    // left and right array
    int len1 = m - l +1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++) left[i] = arr[l+i];
    for (int i = 0; i < len2; i++) right[i] = arr[m+1+i];

    int i = 0, j = 0, k = l;
    // after comparing, we merge those two array in larger subarray;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < len1) {
        arr[k++] = left[i++];
    }
    while (j < len2) {
        arr[k++] = right[j++];
    }
    
}




// iterative Timsort function to sort the
// array[0...n-1] (similar to mergeSort)
void timSort(int arr[], int n) { // n = size of array
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN) {
        insertionSort(arr, i, min((i+31), (n-1)));
    }

    // start merging from size RUN. it will merge
    // to form size 64, then 128, then 256 and so on...
    for (int size = RUN; size < n; size = 2*size) {
        // pick starting point of left sub array. We
        // are going to merge arr[left...left+size-1]
        // and arr[left + size, left+2*size-1]
        // After every merge, we increase left by 2*size
        for (int left = 0; left < n; left += 2*size) {
            // find end point of left sub array
            // mid +1 is starting point of right sub array
            int mid = left + size -1;
            int right = min((left + 2*size -1), (n-1));

            //merge sub array arr[left...mid] & arr[mid+1...right]
            merge(arr, left, mid, right);
        }
    }
}




int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
   
    timSort(arr, N);

    for (int i = 0; i < N; i++) printf("%d ", arr[i]);

    
    return 0;
}
