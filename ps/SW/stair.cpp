#include <iostream>
#include <algorithm>
using namespace std;
int N;
struct P {
    int y;
    int x;
    int d0;
    int d1;
};
struct S {
    int y;
    int x;
    int h;
};
struct sub{
    int t;
    int h;
};
sub sub1[10];
sub sub2[10];
P ppl[10];
S stairs[10];
int result;
int pc, sc;
int abs(int a) {
    if (a > 0) return a;
    return -a;
}

void dfs(int total, int a, int b) {
    if (total == pc) {
        for (int i = 0; i < 10; i++) {
            sub1[i].h = stairs[0].h;
            sub2[i].h = stairs[1].h;
        } 
        cout << endl;
        int res1, res2;
        bool flag = true;
        int time = 0;
        while (flag) {
            flag = false;
            int counter = 0; 
            for (int i = 0; i < a; i++) {
                if (sub1[i].h == 0) continue;
                flag = true;
                if (sub1[i].t < time) {
                    sub1[i].h--;
                    counter++;
                    if (counter == 3) break;
                } 
            }
            if (flag) time++;
        } 
        res1 = time;
        flag = true;
        time = 0;
        while (flag) {
            flag = false;
            int counter = 0; 
            for (int i = 0; i < b; i++) {
                if (sub2[i].h == 0) continue;
                flag = true;
                if (sub2[i].t < time) {
                    sub2[i].h--;
                    counter++;
                    if (counter == 3) break;
                } 
            }
            if (flag) time++;
        } 
        res2 = time;
        cout << "res1: " << res1 << " " << "Res2: " << res2 << endl;
        cout << a << ", " << b << endl;
        result = min(max(res1, res2), result);

    } else {
        sub1[a].h = stairs[0].h;
        sub1[a].t = ppl[total].d0;
        dfs(total + 1, a+1, b);
        sub2[a].h = stairs[1].h;
        sub2[a].t = ppl[total].d1;
        dfs(total + 1, a, b+1);
    }
}

int main() {
    freopen("lunch_input.txt", "r", stdin);
    int T, temp;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        pc = 0, sc = 0;
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++) {
                cin >> temp;
                if (temp == 0) continue;
                if (temp == 1) {
                    ppl[pc++] = {y, x, 0, 0};
                } else {
                    stairs[sc++] = {y, x, temp};
                }
            }
        for (int i = 0; i < pc; i++) {
            ppl[i].d0 = abs(ppl[i].y - stairs[0].y) + abs(ppl[i].x - stairs[0].x);
            ppl[i].d1 = abs(ppl[i].y - stairs[1].y) + abs(ppl[i].x - stairs[1].x);
        }
        result = 999999;
        dfs(0,0,0);
        cout << "#" << tc+1 << " " << result << endl;
    }
    return 0;
}
