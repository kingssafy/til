#include <cstdio>

int main() {
    int n, high = 0, count = 0, day = 0,temp = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        count ++;
        if (temp > high) {
            high = temp;
        } 
        if (high == count) {
            day++;
        }
    }
    printf("%d", day);

    return 0;
}
