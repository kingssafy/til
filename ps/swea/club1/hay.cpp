#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int array[10000] = {0};
    int T, N, result, sum, temp, mean;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        result = 0;
        sum = 0;
        for (int k = 0; k < N; k++) {
            cin >> temp;
            array[k] =temp;
            sum += temp; 
        }
        mean = sum/N;
        for (int i = 0; i < N; i++) {
            temp = array[i] - mean;
            if (temp > 0) {
                result += temp;
            }
        }
        cout << "#" << tc+1 << " " << result << endl;
    }
    return 0;
}
