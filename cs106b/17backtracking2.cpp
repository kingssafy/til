//backtracking: Finding solutions by trying partial solutions and then
//abandoning them if they are not suitable.
//
//-often implemented recursively;
//
// Explore(decisions);
// - if there are no more decisions to make: stop;
// - else, this call will make a single decision.
// for each available choice C that we could make:
// - Choose C.
// Explorer the the remaining decisions.
// Un-Choose-C
// Exercise: Permutations
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int call = 0;

void PermuteHelper(string& name, vector<char>& chosen, vector<bool>& already) {
    call++;
    int stringsize = name.size();
    int chosensize = chosen.size();
    if (stringsize == chosensize) {
        for (char x: chosen) {
            cout << x;
        }
        cout << endl;
    } else {
        for (int i = 0; i < stringsize; i++) {
            if (already[i] == false) {
                already[i] = true;
                chosen.push_back(name[i]);
                PermuteHelper(name, chosen, already);
                already[i] = false;
                chosen.pop_back();
            } 
        }
    }
}

void Permute(string name) {
    int size = name.size();
    vector<char> chosen;
    vector<bool> already(size, false);
    PermuteHelper(name, chosen, already); 
}

int main (void) {
    Permute("marty");
    cout << "total calls " << call << endl;
    return 0;
}
