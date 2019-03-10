#ifndef _linkedlist_h
#define _linkedlist_h

#include <iostream>
#include <string>
using namespace std;

/* The internal structure representing a single node */
struct ListNode {
    int data;           // element stored in each node
    ListNode* next;     // pointer to the next node (NULL if isn't)

    ListNode(int d = 0, ListNode* n = NULL) { // constructor
        data = d;
        next = n;
        cout << "ListNode constructor called" << endl;
    }
    
    ~ListNode() {
        cout << "ListNode destructor called" << endl;
    }
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void add(int value);
    void clear();
    int get(int index) const;
    void insert(int index, int value);
    bool isEmpty() const;
    void remove(int index);
    void set(int index, int value);
    int size() const;

    //friend ostream& operator <<(ostream& out, LinkedList&)
private:
    ListNode* front;

};
#endif


