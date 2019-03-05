#include <iostream>
#include <stack>
#include <string>
using namespace std;
int checkBalance(string code) {
    stack<char> s;
    int length = code.length();
    for (int i = 0; i < length; i++) {
        char c = code[i];
        if (c == '(' || c == '{') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                return i; //error
            } else {
                s.pop();
            }
        } else if (c == '}') {
            if (s.empty() || s.top() != '{') {
                return i; //error
            } else {
                s.pop();
            }
        }
    }
    if (s.empty()) {
    return -1;
    } else {
        return length;
    }
}

int largest(stack<int>& s) {
    int maxValue = s.top();
    s.pop();
    while (!s.empty()) {
        int next = s.top();
        s.pop();
        maxValue = max(maxValue, next);
    }
    return maxValue;
}


int main() {
    cout << (checkBalance("for (i=0;i<a(3} :")) << endl;
    cout << (checkBalance("for ()()(){")) << endl;
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(99);
    s.push(100);
    cout << largest(s) << endl;
    cout << s.empty() << endl;
    cout << s.size() << endl;
    return 0;
}
