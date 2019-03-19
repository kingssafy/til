#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("1138B.txt", "r", stdin);
    int n, temp; 
    scanf("%d", &n);
    bool clown[5001] = {false};
    bool acrob[5001] = {false};
    int count[4] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%1d", &temp); 
        clown[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        scanf("%1d", &temp); 
        acrob[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        temp = (clown[i] << 1) | acrob[i];
        count[temp]++;
    }
    int x0, x1, x2, x3;
    bool find = 0;
    int answer[4] = {0};
    for (x2 = 0; x2 < count[2]+1; x2++) {
        for (x3 = 0; x3 < count[3] +1; x3++) {
            x1 = count[1]+count[3]-2*x3-x2;
            if (x1 <0 || x1 > count[1]) continue;
            x0 = n/2 -x1 - x2 -x3;
            if (x0 < 0 || x0 > count[0]) continue;
            find = 1;
            answer[0] = x0;
            answer[1] = x1;
            answer[2] = x2;
            answer[3] = x3;
        }
    }
    if (find) {

        for (int i = 0; i < n; i++) {
            int value = (clown[i]<<1) | acrob[i];
            if(answer[value]) {
                cout << i+1 << " ";
                answer[value]--;
            }
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
