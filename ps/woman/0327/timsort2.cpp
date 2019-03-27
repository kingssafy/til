#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
const int MAX = 5000;
const int KIM = 32;
int arr[MAX+1] = {};

void insertionSort(int arr[], int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int temp = arr[i];
        int j = i-1;
        while (arr[j] > temp && j >= l) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }  
}

void merge(int arr[], int l, int m, int r) {
    int len1 = m-l+1;
    int len2 = r-m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++) left[i] =arr[l+i];
    for (int i = 0; i < len2; i++) right[i] = arr[m+i+1];
    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        }  else {
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




int min(int a, int b) {
    return a < b ? a : b;
}

void timsort(int arr[], int l, int r) {
    for (int m = l; m < r; m += KIM) {
        insertionSort(arr, m, min(m+KIM-1, r-1)); //inclusive at the end;
    }

    for (int size = KIM; size < r; size += size) {
        
        for (int left = l; left < r; left += 2*size) {
            int mid = left+size-1;
            int right = min(left+2*size-1, r-1);

            merge(arr, left, mid, right);
        }
    }

}



int main() {
int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
//    N =11;
//    int arr[11] ={8, 24, 27, 18, 20, 6, 17, 19, 30, 11, 7};
 
    timsort(arr, 0, N);
    
    for (int i = 0; i < N; i++) printf("%d ", arr[i]);
    return 0;
    
}
