//Marty stepp

#ifndef _arraylist_h
#define _arraylist_h

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class ArrayList {
public:
    //constructor
    ArrayList();
    ~ArrayList();
    // member functions (methods)
    void add(int value);
    void clear();
    int get(int index) const;
    void insert(int index, int value);
    bool isEmpty() const;
    void remove(int index);
    void set(int index, int value);
    int size() const;
    void debug() const;

private:
    //member variables (fields)
    // TODO
    int* myElements;
    int mySize;
    int myCapacity;
    void checkResize();
};

// overloaded operators
ostream& operator <<(ostream& out, ArrayList& list);

#endif

