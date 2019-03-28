#include <iostream>
#include <cstdio>

using namespace std;
int power(int n, int e) {
    int result = 1;
    for (int i = 0; i < e; i++) {
        result = result*n;
    }
    return result;
}
int magnets[5][8] = {};
int nextmagnets[5][8] = {};

void rotate(int num, int clock) {
    if (clock == 1) {
        int temp, j = 7;
        temp = magnets[num][j];
        while (j > 0) {
            nextmagnets[num][j] = magnets[num][j-1];
            j--;
        }
        nextmagnets[num][j] = temp;
    } else {
        int temp, j = 0;
        temp = magnets[num][j];
        while (j < 7) {
            nextmagnets[num][j] = magnets[num][j+1];
            j++;
        }
        nextmagnets[num][j] = temp;
    }
}

void bfs(int num, int clock) {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 8; x++) {
            nextmagnets[y][x] = magnets[y][x];
        }
    }
    int dn[2] = {-1, 1};
    int Qn[4] = {};
    int Qc[4] = {};
    bool visit[5] = {true, false, false, false, false};
    int front = 0, rear = 0;
    Qn[rear] = num;
    Qc[rear++] = clock;
    while (front < rear) {
        int n = Qn[front];
        int c = Qc[front++];
        for (int i = 0; i < 2; i++) {
            int next_n = n+dn[i];
            int next_c = -c;
            if (!visit[next_n] && magnets[n][4-dn[i]*2] != magnets[next_n][4+dn[i]*2] && next_n < 5) { //magnets[4+dn[i]]*2 gives me wrong answer T^T;
                visit[next_n] = true;
                Qn[rear] = next_n;
                Qc[rear++] = next_c;
            }
        }
        rotate(n, c);
    }

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 8; x++) {
            magnets[y][x] = nextmagnets[y][x];
        }
    }
}




int main() {
    freopen("magnet_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        int K;
        scanf("%d", &K);
        for (int j = 1; j < 5; j++){
            for (int i = 0; i < 8; i++) {
                scanf("%d", &magnets[j][i]);
            }
        }
        int num, clock;
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &num, &clock);
            bfs(num, clock);
//            printf("%d %d\n", num, clock);
//            for (int j = 1; j < 5; j++){
//                for (int i = 0; i < 8; i++) {
//                    printf("%d ", magnets[j][i]);
//                }
//                printf("\n");
//            }
        } 
        int result = 0;
        for (int i = 1; i < 5; i++) {
            if (magnets[i][0] == 1) {
                result += power(2, i-1);
            }
        }

        printf("#%d %d\n", tc+1, result);

    }
}
