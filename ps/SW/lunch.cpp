#include <iostream>
#include <fstream>
using namespace std;
int grid[10][10] = {};
int minCounter = 0;
int N, counter=0;
struct man {
    int t1;
    int t2;
};
struct P{
    int y;
    int x;
    int t;
};
P positions[2] ={};
man mans[10] = {};

void solution (int fCounter, int sCounter,int iCounter, int fSubset[10][2], int sSubset[10][2]) {
    if (iCounter == counter) {
        //TODO
        //int fLast=fSubset[fCounter-1][0], sLast=sSubset[sCounter-1][0]; 
        // this gives me wrong answer; we need max;
        int fFirst=fCounter*999, sFirst=sCounter*999;
        for (int i = 0; i < fCounter; i++) {
            fFirst = min(fSubset[i][0], fFirst);
        }
        for (int i = 0; i < sCounter; i++) {
            sFirst = min(sFirst, sSubset[i][0]);
        }
        int fDone = 0, sDone = 0;
        int fC=0, sC = 0;
        int taketime = 0;
        int fTotal, sTotal;
        int flagger= 0;
        while (!fDone &&fCounter) {
            taketime++;
            fC = 0;
            for (int i = 0; i < fCounter; i++) {
                if (fSubset[i][1] > 0 && fFirst+taketime >= fSubset[i][0]) {
                    fSubset[i][1]--;
                    fC++; 
                if (fC >= 3) {
                    break; 
                }
                }
            }
            flagger =1;
            for (int i = 0; i < fCounter; i++) {
                if (fSubset[i][1] > 0) {
                    flagger = 0;
                }
            }
            if (flagger) fDone=1;
        }
        fTotal = fFirst+taketime;
        taketime = 0;
        
        while (!sDone && sCounter) {
            taketime++;
            sC = 0;
            for (int i = 0; i < sCounter; i++) {
                if (sSubset[i][1] > 0 && sFirst+taketime >= sSubset[i][0]) {
                    sSubset[i][1]--;
                    sC++; 
                if (sC >= 3) {
                    break; 
                }
                }
            }
            flagger =1;
            for (int i = 0; i < sCounter; i++) {
                if (sSubset[i][1] > 0) {
                    flagger = 0;
                }
            }
            if (flagger) sDone=1;
        }
        sTotal = sFirst+taketime;
        minCounter = min(minCounter, max(fTotal, sTotal)); 
    

} else {
    fSubset[fCounter][0] = mans[iCounter].t1;
    fSubset[fCounter][1] = positions[0].t;
    solution(fCounter+1, sCounter, iCounter+1, fSubset, sSubset);
    sSubset[sCounter][0] = mans[iCounter].t2;
    sSubset[sCounter][1] = positions[1].t;
    solution(fCounter, sCounter+1, iCounter+1,fSubset, sSubset);
}

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("lunch_input.txt");
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        int checker  = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> grid[y][x];
                if (grid[y][x] >= 2) {
                    positions[checker].y = y;
                    positions[checker].x = x;
                    positions[checker++].t = grid[y][x];

                }
            }
        }
        counter = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (grid[y][x] == 1) {
                    mans[counter].t1 = abs(positions[0].y-y) + abs(positions[0].x - x);
                    mans[counter++].t2 = abs(positions[1].y-y) + abs(positions[1].x - x);
                }
            }
        }
        minCounter = 99999999;
        int fSubset[10][2] = {};
        int sSubset[10][2] = {};
        solution (0, 0, 0, fSubset, sSubset);
        cout << minCounter << endl;



    }

        return 0;
}
