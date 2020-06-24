#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "split.h"
#include "xref.h"

using namespace std;

int main() 
{
    // call xref using split be default
    map<string, vector<int> > ret = xref(cin);

    bool oneLine = true;

    // exercise 7-7
    for (map<string, vector<int> >::const_iterator it = ret.begin(); 
        it != ret.end(); ++it) {
            for (vector<int>::const_iterator line_it = it->second.begin();
                line_it != it->second.end(); ++line_it) {
                    if (*(line_it) > 1 )
                        oneLine = false;
                }            
        }

    if (oneLine)
        cout << "Line" << endl;
    else
        cout << "lines" << endl;
    //end exerise 7-7


    // // write the results
    // for (map<string, vector<int> >::const_iterator it = ret.begin(); 
    //     it != ret.end(); ++it) {
    //     // write the word
    //     cout << it->first << " occurs on line(s): ";

    //     // followed by one or more line numbers
    //     vector<int>::const_iterator line_it = it->second.begin();
    //     cout << *line_it; // write the first line number

    //     ++line_it;
    //     // write the rest of the line nembers, if any
    //     while (line_it != it->second.end()) {
    //         cout << ", " << *line_it;
    //         ++line_it;
    //     } 
    //     // write a new line to separate each word from the next
    //     cout << endl;
    // }

    return 0;
}