#ifndef _date_h
#define _date_h
#include <string>
using namespace std;
class Date {
public:
    Date(int m, int d); //constructor
   
    int daysInMonth(); // member functions
    int getMonth();
    int getDay();
    void nextDay();
    string toString();

private:
    int month; // member variables
    int day;
};
#endif
// private:
//      type name;
// - encapsulation: Hiding implementation details of an obejcts from its clinets;
//
// - Encapsulation provides abstration.
//   - separates external view(behavior) from internal view (state)
// - Encapsulation protects the integrity of an object's data
//
// A class's data members should be declared private
//  - No code outside the class can access or change it.
