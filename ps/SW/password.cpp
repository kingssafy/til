#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
int arr[28];

int main() {
    freopen("password_input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N, K, m, temp;
        set<int> s;
        cin >> N >> K;
        m = N/4;
        for (int i = 0; i < N; i++)
            scanf("%1x", &arr[i]);
        for (int l = 0; l < m; l++) {
            temp = arr[N-1];
            for (int n = N-1; n > 0; n--) {
                arr[n] = arr[n-1];
            }
            arr[0] = temp;
            for (int i = 0; i < 4; i++) {
                temp = 0;
                for (int j = 0; j < m; j++) {
                    temp = temp*16 + arr[i*m+j];
                }
                s.emplace(temp);
            }
        }
        int goal = (int) s.size() - K;
        int count = 0;
        auto x = s.begin();
        while (count != goal) {
            count++;
            x++;
        } 
        cout << "#" << tc+1 << " " << *x << endl;



    }
    
    return 0;
}
