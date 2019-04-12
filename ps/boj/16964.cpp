#include <set>
#include <cstdio>
using namespace std;
int const MAXN = 100001;
set<int> adj[MAXN];
int stack[MAXN];
int rear = 0;
int N;
bool visited[MAXN] = {};

int main() {
    scanf("%d", &N);  
    int u, v;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &u, &v); 
        adj[u].emplace(v);
        adj[v].emplace(u);
    }
    int temp;
    scanf("%d", &temp);
    stack[rear++] = 1;
    for (int p = 0; p < N-1; p++) {
        scanf("%d", &temp);
        if (adj[stack[rear-1]].count(temp)) {
            adj[stack[rear-1]].erase(temp); 
            int parent = stack[rear-1];
            if (adj[stack[rear-1]].size() == 0) {
                rear--;
            } 
            if (adj[temp].size() > 1) {
                adj[temp].erase(parent);
                stack[rear++] = temp;
            }
        } else {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}
