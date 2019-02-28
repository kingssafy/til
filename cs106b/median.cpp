#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ifstream cin("median_input.txt");
    int N;
    cin >> N;
    int array[N];
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        array[i] = num;
    }

    return 0;

}
