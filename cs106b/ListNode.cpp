#include "ListNode.h"
#include <iostream>

using namespace std;
void print(ListNode* hi) {
    while (hi != NULL) {
        cout << hi->data << endl;
        hi = hi->next;
    }
}
int main() {
    ListNode* node1 = new ListNode();
    node1->data = 42;
// 42 -3 17 99
    node1->next = new ListNode();
    node1->next->data = -3;

    node1->next->next = new ListNode();
    node1->next->next->data = 17;

    node1->next->next->next = new ListNode();
    node1->next->next->next->data = 99;

    node1->next->next->next->next = NULL;
    print(node1);
    print(node1);
    return 0;
}
