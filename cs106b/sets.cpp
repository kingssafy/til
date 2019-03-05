// Sets, lexicons, maps
// Sets
// Write a program that counts the number of unique words in a book or file
// using vector to count unique words in a book is just using wrong data structure
// Set: A collection of unique values!
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <unordered_set>
#include <chrono>
using namespace std;
typedef std::chrono::high_resolution_clock Clock;

void clockexample()
{
    auto t1 = Clock::now();
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " nanoseconds" << std::endl;
}
//void wordCount(string filename) {
//
//}



int main(void) {
    unordered_set<string> words;
    ifstream input;
    input.open("mobydick.txt");
    string word;
    auto t1 = Clock::now();
    while (input >> word) {
        words.insert(word);
    }
    auto t2 = Clock::now();
    cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;
    cout << words.size() << endl;
    for (auto s : words) {
        cout << s << endl;
    }
    return 0;
}
