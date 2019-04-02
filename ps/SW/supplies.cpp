#include <bits/stdc++.h>
using namespace std;

//template <typename T1, typename T2>
//class pair {
//public:
//    T1 first;
//    T2 second;
//
//    bool operator <(const pair<T1, T2> &a) {
//        if (first == a.first)
//            return second < a.second;
//        return first < a.first;
//    }
//};
const int MAX = 100;
struct P {
    int y;
    int x;
};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int grid[MAX][MAX] = {};
int d[MAX][MAX] = {};
bool p[MAX][MAX] = {};
int N;



int djik() {
    priority_queue<pair<int, pair<int, int>>> q;    
    q.push({0, {0, 0,}});
    d[0][0] = 0;
    while (!q.empty()) {
        int y = q.top().second.first;
        int x = q.top().second.second;
        q.pop();
        if (y == N-1 && x == N-1) return d[N-1][N-1];
        if (p[y][x]) continue;
        p[y][x] = true;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || nx >= N || ny >= N) continue;
            if (d[ny][nx] > d[y][x] + grid[ny][nx]) {
                d[ny][nx] = d[y][x] + grid[ny][nx];
                q.push({-d[ny][nx], {ny, nx}});
            }
        }

    }
    return -1;
}



int main() {
    freopen("supplies_input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++) {
                scanf("%1d", &grid[y][x]);
                p[y][x] = false;
                d[y][x] = 217463532;
            }
        int result = djik();
        cout << "#" << tc+1 << " " << result << endl;
    }

    return 0;
}

