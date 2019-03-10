#include <iostream>
#include <vector>
using namespace std;

int calls = 0;

void diceRollHelper(int num, int desiredSum, int sumSoFar, vector<int>& chosen) {
    calls++;
    int size = chosen.size();
    if (size == num) {
        //if (sumSoFar == desiredSum){
            for (auto x: chosen) {
                cout << x << " ";
            }
            cout << endl;
        //}

    } else {
        for (int i = 1; i <=6; i++) {
            if(sumSoFar + i + 1*(num - (size+1)) <= desiredSum &&
               sumSoFar + i + 6*(num - (size+1)) >= desiredSum) {
                chosen.push_back(i);
                diceRollHelper(num, desiredSum, sumSoFar+i, chosen);
                chosen.pop_back();

            }
        }
    }
}
void diceSum(int num, int desiredSum) {
    vector<int> chosen;
    int sumSoFar = 0;
    diceRollHelper(num, desiredSum, sumSoFar, chosen);
}
int main(void) {
    diceSum(7, 15);  
    cout << "total calls: " << calls << endl;
    return 0;
}
