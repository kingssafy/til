#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int const MAXN = 100001, M = 1000001;
struct edge{
    int u;
    int v;
    int w;
};
vector<edge> edges;
int size[MAXN], link[MAXN];
bool compareEdge(edge& a, edge& b) {
    return a.w < b.w;
} 
int find(int x) {
    while (link[x] != x) x = link[x];
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
    link[b] = link[a];
}

int main() {
    int N, M, u, v, w;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        size[i] = 1;
        link[i] = i;
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--;v--;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(), edges.end(), compareEdge);
    int result = 0;
    int maximum = 0;
    for (auto x: edges) {
        if (!same(x.u, x.v)) {
            unite(x.u, x.v); 
            result += x.w;
            maximum = max(maximum, x.w); 
        }
    }
    printf("%d\n", result-maximum);
    return 0;
}
