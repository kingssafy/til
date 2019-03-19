#include <iostream>

using namespace std;

template <typename T1, typename T2>
class _pair {
public:
    T1 first;
    T2 second;

    bool operator<(const _pair<T1, T2> &a) {
        if (first == a.first)
            return second < a.second;
        return first < a.first;
    }
};
struct P {
    int x, y;
};

int main() {
    int T, N, temp;
    int grid[101][101] = {};
    int length[101][101] = {};
    _pair<int, P> con[10001] = {};
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> temp;
                grid[x][y] = temp;
                 
            }
        }

    }
    
    return 0;
}
