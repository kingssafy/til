// 1138A
// INMAK
// feel free to contact me: jchrys@me.com

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("1138A_input.txt");
    int N, tray;
    int flag = 0, tuna= 0, eel = 0;
    int result = 0, temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tray;
        if (flag == 0) {flag = tray;}
        if (flag != tray) {
            temp = min(tuna, eel);
            result = max(result, temp);
            flag = tray;
            if (tray == 1) {
                tuna = 0;
            } else {
                eel = 0;
            }
        }
        if (tray == 1) { tuna++; }
        if (tray == 2) { eel++; }
    }
    temp = min(tuna, eel);
    result = max(result, temp);
    cout << result*2;
    return 0;
}
