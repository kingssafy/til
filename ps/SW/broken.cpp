#include <cstdio>
#include <iostream>
using namespace std;
int N, M, O;
int nums[10] = {};
int ops[4] = {}; 
int W;
int minimum = 2147483647;

int eval(int a, int op, int b) {
    if (op == 0) return b;
    if (op == 1) return a + b;
    if (op == 2) return a - b;
    if (op == 3) return a * b;
    return a / b;
}


void dfs(int a, int op, int b, int m) {
    if (m >= minimum && m != 0) return;
    if (b == W && m != 0 &&  op == 0) {
        minimum = min(minimum, m);
        return;
    }
    if (m!=0 && (b != 0 || op != 4)) {
        if (eval(a,op,b) > 999 && b != 1000) return; 
        if (eval(a,op,b) == W && b !=1000) {
            minimum = min(minimum, m+1);
            return;
        }
    }
    if (m > M) return;
    if (b != 1000) {
        for (int i = 0; i < N; i++) {
            dfs(a, op, b*10+nums[i], m+1);
        }

        for (int i = 0; i < O; i++) {
            if (b == 0 && op == 4) continue;
            dfs(eval(a,op,b), ops[i], 1000, m+1);
        }
    } else {
        for (int i = 0; i < N; i++) {
            dfs(a, op, nums[i], m+1);
        }
    }

}



int main() {
    freopen("broken_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d %d", &N, &O, &M);
        for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
        for (int i = 0; i < O; i++) scanf("%d", &ops[i]);
        scanf("%d", &W);
        minimum = 2147483647;
        dfs(0,0,1000,0);
        if (minimum == 2147483647) {
            printf("#%d -1\n", tc+1);
        } else {

            printf("#%d %d\n", tc+1, minimum);
        }


    }


    return 0;
}
