#include <iostream>
using namespace std;
// the operator should be defined inside the struct as a function operator<
// whose parameter is another element of the same type.
// The operator should return true if the element is smaller than the paremter and false otehrwise.
// For example, the following struct P contains the x and y coordinates of a point.
// The comparison operator is defined so that the points are sorted primarily by the x coordinate
// and secondarily by the y coordinate.
struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x !=p.x) return x< p.x;
        else return y < p.y;
    }
};
