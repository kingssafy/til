#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("5215.txt");
    int T, N, L, s, c;
    int savory[20] = {0};
    int calorie[20] = {0};
    bool possible[10001] = {false};
    int maxscore[10001] = {false};
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int W = 0;
        cin >> N >> L;
        for (int i = 0; i < N; i++) {
            cin >> s >> c;
            savory[i] = s;
            calorie[i] = c;
            W += c;
        }
        possible[0] = true;
        
        for (int k = 0; k < N; k++) {
            for (int l = L - calorie[k]; l >= 0; l--) {
                possible[l+calorie[k]] |= possible[l];
                if (possible[l+calorie[k]]) {
                    maxscore[l+calorie[k]] = max(maxscore[l+calorie[k]], maxscore[l] + savory[k]);
                }
            }
        }
        int result = 0;
        for (int i = 0; i <= L; i++) {
            result = max(result, maxscore[i]);
        }
        cout << "#" << tc+1 << " " << result << endl;
        
         
    }




    return 0;
}
