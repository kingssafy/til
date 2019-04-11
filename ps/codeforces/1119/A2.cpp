#include <cstdio>
using namespace std;

int main() {
    //freopen("A_input.txt", "r", stdin);
    int n, arr[300001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int len1 = 0, len2 = 0;
    for (int i = n-1; i >= 0; i--) {
        if (arr[0] != arr[i]) {
            len1 = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[n-1] != arr[i]) {
            len2 = n-i-1; 
            break;
        }
    }
    //printf("%d %d\n", len1, len2);
    printf("%d\n", len1 > len2 ? len1 : len2);

    return 0;
}
