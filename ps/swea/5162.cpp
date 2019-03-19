#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, A, B, C;
    cin >> T;
    for (int  tc = 0; tc < T; tc++) {
        cin >> A >> B >> C; 
        int a=0, ca = 1, cb = 1,b=0, now=0;
        for (int i = 1; i < C+1; i++) {
            if (i-(A)*ca >=0) {
                now = max(now, a+1);
                a = now;
                ca++;
            } 
            if (i - (B)*cb >=0) {
                now = max(now, b+1);
                b = now;
                cb++;
            }
        }
        cout << "#" << tc+1 << " " << now << endl;
    }
    return 0;
}
