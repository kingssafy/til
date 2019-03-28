#include <stdio.h>
int a[3] = {1, 2, 3};
int b[3] = {};
int N = 3;
void DFS(int no) {
    if (no == 3) {
        for (int i = 0; i < 3; i++) {
            printf("%d ", b[i]);
        }
        printf("\n");
    } else {
        b[no] = a[no];
        DFS(no+1);
        b[no] = 0;
        DFS(no+1);
    }

}


int main(void) {
    DFS(0);
}
