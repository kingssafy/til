#include <cstdio>

int main() {
    int n, temp;
    int result = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%1d", &temp);
        if (!(temp %2)) {
            result += i;
        }
    }
    printf("%d\n", result);
    return 0;
}
