#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, temp;
    bool clown[5001] = {false};
    bool acrob[5001] = {false};
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%1d", &temp);
        clown[i] = temp;
    } 
    for (int i = 0; i < n; i++) {
        scanf("%1d", &temp);
        acrob[i] = temp;
    } 
    int counter[4] = {0};
    int value;
    for (int i = 0; i < n; i++) {
        value = (clown[i]<<1) | acrob[i];
    }
    

    return 0;
}
