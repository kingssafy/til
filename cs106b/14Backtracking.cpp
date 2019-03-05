//depth first search
//Backtracking:
// Finding solution(s) by trying partial solutions and then abandoning them if they are not suitable.
// a "brute force" algorithmic technique (tries all paths)
// often implemented recursively


#include <iostream>
#include <vector>
using namespace std;

void diceHelper(int dice, vector<int>& chosen) {
    if (dice == 0) {
        // base case 
        cout << "{ ";
        for (auto x : chosen) {
            cout << x << ", ";
        }
        cout << "}" << endl;
    } else {
        // recurse
        for (int i = 1; i <= 6; i++) {
            chosen.push_back(i);

            diceHelper(dice-1, chosen);

            chosen.pop_back();
        } 
        
    }

}

void diceRolls(int dice) {
    vector<int> chosen;
    diceHelper(dice, chosen);
}

int main(void) {
    diceRolls(3);
    return 0;
}
