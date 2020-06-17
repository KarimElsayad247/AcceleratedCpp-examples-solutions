//
// Created by karim on 21-May-20.
//
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cctype>
#include <stdexcept>

//don't forget to remove this later
#include <iostream>

#include "prmindx.h"


using namespace std;

vector<string> generate_rotations(list<string>& spliced_words) {
    //return vector
    vector<string> collection;
    string temp;

    // each loop rotates the words once
    for (list<string>::size_type k = 0; k != spliced_words.size(); ++k) {

        // rotate once
        string s = *(spliced_words.begin());
        spliced_words.erase(spliced_words.begin());
        spliced_words.push_back(s);

        // concatenate the words: generate one sentence
        temp.clear();
        for (list<string>::iterator i = spliced_words.begin(); i != spliced_words.end(); ++i) {
            temp += ((*i) + " ");
            //         cout << temp << endl;
        }
        collection.push_back(temp);
    }
    // sort the rotations


    return collection;
}

string::size_type get_left_block_width(const vector<string>& original) {
    // the width is the sum of the sizes of all words except for first one
    // plus enough spaces
    if(original.size() == 0) {
        throw domain_error("vector is empty!");
    }

    string::size_type ret = 0;
    for (vector<string>::size_type i = 0; i != original.size(); ++i) {
        ret += original[i].size();
    }
    // minus 2 is for initial word space and end space
    ret = ret - original[0].size() + original.size() - 2;

    return ret;
}

vector<string> create_left_block(const vector<string>& original, const vector<list<string>>& rotations_list) {

    // get max width of left block
    string::size_type block_width = get_left_block_width(original);

    vector<string> ret;

    // compare 1st word of rotations with words of original
    // until you find the stopping word
    for (vector<string>::size_type i = 0; i != original.size(); ++i) {
        string s;

        // loop over contents of original strings until you find stop word
        // stop word is the first word in the rotation_list of the current loop iteration
        for (vector<string>::size_type j = 0; j != original.size(); j++) {
            // if they are equal, string we ready
            if ( !(lowcase(original[j]).compare(lowcase(*(rotations_list[i].begin() ) ) ) ) ) { // case insensitive comparison

                // if s is emtpy, no trailing spaces to delete
                if(s.size()) s.erase(s.end() - 1);

                // pad the string from the left to the block width
                s.insert(0, string(block_width - s.size(), ' '));

                // put in vector to return
                ret.push_back(s);
                break;
            }
            else {
                s = s + original[j] + " ";
            }
        }
    }
    return ret;
}

vector<string> create_right_block(const vector<string>& original, const vector<list<string>>& rotations_list) {

    vector<string> ret;

    // compare 1st word of rotations with words of original
    // until you find the stopping word
    for (vector<string>::size_type i = 0; i != original.size(); ++i) {
        string s;
        // loop over contents of original strings until you find stop word
        // stop word is the first word in the rotation_list of the current loop iteration
        for (vector<string>::size_type j = 0; j != original.size(); j++) {
            // if they are equal, this is stopping word
            if ( !(lowcase(original[j]).compare(lowcase(*(rotations_list[i].begin() ) ) ) ) ) { // case insensitive comparison
                // leading blank space
                s.push_back('\t');

                // invariant: we have written j - (original value of j) words into ret
                while (j != original.size()) {
                    s += (original[j++] + " ");
                }

                ret.push_back(s);
                break;
            }
        }
    }
    return ret;
}
// split function is directly copied from the book
list<string> split(const string& s) {
    list<string> ret;
    typedef string::size_type string_size;string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != s.size()) {

        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;

        // invariant: none of the characters in range [original j, current j)is a space
        while (j != s.size() && !isspace(s[j]))
            j++;

        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i and taking j - i chars
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}



// the compare function is obtained through mathalope.co.uk
// couldn't think for one myself
bool compare(const string& x, const string& y) {
    return lowcase(x) < lowcase(y);
}

string lowcase(const string& s) {
    string ret;

    if(s.size() == 0) throw(domain_error("string is empty!"));

    for (string::size_type i = 0; i != s.size(); ++i) {
        ret.push_back(tolower(s[i]));
    }
    return ret;
}

void sort_perm_indx_collection(vector<string>& v) {
    sort(v.begin(), v.end(), compare);
}

vector<string> to_vector(list<string>& list_of_strings) {
    list<string>::const_iterator iter;
    vector<string> ret;
    // push words from list to vector
    for (iter = list_of_strings.begin(); iter != list_of_strings.end(); ++iter) {
        ret.push_back(*iter);
    }
    return ret;
}
