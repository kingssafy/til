#include <iostream>
#include <vector>

using namespace std;

void search(vector<int>& v, int k, vector<int>& subset) {
    int n = v.size();
    if (k == n) {
        //process subset
        for (auto x : subset) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        search(v, k+1, subset);
        subset.push_back(v[k]);
        search(v, k+1, subset);
        subset.pop_back();
    }
}

int main(void) {
    vector<int> v;
    for (int i = 0; i < 3; i++) {
        v.push_back(i);
    }
    vector<int> subset;
    search(v, 0, subset);
    int size = v.size();
    for (int b = 0; b < (1<<size); b++) {

    }
}
