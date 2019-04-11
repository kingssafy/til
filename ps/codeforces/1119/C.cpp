#include <iostream>
using namespace std;

int main() {
    //freopen("C_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int A[500][500], B[500][500];
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> A[y][x];
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> B[y][x];
        }
    }
    bool flag = 1;
    for (int y = 0; y < n; y++) {
        int temp = 0;
        int temp2 = 0;
        for (int x = 0; x < m; x++) {
            temp += A[y][x]; 
            temp2 += B[y][x];
        }
        if (temp %2 != temp2 %2) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        for (int x = 0; x < m; x++) {
                int temp = 0;
                int temp2 = 0;
            for (int y = 0; y < n; y++) {
                temp += A[y][x]; 
                temp2 += B[y][x];
            }
            if (temp %2 != temp2 %2) {
                flag = 0;
                break;
            }
        }

    }
    if (!flag) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

    return 0;
}
