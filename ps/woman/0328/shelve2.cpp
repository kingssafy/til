#include <cstdio>
#include <set>

using namespace std;

int main() {
    int T, N, B;
    int arr[20] = {};
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d", &N, &B);
        int sum = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        set<int> s;
        s.emplace(sum);
        for (int i = 0; i < N; i++) {
            auto end = s.end(); 
            for (auto it = s.begin(); it != end; it++) {
                s.emplace(*it-arr[i]);
            }
        }
        
        for (auto x : s) {
            if (x >= B) {
                printf("%d\n", x-B);
                break;
            }
        }
        

    }
    return 0;
}
