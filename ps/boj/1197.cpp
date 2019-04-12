#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;


int const MAXV = 10001, MAXE = 100001;
int link[MAXV];
int size[MAXV];


struct edge{
    int w;
    int a;
    int b;
};
bool compareEdges(edge a, edge b) {
    return a.w < b.w;
}

edge edges[MAXV];

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
    //if (size[a] < size[b]) swap(a, b);
    size[a] +=  size[b];
    link[b] = a;
}

int main() {
    int V, E, u, v, w;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        size[i] = 1;
        link[i] = i;
    }
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--;v--;
        edges[i] = {w, u, v};
    }
    sort(edges, edges+V, compareEdges);
    ll result = 0;
    for (int i = 0; i < E; i++) {
        if (!same(edges[i].a, edges[i].b)) {
            unite(edges[i].a, edges[i].b);
            result += edges[i].w;
        }
    }
    printf("%lld\n", result);
    return 0;
}
