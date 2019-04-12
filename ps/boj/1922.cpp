#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int const MAXN = 1001, MAXM = 100001;
struct edge {
    int a;
    int b;
    int w;
};

bool edgeCompare(const edge& a, const edge& b) {
    return a.w < b.w;
}
vector<edge> edges;
int link[MAXN];
int size[MAXN];

int find(int x) {
    while (link[x]!= x) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (size[a] < size[b]) swap(a, b);
    link[b]= a;
    size[a] += size[b];
}


int main() {
    int N, M, u, v, w;    
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &w); 
        u--;v--;
        edges.push_back({u, v, w});
    }
    for (int i = 0; i < N; i++) {
        size[i] = 1;
        link[i] = i;
    }
    sort(edges.begin(), edges.end(), edgeCompare);
    int result = 0;
    for (auto edge: edges) {
        if (!same(edge.a, edge.b)) {
            unite(edge.a, edge.b);
            result += edge.w;
        }
    }
    printf("%d\n", result);
    
    return 0;
}
