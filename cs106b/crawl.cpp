#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Prints information about this file,
// and (if it is a directory) any files inside it.
void crawl(string filename, string indent = "") {
    cout << indent << getTail(filename) << endl;
    if (isDirectory(filename)) {
        //recursive case; print contained files/dirs
        vector<string> filelist;
        listDirectory(filename, filelist);
        for (string subfile : filelist) {
            crawl(filename + "\" + subfile,
                    indent + "    ");
        }
    }
}
