#include <iostream>
using namespace std;
void print(int);
void print(double);
void print(string);

void user()
{
    print(42);
    print(9.65);
    print("D is for Digital");
}

int main()
{
    user();
}
