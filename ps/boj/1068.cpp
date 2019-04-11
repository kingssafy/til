#include <cstdio>
using namespace std;
int const MAXN = 51;
int p[MAXN];
int s[MAXN];
int main() {
    int N, root, del;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
        s[i] = 1;
        if (p[i] == -1) root = i;
    }
    for (int i = 0; i < N; i++) {
        int parent = p[i];
        while (parent != -1) {
            s[parent]++;
            parent = p[parent];
        }
    }
    scanf("%d", &del);
    s[p[del]] -= s[del]; // togetanswer
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] != 1 || i == del) continue; 
        int parent = p[i];
        result++;
        while (parent != -1) {
            if (parent == del) {
                result--;
                break;
            }
            parent = p[parent];
        } 
    }
    printf("%d\n", result);
}
