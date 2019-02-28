#include <vector>
#include <string>
#include <iostream>
using namespace std;

int countInRange(vector<int>& v, int min, int max) {
    int count = 0;
    for (int num : v) {
        if (num >= min && num <= max) {
            count++;
        }
    }
    return count;

}

void removeAll(vector<string>& v, string s) {
    int size = v.size();
    for (int i = size - 1; i > -1; i--) {
        string value = v.at(i);
        if(value == s) v.erase(v.begin()+i);
    }
}


int main(void) {
    vector<int> v = {28, 1, 17, 4, 41, 9, 59, 8, 31, 30, 25};
    cout << countInRange(v, 10, 30) << endl;
    vector<string> v2;
    v2 = {"a", "b", "c", "b", "b", "a", "b"};
    removeAll(v2, "b");
    for (string s : v2) {
        cout << s << " ";
    }
    return 0;
}
