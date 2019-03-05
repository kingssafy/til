// map: A collection of pairs (k, v), sometimes called key/value pairs, where v can be found quickly if you know k.
//  - a.k.a dictionary, assiciative array, hash
// there's two map classes
// hashmap and just 'map'
// - requires 2 type parameters: one for keys, one for values;

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

void wordTally(string filename);
void mprint(map<string, int> tally);

int main() {
    wordTally("mobydick.txt");
    return 0;
     
}


void wordTally(string filename) {
    ifstream input;
    input.open(filename);
    string word; 
    map<string, int> tally;
    
    while (input >> word) {
        tally[word]++; 
    }
    mprint(tally);
}
void mprint(map<string, int> tally) {
    for (auto x : tally) {
        cout << x.first << " " << x.second << endl;
    }
}
