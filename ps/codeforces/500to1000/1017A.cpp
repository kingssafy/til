#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int rank = 1;
    int thomas = 0;
    int temp;
    cin >> temp;
    thomas += temp;
    cin >> temp;
    thomas += temp;
    cin >> temp;
    thomas += temp;
    cin >> temp;
    thomas += temp;
    for (int i = 0; i < n-1; i++) {
        int sum = 0; 
        for (int j = 0; j < 4; j++) {
            cin >> temp;
            sum += temp;
        }
        if (sum > thomas) rank++;
    }
    cout << rank << "\n";
    return 0;
}
