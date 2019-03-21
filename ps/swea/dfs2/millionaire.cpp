#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("millionaire_input.txt");
    int T, N, array[1000000] = {};
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> array[i]; 
        }
        int max = 0;
        long long result = 0LLU;
        for (int i = N-1; i >= 0; i--) {
            if (array[i] > max) {
                max = array[i];
            } else {
                result += max-array[i];
            }
        }
        cout << "#" << tc << " " << result << endl;
        
    }
}
