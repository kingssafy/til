#include <iostream>
using namespace std;
const int MAXN = 10, MAXT = 70;
struct P {
    int y;
    int x;
};
int answer;
P mans[10];
P stairs[2];
int grid[MAXN][MAXN];
int N, M, S;
int paring[10];

int abs(int a) {
    if (a > 0) return a;
    return -a;
}

int dis(int mi, int si) {
    int dy = abs(mans[mi].y - stairs[si].y);
    int dx = abs(mans[mi].x - stairs[si].x);
    return dy+dx;
}    

void update() {
    int result = 0;
    for (int si = 0; si < 2; si++) {
        int mintime = 0; 
        int toa[2*MAXN+1] = {};
        int cur_walk[MAXT] = {};
        for (int i = 0; i < M; i++) {
            if (paring[i] == si) {
                toa[dis(i, si) + 1]++;
            }
        }

        for (int i = 0; i < 2 * MAXN + 1; i++) {
            while (toa[i]) {
                toa[i]--;
                int remain = grid[stairs[si].y][stairs[si].x];
                for (int time = i; time < MAXT; time++) {
                    if (cur_walk[time] < 3) {
                        cur_walk[time]++;
                        remain--;
                        if (!remain) {
                            mintime = max(mintime, time+1);
                            break;
                        }
                    }
                }
            }
        }
        result = max(result, mintime);
    }
    answer = min(answer, result);
}

void dfs(int depth) {
    if (depth == M) {
        //TODO
        update();
    } else {
        for (int i = 0; i < 2; i++) {
            paring[depth] = i;
            dfs(depth + 1);
        }
    }


}



int main() {
    freopen("lunch_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N; 
        M = S = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> grid[y][x];
                if (grid[y][x] == 1) {
                    mans[M++] = {y, x}; 
                    continue;
                }
                if (grid[y][x] >= 2) {
                    stairs[S++] = {y, x};
                }
            }
        }
        answer = 1e9;
        dfs(0);
        cout << "#" << tc+1 << " " << answer << endl;

    }



    return 0;
}
