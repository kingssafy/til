#include <cstdio>
#include <vector>
using namespace std;
int const MAXN = 10001;
int r[MAXN] = {};
int p[MAXN] = {};
int s[MAXN] = {};
int N;
int result = 0;
int endnode= -1;
vector<pair<int, int>> adj[MAXN];

void dfs(int pn, int curSum) {
    if (adj[pn].empty()) {
        if (result < curSum) {
            result = curSum;
            endnode = pn;
        }
    } else {
        for (auto v: adj[pn]) {
            int cn = v.first, w = v.second;
            dfs(cn, curSum+w);
        } 
    }
}
int main() {
    scanf("%d", &N);
    int u, v, w;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--;v--;
        adj[u].push_back({v, w});
        p[v] = u;
        s[v] = w;
    }
    p[0] = -1;
    return 0;
}
