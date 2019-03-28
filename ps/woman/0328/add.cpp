#include <iostream>
#include <cstdio>
using namespace std;
const int size = 2000001;
bool arr[size] = {};



int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        memset(arr, false, size);
        arr[0] = true;
        int N, K, temp;
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++) {
           scanf("%d", &temp);
           for (int k = K-temp; k >= 0; k--) {
                if (arr[k]) arr[k+temp]=true;
           }
        }
        if (arr[K]) {
            printf("YES");
        } else {
            printf("NO");
        }
    }

}
