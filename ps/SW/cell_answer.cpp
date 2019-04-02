#include <iostream>
using namespace std;

#define MAXL 352

struct data_type {
    // 0: empty, 1: no active, 2: active, 3: dead;
    int Status;
    //LP: Life Point
    //HP: dead at 0, increase when not activated, dec when active;
    int LP, HP;
};

int T, N, M, K;
data_type Map[2][MAXL][MAXL];

int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

int main() {
    freopen("cell_input.txt", "r", stdin);

    setbuf(stdout, NULL);
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M >> K;
        //init
        for (int i = 0; i < N+K+2; i++)
            for (int j = 0; j < M + K + 2; j++) {
                Map[0][i][j].Status = 0;
                Map[1][i][j].Status = 0;
            }
        // initial cells Life point
        for (int i = 0 + K / 2 + 1; i < N + K / 2 + 1; i++)
            for (int j = 0 + K / 2 + 1; j < M + K / 2 + 1; j++) {
                cin >> Map[0][i][j].LP;
                if (Map[0][i][j].LP > 0) {
                    Map[0][i][j].Status = 1;
                    Map[0][i][j].HP = 0;
                }

            }
        N = N + K + 2;
        M = M + K + 2;

        int CurMap = 0;
        for (int k = 0; k < K; k++) {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                    //if dead cell
                    if (Map[CurMap][i][j].Status == 0) continue;
                    if (Map[CurMap][i][j].Status == 3) {
                        Map[1-CurMap][i][j].Status = Map[CurMap][i][j].Status;
                        continue;
                        // if not activated
                    } else if (Map[CurMap][i][j].Status == 1) {
                        // time add
                        Map[1-CurMap][i][j].HP = Map[CurMap][i][j].HP + 1;
                        Map[1-CurMap][i][j].LP = Map[CurMap][i][j].LP;

                        //if time elapsed LP
                        if (Map[1 - CurMap][i][j].HP == Map[1 - CurMap][i][j].LP)
                            //activate it
                            Map[1 - CurMap][i][j].Status = 2;
                        else
                            Map[1 - CurMap][i][j].Status = 1;

                        // if activated
                    } else if (Map[CurMap][i][j].Status == 2) {
                        // if first
                        if (Map[CurMap][i][j].HP == Map[CurMap][i][j].LP) { //go
                            for (int d = 0; d < 4; d++) {
                                int i2 = i + dir[d][0];
                                int j2 = j + dir[d][1];

                                if (Map[CurMap][i2][j2].Status == 0) {

                                    // first
                                    if (Map[1 - CurMap][i2][j2].Status == 0) {
                                        Map[1 - CurMap][i2][j2].Status = 1;
                                        Map[1 - CurMap][i2][j2].LP = Map[CurMap][i][j].LP;
                                        Map[1 - CurMap][i2][j2].HP = 0;
                                        // if im second
                                    } else if (Map[1 - CurMap][i2][j2].Status == 1 && 
                                            Map[1-CurMap][i2][j2].LP < Map[CurMap][i][j].LP) {
                                        Map[1 - CurMap][i2][j2].LP = Map[CurMap][i][j].LP;
                                    }
                                }
                            }
                        }

                        // time elapse
                        Map[1 - CurMap][i][j].HP = Map[CurMap][i][j].HP - 1;
                        if (Map[1 - CurMap][i][j].HP == 0)
                            // dead
                            Map[1 - CurMap][i][j].Status = 3;
                        else
                            Map[1-CurMap][i][j].Status = 2;
                    }

                }
            //Map change
            CurMap = 1 - CurMap;
        }
        int Answer = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) 
                if (Map[CurMap][i][j].Status == 1 || Map[CurMap][i][j].Status == 2) 
                    Answer++;

        cout << "#" << tc << " " << Answer << endl;




    }
    return 0;
}
