#include <iostream>
using namespace std;
struct sub {
    int h;
    int t;
};
sub sub1[10] = {{5,2}, {5, 3}, {5, 3}};
int a = 3;

int getTime() {
    bool flag = true;
    int time = 0;
    while (flag) {
        flag = false;
        int counter = 0; 
        for (int i = 0; i < a; i++) {
            if (sub1[i].h == 0) continue;
            flag = true;
            if (sub1[i].t < time) {
                sub1[i].h--;
                counter++;
                if (counter == 3) break;
            } 
        }
        if (flag) time++;
    } 
    int res1 = time;
    return res1;
}

int main() {
    cout << getTime();
    return 0;
}
