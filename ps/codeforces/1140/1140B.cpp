#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int T, n, left, right=0, leftflag=1;
    char a;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        leftflag = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf(" %c", &a);
            if (leftflag == 1 && a == '>' ) {
                leftflag = 0;
                left = i;
            }
            if (a =='<') {
                right=i;
            }
        }
        printf("%d\n", max(0, min(left-1, n-right)));
    }

}
