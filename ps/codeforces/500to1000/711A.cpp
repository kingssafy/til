#include <iostream>
using namespace std;
int const MAXN = 1000;
char grid[MAXN][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    char temp;
    char before;
    bool flag=true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 0) {
                cin >> before;
                grid[i][j] = before;
                continue;
            }
            cin >> temp;
            grid[i][j] = temp;
            if (before == 'O' && temp == 'O' && flag) {
                grid[i][j-1] = '+';
                grid[i][j] = '+';
                flag = false;
            } 
            before = temp;

        }
    }
    if (!flag) {
        cout << "YES" << "\n";
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < 5; x++) {
                cout << grid[y][x];
            }
            cout << "\n";
        }
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}
