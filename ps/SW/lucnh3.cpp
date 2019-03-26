#include <cstdio>
#include <iostream>
using namespace std;
struct stairCase {
    int y;
    int x;
    int t;
};
struct man {
    int y;
    int x;
    int t0;
    int t1;
};

struct stair {
    int arrival;
    int steps;
};

int N;
int manCnt;
stair fStair[10];
stair sStair[10];
stairCase stairCases[2]={};
man mans[10];
int programChecker = 9999;


void dfs(int fCounter, int sCounter, stair fStair[10], stair sStair[10]) {
    if (fCounter + sCounter == manCnt) {
        for (int i = 0; i < fCounter; i++) {
            fStair[i].steps = stairCases[0].t;
        }
        for (int i = 0; i < sCounter; i++) {
            sStair[i].steps = stairCases[1].t;
        }
        int flag = 1;
        int initial = 999;
        for (int i = 0; i < fCounter; i++) {
            initial = min(initial, fStair[i].arrival);
        }
        int time = 0;
        int fmin = 0; int smin = 0;
        while (flag) {
            int counter = 0;
            for (int i = 0; i < fCounter; i++) {
                if (initial+time >= fStair[i].arrival && fStair[i].steps > 0) {
                    fStair[i].steps--;
                    counter++;
                    if (counter >= 3) break;
                }
            }
            if (counter == 0) {
                flag = 0;
                for (int k = 0; k < fCounter; k++) {
                    if (fStair[k].steps > 0) flag = 1;
                }
            }
            if (flag == 0) fmin = initial +time;
            time ++;
        } 
        flag = 1;
        time = 0;

        initial = 999;
        for (int i = 0; i < sCounter; i++) {
            initial = min(initial, sStair[i].arrival);
        }
        while (flag) {
            int counter = 0;
            for (int i = 0; i < sCounter; i++) {
                if (initial+time >= sStair[i].arrival && sStair[i].steps > 0) {
                    sStair[i].steps--;
                    counter++;
                    if (counter >= 3) break;
                }
            }
            if (counter == 0) {
                flag = 0;
                for (int k = 0; k < sCounter; k++) {
                    if (sStair[k].steps > 0) flag = 1;
                }
            }
            if (flag == 0) smin = initial +time;
            time ++;
        } 
        programChecker = min(programChecker, max(smin, fmin));
        cout << smin << " " << fmin << endl;
        




    }  else {
        fStair[fCounter].arrival = mans[fCounter+sCounter].t0;
        fStair[fCounter].steps = stairCases[0].t; 
        dfs(fCounter + 1, sCounter, fStair, sStair);
        sStair[sCounter].arrival = mans[fCounter+sCounter].t1;
        sStair[sCounter].steps = stairCases[1].t;
        dfs(fCounter, sCounter+1, fStair, sStair);
    }
}






int main() {
    freopen("lunch_input.txt", "r", stdin);
    int T, temp;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d",  &N);
        manCnt = 0;
        int stairCnt = 0;
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++) {
                scanf("%d", &temp);
                if (temp == 1) {
                    mans[manCnt].y = y;
                    mans[manCnt++].x = x;
                } else if (temp >= 2) {
                    stairCases[stairCnt].y = y;
                    stairCases[stairCnt].x = x;
                    stairCases[stairCnt++].t = temp;
                }
            }
        for (int i = 0; i < manCnt; i++) {
            mans[i].t0 = abs(stairCases[0].y - mans[i].y) + abs(stairCases[0].x - mans[i].x);
            mans[i].t1 = abs(stairCases[1].y - mans[i].y) + abs(stairCases[1].x - mans[i].x);
        }
        programChecker = 999;
        dfs(0, 0, fStair, sStair);
        cout << "#" << tc+1 <<  " " << programChecker << endl;


    }

}
