#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;
int btd(bool code[7]) {
    int result = 0;
    for (int i = 0; i < 7; i++) {
        result = result*2+code[i];
    }
    return result;
}
int main() {
    freopen("bit_0318.txt", "r", stdin);
    int T, N, M, temp;
    scanf("%d", &T);
    int cypher[200] = {};
    bool code1[7] = {0,0,0,1,1,0,1};
    cypher[btd(code1)] = 0;
    bool code2[7] = {0,0,1,1,0,0,1};
    cypher[btd(code2)] = 1;
    bool code3[7] = {0,0,1,0,0,1,1};
    cypher[btd(code3)] = 2;
    bool code4[7] = {0,1,1,1,1,0,1};
    cypher[btd(code4)] = 3;
    bool code5[7] = {0,1,0,0,0,1,1};
    cypher[btd(code5)] = 4;
    bool code6[7] = {0,1,1,0,0,0,1};
    cypher[btd(code6)] = 5;
    bool code7[7] = {0,1,0,1,1,1,1};
    cypher[btd(code7)] = 6;
    bool code8[7] = {0,1,1,1,0,1,1};
    cypher[btd(code8)] = 7;
    bool code9[7] = {0,1,1,0,1,1,1};
    cypher[btd(code9)] = 8;
    bool code10[7] = {0,0,0,1,0,1,1};
    cypher[btd(code10)] = 9;

    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d", &N, &M);
        bool codes[5001] = {0};
        for (int i = 0; i < N*M; i++) {
            scanf("%1d", &temp);
            codes[i] = temp;
        }
        int array[8] = {0};
        for (int  i = N*M-1; i >=0; i--) {
            if (codes[i] == 1) {
                int start = i-55;
                int now = 0;
                int counter = 0;
                for (int k = start; k <= i; k++) {
                    array[now] = (array[now]<<1)|codes[k];
                    counter++;
                    if (counter == 7) {
                        now++;
                        counter = 0;
                    }
                } 
                break;
            }
        }
        int confirm = 0;
        int answer=0;
        for (int i = 0; i < 8; i++) {
            if (i%2) {
                confirm += cypher[array[i]];
                answer += cypher[array[i]];
                 
            } else {
                confirm += cypher[array[i]]*3;
                answer += cypher[array[i]];
            }
        }
        if (confirm%10 == 0) {

           cout << "#" << tc+1 << " " << answer << endl; 
        } else {

           cout << "#" << tc+1 << " " << 0 << endl; 
        }

    }
}

