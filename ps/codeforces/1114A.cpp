//1114A
//INMAK
//feel free to contact me jchrys@me.com
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("1114A_input.txt");
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    int temp;
    int flag = 0;
    temp = a-x;
    if (temp >= 0) {
        temp += b;
        temp -= y;
        if (temp >= 0) {
            temp += c;
            temp -= z;
            if (temp >= 0) {
                cout << "YES" << endl;
                flag = 1;
            }
        }
    }
    if (!flag) {cout << "NO";}
    return 0;
}
