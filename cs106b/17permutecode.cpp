#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
void permute(vector<string>& v);
void permute(string s);
void combin(string s, int len);

int main() {
    cout << endl;
    cout << "permute: " << endl;
    permute("GOOGLE");

    return 0;
}

/*
 *  Prints all possible rearrangements
 */

void indent(int n) {
    for (int i = 0; i < n; i++) {
        if (i != n-1) {
            cout << "----";
        } else {
            cout << "    ";
        }
        
    }
}

void permuteHelper(string s, string chosen,  set<string>& already) {
//    int l = chosen.size();
//    indent(l);
//    cout << "permuteHelper(" << s << ", " << chosen << ")" << endl;
    // if/else a basecase vs recursive cases
    if (s.empty()) {
        if (already.count(chosen) == 0) {
            cout << chosen << endl; 
            already.insert(chosen);
        }
    } else {
        // choose/explorer/unchoose
        // (1 letter)
        int length = s.length();
        for (int i = 0; i < length; i++) {
            // choose
            char c = s[i];
            chosen += c;
            s = s.erase(i, 1);
            // explore
            permuteHelper(s, chosen, already);

//            //un-choose
            s.insert(i, 1, c);
            chosen.erase(chosen.length() - 1, 1);
        }
    }
}


void permute(string s) {
    set<string> already;
    permuteHelper(s, "", already); 
}



