// Topological sort
// nodes : a,b,c,d,e,f
// directed edges are given
// for example
// if scottwu -> ooooo -> subscriber
// s -> o, o -> s 
// elif scottw -> step
// c->t
#include <string>
#include <iostream>
//#include <fstream>
#include <vector>
using namespace std;
int const maxc = 26;
int n;
string now;
string before;
vector<int> adj[maxc];
int sorted[maxc];
int process[maxc] = {};
int rear = 0;
bool possible = true;

void topoSort(int sn) {
    if (process[sn] == 2) return;
    process[sn] = 1;
    for (auto x: adj[sn]) {
        if (process[x] == 1) {
            possible = false;
            return;
        } 
        topoSort(x); 
    }
    process[sn] = 2;
    sorted[rear++] = sn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    ifstream cin("C_input.txt");
    cin >> n;
    cin >> before;
    for (int i = 0; i < n-1; i++) {
        cin >> now;
        for (int j = 0; j < min((int) before.size(), (int) now.size()); j++)  {
            if (before[j] != now[j]) {
                int b = before[j] - 'a';
                int n = now[j] - 'a';
                adj[b].push_back(n);
                before = now;
                break;
            }
            if (j == min((int) before.size(), (int) now.size())-1) {
                if (before.size() > now.size()) {
                    printf("Impossible\n");
                    return 0;
                }
            }
        }
        before = now;
    }
//    for (int i = 0; i < 26; i++) {
//        if (adj[i].size() == 0) continue;
//        topoSort(i, -1); 
//    }
    for (int i = 0; i < 26; i++) {
        if (process[i]) continue;
        topoSort(i);
    }
    if (!possible) {
        printf("Impossible\n");
        return 0;
    }
    for (int i = 25; i >= 0; i--) {
        printf("%c", sorted[i] + 'a');
    }
    return 0;
}
