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
        int fInitial=999, sInitial=999;
        int fTotal, sTotal;
        for (int i = 0; i < fCounter; i++) {
            fInitial = min(fInitial, fStair[i].arrival);
            fStair[i].steps = stairCases[0].t;
        }
        for (int i = 0; i < sCounter; i++) {
            sInitial = min(sInitial, sStair[i].arrival);
            sStair[i].steps = stairCases[1].t;
        }
        int flag = 1;
        int timer = 0;
        while (flag) {
            timer+=1;
            int pCounter = 0;
            for (int i = 0; i < fCounter; i++) {
                if (fStair[i].arrival < fInitial+timer && fStair[i].steps > 0) {
                    fStair[i].steps--;
                    pCounter++;
                }
                if (pCounter ==3) {
                    break;
                }
            }
            if (pCounter==0) {
                flag = 0;
                for (int i = 0; i < fCounter; i++) {
                    if (fStair[i].steps > 0) flag = 1;
                }
                if (flag ==0) {
                    fTotal = fInitial + timer;
                }
                //                printf("sInitial: %d, timer: %d, sTotal: %d\n", sInitial, timer, sTotal);
                //                cout << sCounter << endl;
            }
        }
        flag = 1;
        timer = 0;
        while (flag) {
            timer += 1;
            int pCounter = 0;
            for (int i = 0; i < sCounter; i++) {
                //                printf("sStair[i].arrival:%d, sStair[i].steps: %d\n", sStair[i].arrival, sStair[i].steps);
                if (sStair[i].arrival < sInitial+timer && sStair[i].steps > 0) {
                    sStair[i].steps--;
                    pCounter++;
                }
                if (pCounter ==3) {
                    break;
                }
            }
            if (pCounter==0) {
                flag = 0;
                for (int i = 0; i < sCounter; i++) {
                    if (sStair[i].steps > 0) flag = 1;
                }
                if (flag ==0) {
                    sTotal = sInitial + timer;
                }
                //                printf("sInitial: %d, timer: %d, sTotal: %d\n", sInitial, timer, sTotal);
                //                cout << sCounter << endl;
            }
        }
        programChecker = min(programChecker,max(fCounter == 0 ? 0 : fTotal, sCounter == 0 ? 0 : sTotal));
//        cout << "#" <<  max(fCounter == 0 ? 0 : fTotal, sCounter == 0 ? 0 : sTotal) << endl; 
        //        cout << fInitial << " " << sInitial << endl;
        //        cout << fTotal << " " << sTotal << endl;
//                for (int i = 0; i < fCounter; i++) {
//                    cout << fStair[i].arrival << " ";
//                }
//                    cout << endl;
//                for (int i = 0; i <sCounter; i++) {
//                    cout << sStair[i].arrival << " ";
//                }
//                cout << endl;



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
