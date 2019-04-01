#include <cstdio>
using namespace std;
// i can also use array;
int arr[12] = {};
bool answer[60001] = {};
int main() {
    int N, M, temp;
    scanf("%d", &N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    answer[sum] = true;
    for (int i = 0; i < N; i++) answer[arr[i]] = true;
    for (int j = N-1; j >= 0; j--) {
        for (int i = sum-arr[j];i >= 0; i--) {
            if (answer[i+arr[j]]) {
                answer[i] = true;
            }
        }
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &temp);
        if (answer[temp]) {
            printf("Y ");
        } else {
            printf("N ");
        }
    }
    printf("\n");
    for (int i = sum; i >= 0; i--) {
        if (answer[i]) printf("%d ", i);
    }


    return 0;
}
