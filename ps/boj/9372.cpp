#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int const MAXN = 1001, MAXM = 10001;
int link[MAXN];
int size[MAXN];

int find(int x) {
    while(x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}


int main() {
    int T, N, M, u, v;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
            link[i] = i;
            size[i] = 1;
        }
        int result = 0;
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &u, &v);
            u--;v--;
            if (!same(u, v)) {
                unite(u, v);
                result++;
            }
            
        }
        printf("%d\n", result);

    }
    return 0;
}
