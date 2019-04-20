#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 100001;
vector<int> adj[MAXN];
int node_id[MAXN] = {};
int depth[MAXN] = {};
bool visit[MAXN] = {};
int visitcounter = 0;

void dfs(int u) {
    visit[u] = true;
    
}



int main() {
    int n;
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    



    //QUERY
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
    }

    return 0;
}


