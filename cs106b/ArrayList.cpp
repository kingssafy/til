#include "ArrayList.h"
#include <iostream>
using namespace std;

/*
 * Constructs a new empty list.(capacitiy 10)
 */
ArrayList::ArrayList() {
    myElements = new int[10]();
    mySize = 0;
    myCapacity = 10;
}

ArrayList::~ArrayList() {
    //when an arraylist is destoryed
    cout << "Destructor called" << endl;
}

/*
 * Appends the given value to the end of the list.
 */
void ArrayList::add(int value) {
    checkResize();
    myElements[mySize] = value;
    mySize++;
}

void ArrayList::insert(int index, int value) {
    for (int i = mySize; i > index; i--) {
        myElements[i] = myElements[i - 1];
    }
    myElements[index] = value;
    mySize++; 
}

int ArrayList::size() const {
    return mySize;
}

int ArrayList::get(int index) const {
    return myElements[index];
}

void ArrayList::set(int index, int value) {
    myElements[index] = value;
}

bool ArrayList::isEmpty() const {
    return mySize == 0;
}

void ArrayList::remove(int index) {
    for (int i = index; i < mySize; i++) {
                myElements[i] = myElements[i+1];
            } 
    mySize--;
}

/*
 * Prints the list to the given output stream, ina formal way
 * {42, -7, 19, 106}
 */
ostream& operator <<(ostream& out, ArrayList& list) {
    out << "{";
    //TODO
    for (int i =0; i < list.size(); i++) {
        out << list.get(i) << ", ";
    }
    out << "}";
    return out;
}

void ArrayList::checkResize() {
    if (mySize == myCapacity) {
        int * bigger = new int[2 * myCapacity];
        for (int i = 0; i < mySize; i++) {
            bigger[i] = myElements[i];
        }
        delete[] myElements;
        myElements = bigger;
    }
}
