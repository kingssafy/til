#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int sum = 0;
        int num;
        for(int i=0; i<10; i++) {
            cin >> num;
            sum += num;
        }
        long result = round(sum/10.0);
        cout << "#" << t << " " << result<< endl;
    }
}
