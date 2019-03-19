#include <iostream>
using namespace std;

int naive() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (color[a][i] == 1 && color[b][i] ==1) count++;
    }
}
