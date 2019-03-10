#include "linkedlist.h"

/* 
 * Constructs a new empty list.
 */
LinkedList::LinkedList() {
    // TODO
    front = NULL;
}

LinkedList::~LinkedList() {
    //TODO
    clear();
}


/*
 * Appends the given value to the end of the list
 */
void LinkedList::add(int value) {
    if (!front) {
    front = new ListNode(value);
    } else {
        ListNode* current = front;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new ListNode(value);
    }
}




// Returns value in list at given index.
int LinkedList::get(int index) const {
    ListNode* current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

/*
 * Stores the given value at the given 0-based index
 */
void LinkedList::set(int index, int value) {
    ListNode* current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;
}


void LinkedList::insert(int index, int value) {
    if (index == 0) {
        ListNode* oldFront = front;
        front = new ListNode(value);
        front->next = oldFront;
    } else {
        ListNode* current = front;
        for (int i = 0; i < index-1; i++) {
            current = current->next;
        }
    //    ListNode* temp = current->next;
    //    current->next = new ListNode(value);
    //    current->next->next = temp;
        ListNode* newNode = new ListNode(value);
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Removes value at given index from lsit.
void LinkedList::remove(int index) {
    ListNode* trash;
    if (index == 0) {
        trash = front;
        front = front->next;
    } else {
        ListNode* current = front;
        for (int i = 0; i < index-1; i++) {
            current = current->next;
        }
        trash  = current->next;
        current->next = current->next->next;
        //delete trash; // what ever that pointer is pointing at delete that! ''delete what trash's pointing at""
    }
    delete trash;
}

void clearHelper(ListNode* front) {
    if (front->next != NULL) {
        clearHelper(front->next);
        delete front->next;
    }
}

void LinkedList::clear(void) {
//    clearHelper(front);
//    delete front;
//    front = NULL;
    while (front != NULL) {
        //remove(size() -1); // takes long time
        remove(0);
    }
}

// 2ways to change a linked list
// 1. front = ___;
// 2. ___ -> next = ___;
// does Not change the list:
//    curr = new ListNode();
//    curr = front;
//    curr = NULL;
