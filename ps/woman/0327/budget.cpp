#include <iostream>
#include <fstream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("budget_input.txt");
    ll N, M, temp=0,maximum = 0;
    ll array[10001] = {};
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> array[i];
        temp += array[i];
        maximum = max(maximum, array[i]);
    }
    cin >> M;
    if (temp <= M) {
        cout << maximum; 
        return 0;
    }
    ll x = 0;
    for (int b = M; b >= 1; b/=2) {
        bool flag = true;
        while (flag) {
            flag = false;
            temp = 0;
            for (int i = 0; i < N; i++) temp += min(x + b, array[i]); 
            if (temp <= M) {
                x+= b;
                flag = true;
            }
        }
    }
    cout << x;

    return 0;
}
