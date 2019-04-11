#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int const MAXV = 20001, MAXE = 300001;
    int const INF = 2e9;
    int dis[MAXV];
    bool processed[MAXV] = {};
    vector<pair<int, int>> adj[MAXV];
    int V, E, u, v, w, sv;
    cin >> V >> E >> sv;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w; 
        u--;v--;
        adj[u].push_back({v, w});
    }
    sv--;
    for (int i = 0; i < V; i++) dis[i] = INF;
    dis[sv] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, sv});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u: adj[a]) {
            int b = u.first, w = u.second;
            if (dis[b] > dis[a]+w) {
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (dis[i] != INF) {
            cout << dis[i] << endl;
            continue;
        }
        cout << "INF" << endl;
    }
    
    
    return 0;
}
