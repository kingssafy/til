#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, temp, search, maxa;
    int nums[7];
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        maxa = 0;
        bool array[301] = {0};
        for (int i = 0; i < 7; i++) {
            cin >> nums[i];
        } 
        int b = 0;
        int c = 2*2*2*2*2*2*2-1; //change 2^6 to 2^7 
        do {
            if (__builtin_popcount(b) == 3) {
                temp = 0;
                for (int e = 6; e >=0; e--) {
                    if ((1<<e)&b) {
                        temp+= nums[e];
                    }
                } 
                array[temp] = true;
                maxa = max(maxa, temp);
            }
        } while((b=(b-c)&c));
        search = 5;
        for (int i = maxa; i >= 0; i--) {
            if (array[i]) search--;
            if (search==0) {
                cout << "#" << tc+1 << " " << i << endl;
                break;
            }
        }


    }

}
