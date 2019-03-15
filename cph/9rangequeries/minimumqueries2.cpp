#include <iostream>
#include <fstream>
using namespace std;

int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result = result*x;
    }
    return result;
}

void makemint(int array[100], int mint[100][6]) {
    int column = 0;
    for (int max = 1; max <= 100/2 ; max = max* 2) {
        column++;
    }
    for (int c = 0; c < column; c++) {
        for (int r = 0; r < 100-pow(2,c)+1; r++) {
            if (c == 0) {
                mint[r][c] = array[r];
            } else {
                //TODO
                mint[r][c] = min(mint[r][c-1], mint[r+pow(2,c-1)][c-1]);
            }
        }
    }
}

void print(int mint[100][6]) {
    for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 6; c++) {
            cout << mint[r][c] << " ";
        }
        cout << endl;
    }
}

int getmin(int mint[100][6], int x, int y) {
    int column = 0;
    for (int max = 1; max <= (y-x+1)/2 ; max = max* 2) {
        column++;
    }
    cout << "adsfasffd" << column << endl;
    return min(mint[x][column], mint[y-pow(2,column)+1][column]);
}


int main() {
    ifstream cin("100array.txt");
    int N;
    cin >> N;
    int array[100] = {};
    for (int i = 0; i < 100; i++) {
        cin >> array[i];
    }
    int mint[100][6] = {{0}};
    makemint(array, mint); 
    print(mint);
    cout << endl << endl << getmin(mint, 0, 8) << endl;
    return 0;
}
