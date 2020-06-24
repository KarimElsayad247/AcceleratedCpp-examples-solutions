#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "split.h"

using namespace std;

// find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in,
        vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    // read the next line
    while (getline(in, line)) {
        ++line_number;

        //break the input into words
        vector<string> words = find_words(line);
        
        // get rid of duplicates so words are inserted only once 
        // in a line
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());

        // remember that each word occurs on the current line
        for (vector<string>::const_iterator it = words.begin();
            it != words.end(); ++it) {
                ret[*it].push_back(line_number);
            }
    }
    return ret;
}
