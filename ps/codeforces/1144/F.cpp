#include <cstdio>
#include <vector>
using namespace std;
vector<int> g[200000];
int colors[200000] = {};
int edgel[200000] = {};
int edger[200000] = {};
int n, m;
bool bipartite;

void dfs(int v, int c) {
    if (!colors[v]) {
        colors[v] = c;
        for (auto x : g[v]) {
            dfs(x, c%2+1);
        }
    } else {
        if (colors[v] != c) {
            bipartite = false;
        }
    }
}


int main() {
    int y, x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &y, &x);
        y--;x--;
        g[y].push_back(x);
        g[x].push_back(y);
        edgel[i] = y;
        edger[i] = x;
    }
    bipartite = true;
    dfs(0,1);
    if (!bipartite) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
        for (int i = 0; i < m; i++)
            printf("%d", colors[edgel[i]] < colors[edger[i]]);
    }
    return 0;
}
