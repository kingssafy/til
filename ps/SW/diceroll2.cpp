#include <cstdio>
using namespace std;
int subset[7] = {};
void sol(int N, int M, int count, int crSum) {
    if (count == N) {
        for (int i = 0; i < N; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= 6; i++) {
            int newSum = crSum+i;
            if (newSum <= M && newSum+6*(N-count-1) >= M && newSum+(N-count-1)<=M) {
            subset[count] = i;
            sol(N, M, count+1, crSum+i);
            }
        }
    }




}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    sol(N, M, 0, 0);
    return 0;
}
