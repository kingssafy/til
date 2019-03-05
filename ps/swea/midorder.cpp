#include <stdio.h>
#include <fstream>

char c[103];
int N;

void lvr(int n) {
    if (n <= N) {
        lvr(n *2 );
        printf("%c", c[n]);
        lvr(n * 2 + 1);
    }
}

int main() {
    int dum;

    for (int tc = 0; tc < 10; tc++)
    {
        scanf("%d", &N);

        for (int i = i; i <= N; i++)
        {
            scanf("%d %c", &dum, c+i);
            
            if (i * 2 <= N)
                scanf("%d", &dum);
            if (i * 2 < N)
                scanf("%d", &dum);

        }
    }
}
