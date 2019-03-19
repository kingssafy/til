#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, array[1000]={};
    string s1, s2;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> s1 >> s2;
        int size = s2.length();
        int r = 0;
        for (int i = 0; i < size; i++) {
            char a = s1[i]; 
            for (int j = size-1; j >= 0; j--) {
                if (a == s2[j]) {
                    array[j] = 1;
                    for(int k = 0; k < j; k++) {
                        array[j] = max(array[j], array[k]+1);
                        
                    }
                    r = max(r, array[j]);
                }
            }
        } 
        cout << "#" << tc+1 << " " << r << endl;
        
    }
    return 0;
}
