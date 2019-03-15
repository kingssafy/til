#include <iostream>
#include <fstream>
using namespace std;

int getmin(int mintp[100][6], int a, int b) {
    int width = 1;
    int column = 0;
    for (width = 1; width <= (b-a+1)/2; width *=2) {
        column++;
    }

    return min(mintp[a+width][column-1], mintp[b-width][column-1]);
}


int main() {
    ifstream cin("100array.txt");
    int N, array[100];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    int end = 0;
    for (end = 1; end < N; end *= 2);

    int minpt[100][6] ={{0}};
    int column = 0;
    for (int j = 1; j <= end/2; j *= 2) {
        for (int i = 0; i < N-j+1; i++) {
            if (column == 0) {
                minpt[i][column] = array[i];
            } else {
                minpt[i][column] = min(minpt[i][column-1], minpt[i+j/2][column-1]);
            }
        }
        column++;
    }

    for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 6; c++) {
            cout << minpt[r][c] << " ";
        }
        cout << endl;
    }

    cout << getmin(minpt, 1,10);    


    return 0;
}
