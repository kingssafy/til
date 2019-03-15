//we can easily process sumqueries on a static array by constructing a rpefix sumarray
#include <iostream>
#include <fstream>
using namespace std;


int prefixsum(int array[], int size, int a, int b) {
    if (a == 0) {return array[b];}
    if (a == 0 && b == -1) {return 0;}
    return  prefixsum(array, size, 0, b) - prefixsum(array, size, 0, a-1);
}

int main() {
    ifstream input("100array.txt");
    int N;
    input >> N;
    int array[N];
    for (int i = 0; i < N; i++) {
        input >> array[i];
    }

    for (int i = 1; i < N; i++) {
        array[i] += array[i-1];
    }

    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << prefixsum(array, N, 0, 5);

    return 0;
}
