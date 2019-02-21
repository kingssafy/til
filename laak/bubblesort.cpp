#include <iostream>

int main() {
    int foo [8] = { 1, 3, 8, 2, 9, 2, 5, 6 };
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (foo[j] > foo[j+1]) {
                std::swap(foo[j], foo[j+1]);
                
            }
        }
    } 
}
