#include <cstdio>
using namespace std;
const int maxM = 100;

int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};

int A, M;
struct power {
    int x;
    int y;
    int d;
    int p;
};
power powers[8] = {};
int arr[maxM] = {};
int brr[maxM] = {};

int abs(int n) {
    if (n > 0)  return n;
    return -n;
}

int getMax(int ay, int ax, int by, int bx) {
    int result = 0;
    bool visit[10] = {};
    int curPower = 0;
    int curidx = 9;
    for (int i = 0; i < A; i++) {
        if (!visit[i] && abs(powers[i].y -ay) + abs(powers[i].x-ax) <= powers[i].d) {
            if (curPower < powers[i].p) {
                visit[curidx] = false;
                visit[i] = true;
                curidx = i;
                curPower = powers[i].p;
            }
        }
    }
    result += curPower;
    curPower = 0;
    curidx = 9;
    for (int i = 0; i < A; i++) {
        if (!visit[i] && abs(powers[i].y -by) + abs(powers[i].x-bx) <= powers[i].d) {
            if (curPower < powers[i].p) {
                visit[curidx] = false;
                visit[i] = true;
                curidx = i;
                curPower = powers[i].p;
            }
        }
    }
    result += curPower;


    for (int i = 0; i < 10; i++) visit[i] = false;
    curPower = 0;
    int result2 = 0;
    curidx = 9;
    for (int i = 0; i < A; i++) {
        if (!visit[i] && abs(powers[i].y -by) + abs(powers[i].x-bx) <= powers[i].d) {
            if (curPower < powers[i].p) {
                visit[curidx] = false;
                visit[i] = true;
                curidx = i;
                curPower = powers[i].p;
            }
        }
    }
    result2 += curPower;
    curPower = 0;
    curidx = 9;
    for (int i = 0; i < A; i++) {
        if (!visit[i] && abs(powers[i].y -ay) + abs(powers[i].x-ax) <= powers[i].d) {
            if (curPower < powers[i].p) {
                visit[curidx] = false;
                visit[i] = true;
                curidx = i;
                curPower = powers[i].p;
            }
        }
    }
    result2 += curPower;
    if (result > result2) {
        return result;
    }
    return result2;
}

int main() {
    freopen("battery_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d", &M, &A);
        for (int i = 0; i < M; i++) scanf("%d", &arr[i]); 
        for (int i = 0; i < M; i++) scanf("%d", &brr[i]);
        for (int i = 0; i < A; i++) {
            scanf("%d %d %d %d", &powers[i].x, &powers[i].y, &powers[i].d, &powers[i].p);
        }
        int result = getMax(1,1,10,10);
        int ay = 1, ax = 1;
        int by = 10, bx = 10;
        for (int i = 0; i < M; i++) {
            ay += dy[arr[i]];
            ax += dx[arr[i]];
            by += dy[brr[i]];
            bx += dx[brr[i]];
            result += getMax(ay, ax, by, bx);
        }
        printf("#%d %d\n", tc+1, result);

    }


    return 0;
}
