#include <iostream>
#include <fstream>
#define ll long long
using namespace std;

int main() {
    ifstream cin("in.txt");
    int T;
    int N, M;
    ll array[100000] = {};
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N >> M;
        ll imax = 0LLU;
        for (int i = 0; i < N; i++) {
            cin >> array[i]; 
            imax = max(imax, array[i]);
        }

        ll low = 1;
        ll mid;
        ll high = imax*M;
        while (low < high) {

            mid = (low + high)/2;
            ll sum = 0;
            for (int i = 0; i < N; i++) {
                sum += (mid/array[i]);
            } 
            if (sum >= M) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        cout << "#" << tc+1 << " " << high << endl;
    }
    return 0;
}
