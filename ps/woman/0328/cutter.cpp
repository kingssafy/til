#include <iostream>
#include <cstdio>
using namespace std;
int N, M;
int arr[1000001] = {};
bool check(int mid) {
    long long sum = 0;
    for (int i = 0; i <N; i++) {
        sum += arr[i] - mid >= 0 ? arr[i] - mid : 0;
    }
    if (sum >= M) return false;
    return true;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int x = -1;
    for (int b = 1000000000; b >= 1; b /=2) {
        while (!check(b+x)) x+=b;
    }
    printf("%d", x); 
    return 0;
}
