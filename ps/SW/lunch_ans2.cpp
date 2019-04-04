#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int MAXN = 11;
const int MAXT = MAXN*2 + MAXN*MAXN;

struct PT {
    int r, c;
};
PT stair[2];
PT man[10];
int N, M, S;
int map[MAXN][MAXN];
int match[MAXN], answer;
int abs(int a) {
    if (a > 0) return a;
    return -a;
}

int dist(int man_index, int stair_index) {
    int dx = abs(man[man_index].r - stair[stair_index].r);
    int dy = abs(man[man_index].c - stair[stair_index].c);
    return dy+dx;
}

void update() {
    int total_min_time = 0;
    for (int stair_index = 0; stair_index < 2; stair_index++) {
        PT &now_stair = stair[stair_index];
        int arrival_time[MAXN*2] = {0, };
        int current_stair[MAXT] = {};
        for (int man_index = 0; man_index < M; man_index++) {
            if (match[man_index] == stair_index) {
                arrival_time[dist(man_index, stair_index) + 1]++;
            }
        }

        int now_min_time = 0;
        for (int time = 1; time <= 20; time++) {

            while (arrival_time[time] > 0) {
                arrival_time[time]--;

                int remain_time = map[now_stair.r][now_stair.c];

                for (int walk_time = time; walk_time < MAXT; walk_time++)
                    if (current_stair[walk_time] < 3) {

                        current_stair[walk_time]++;
                        remain_time--;
                        if (remain_time == 0) {
                            now_min_time = max(now_min_time, walk_time +1);
                            break;
                        }
                    }
            }
        }
        total_min_time = max(now_min_time, total_min_time);
    }
    answer = min(answer, total_min_time);
}


void dfs(int depth) {
    if (depth == M) {
        update();
        return;
    } else {
        for (int i = 0; i < 2; i++) {
            match[depth] = i;
            dfs(depth+1);
        }
    }
}

int main() {
    freopen("lunch_input.txt", "r" ,stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d", &N);
        M = S = 0;
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                scanf("%d", &map[y][x]);
                if (map[y][x] == 1) man[M++] = {y, x};
                if (map[y][x] >= 2) stair[S++] = {y, x};
            }
        }
        answer = 1e9;
        dfs(0);
        printf("#%d %d\n", tc+1, answer);
    }
}
