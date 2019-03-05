// queue: Retrives elements in the order they were added
// -First-in, First-out("FIFO")
// -Elements are stored in order of insertion but don't have indices;
// -Client can only add to the end of the queue, and can only examine/remove
// the front of the queue.

//basic queue operations:
//-enqueue: Add an element to the back
//-dequeue: Remove the front element.
//-peek: Examine the front element.

// Operating systems:
// -queue of print jobs to send to the printer
// Programming:
// - modeling a line of customers or clients

#include <iostream>
#include <queue>
#include <string>
#include <stack>
using namespace std;
void stutter(queue<int>& q);
void mirror(queue<string>& q);
void qprint(queue<int> q) {
    cout << "{ ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "}";
}
void qprint(queue<string> q) {
    cout << "{ ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "}";
}
int main(void) {
    queue<int> q;
    for (int i = 1; i <= 6; i++) {
        q.push(i);
    }
    stutter(q);
//    while (!q.empty()) {
//        cout << q.front() << " ";
//        q.pop();
//    }
//    int size = q.size();
//    for (int i = 0; i < size; i++) {
//        cout << q.front() << " ";
//        q.pop();
//    }
    qprint(q);
    cout << " size " << q.size() << endl;
    queue<string> u;
    u.push("a");
    u.push("b");
    u.push("c");
    mirror(u);
    qprint(u);
    return 0;
}
// 1, 2, 3 => 1, 1, 2, 2, 3, 3
void stutter(queue<int>& q) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        q.push(q.front());
        q.push(q.front());
        q.pop();
    }

//    queue<int> u;
//    while (!q.empty()) {
//        u.push(q.front());
//        u.push(q.front());
//        q.pop();
//    } 
//    q = u;

}
void mirror(queue<string>& q) {
    stack<string> s;
    int size = q.size();
    for (int i = 0; i < size; i ++) {
        string temp = q.front();
        q.pop();
        s.push(temp);
        q.push(temp);
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
