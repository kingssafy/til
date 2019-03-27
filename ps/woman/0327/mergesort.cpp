#include <cstdio>
using namespace std;
int N;
int array[5001];

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r - m;

    //create temp arrays 
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) L[i] = arr[l + i]; 
    for (i = 0; i < n2; i++) R[i] = arr[m+1+i];
    i = j = 0;
    k = l;  // index of first subarray, second, merged subarray; 
    while (i < n1 && j < n2) {
        if(L[i] < R[j]) {
            arr[k++] = L[i++]; 
        } else {
            arr[k++] = R[j++];
        }
    } 
    while (i < n1) {
        arr[k++]  = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

}


void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids over flow for
        // large l and r
        int m = l+(r-l)/2; //TODO why r-1?? will check it out

        // Sort first and second halves;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


int main() {
    scanf("%d", &N); 
    for (int i = 0; i < N; i++) scanf("%d", &array[i]);
    //TODO
    mergeSort(array, 0, N-1);
    for (int i = 0; i < N; i++) printf("%d ", array[i]);


    return 0;
}
