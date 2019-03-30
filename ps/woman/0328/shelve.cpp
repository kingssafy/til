#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int N = 5;
int arr[20] = {3, 1, 3, 5, 6};

int main() {
    int T = 1, B = 16; 
    set<int> s;

    //scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        //        scanf("%d", &N);
        //        scanf("%d", &B);
        //        for (int i = 0; i < N; i++) {
        //            scanf("%d", &arr[i]);
        //        }
        s.emplace(123);
        for (auto x : arr) {
            auto end = s.end();
            cout << "end" << endl;
            cout << *end << endl; 
            for (auto it = s.begin(); it != end; it++) {
                cout << "endl " << *end << endl;
                cout << *it << endl; 
                s.emplace(*it+x);
            }
        }

        for (auto x : s) {
            if (x > B) {
                printf("%d\n", x-B);
                break;
            }
        }



    }



    return 0;
}
