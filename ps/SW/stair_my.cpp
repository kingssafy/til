#include <iostream>
using namespace std;

struct P {
    int y;
    int x;
};

P ppl[10] = {};
P stairs[2] = {};
int grid[10][10];
int N, pc = 0 , sc=0;
int match[10] = {};
int result;

int abs(int a) {
    if (a > 0) return a;
    return -a;
}
int getDis(P a, P b) {
    return abs(a.x - b.x) + abs(a.y-b.y);
}


void update() {
    int total_min_time = 0;
    for (int stair = 0; stair < 2; stair++) {
        int arrivtime[20] = {}; 
        int use_stair[40] = {};
        int cur_min_time = 99999;
        int time, remain;
        for (int i = 0; i < pc; i++) {
            if (match[i] == stair) arrivtime[getDis(ppl[i], stairs[stair]) + 1]++;
        }
        for (int i = 0; i < 20; i++) {
            while (arrivtime[i]) {
                arrivtime[i]--; 
                remain = grid[stairs[stair].y][stairs[stair].x];
                for (time = i; time < 40; time++) {
                    if(use_stair[i] < 2) {
                        use_stair[i]++;
                        remain--;
                    }
                    if (!remain) break;
                }
            }
            cur_min_time = min(cur_min_time, time+1);
            cout << cur_min_time << endl;
        }
        total_min_time = max(total_min_time, cur_min_time); 

    }
    result = min(result, total_min_time);
}

void dfs(int idx) {
    if (idx == pc) {
        update();
    } else {
        for (int i = 0; i < 2; i++) {
            match[idx] = i;
            dfs(idx+1);
        }
    }
}

int main() {
    freopen("lunch_input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 0; tc < 1; tc++) {
        cin >> N;
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++) {
                cin >> grid[y][x];
                if (grid[y][x] == 1) {
                    ppl[pc++] = {y, x}; 
                    continue;
                }
                if (grid[y][x] >= 2) {
                    stairs[sc++] = {y, x};
                }
            }
        result = 1e9;
        dfs(0);
        cout << "#" << tc+1 << " " << result << endl;
    } //T

    return 0;
}
