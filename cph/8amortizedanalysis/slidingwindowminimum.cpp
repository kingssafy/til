#include <iostream>
using namespace std;
void window(int array[], int windowsize, int result[]) {
    int queue[10] = {};
    queue[1] = array[0];
    int front = 1;
    int last = 1;
    for (int i = 1; i < 8; i++) {
        if (queue[last] <= array[i]) {
        } else while (queue[last] >= array[i] && front<=last) {
            last--;
        }
        last++;
        queue[last] = array[i];
        if (array[i-windowsize] == queue[front]) {
            front++;
        } 
        if (i >= windowsize-1) {result[i] = queue[front];}
        for (int i = 0; i < 10; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 8; i++) {
        cout << result[i] << " ";
    }



}
int main() {
    int windowsize = 4;
    int array[8] = {2, 1, 4, 5, 3, 4, 1, 2};
    int result[8] = {}; 
    window(array, windowsize, result);

    return 0;
}
