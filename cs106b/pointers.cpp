// you can ask for any variable's memory address with the & operator.
// pointer: A variable that stores a memory address.
// - Pointers are declared with * after the type they point to.
// - The pointer itself is also a variable that occupies memory.
// - You can refer to the value pointed at by a pointer using * before it.



#include <vector>
#include <iostream>
using namespace std;
int main(void) {
//    int x = 42;
//    int y = 17;
//    int a[3] = {91, -3, 85};
//
//    cout << x << endl;
//    cout << &x << endl;
//    cout << y << endl;
//    cout << &y << endl;
//    cout << &a[0] << endl;
//    cout << &a[1] << endl;
//    cout << &a[2] << endl;
// Pointer
//    int x = 42;
//    int* p = &x;
//    cout << p << endl;
//    cout << *p << endl;
//    *p = 99;
//    cout << x << endl;
// if uninitialized, a pointer points to an arbitrary place in memory.
// - if you try to follow the pointer, the program will probably crash!
//    int* a;
//    cout << a << endl;
//    cout << *a << endl;
// NULL pointer
// NULL: memory address 0, intended to mean "points to nothing"
// - Meant as a default or "empty" value to initialize a pointer to.
// - if you follow a NULL pointer, the program will crash!
//    int x = 42;
//    int* p = NULL;
//    cout << p << endl;
//    cout << *p << endl;
// Testing for NULLness
// if (p == NULL) true
// if (p) false
// if (!p) true
// Pointer to an object
// You can point to an object
// - To refer to members of the oject, write pointer->member.
//   * The same as (*pointer).member
/*
 * Date d(9, 19);
 * Date* p = &d;
 * cout << p->daysInMonth() << endl; // 30
 * p -> nextday();
 * cout << *p << endl; //9, 20
 */
//
//Object life span
//*Any declared values live until the end of the current function scope.
//- This is called static allocation or stack allocation.
//If you return an object, it is copied; the original is still discarded.
// * How to make an object that lives past the end of the function?
// -> use new statement and get a pointer ! it doesnt destructed
//
    vector<int>* p = new vector<int>;
    return 0;
}


