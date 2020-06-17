#include <iostream>
#include <string>
#include <vector>
#include <list>


#include "prmindx.h"
#include "chborder.h"

using namespace std;

int main() {
    string s;

    list<string> sliced_words;

    // get line to be permuted
    getline(cin, s);

    // split the line into individual words
    sliced_words = split(s);

    // turn the list into vector for some performance later on (I hope)
    // I don't even remember why I did this
    // update: oh yes to use with get_left_block_width
    vector<string> v = to_vector(sliced_words);

//    for (int i = 0; i != v.size(); ++i) {
//        cout << v[i];
//    }
    // the fox jumps over


    vector<string> rot = generate_rotations(sliced_words);
    sort_perm_indx_collection(rot);

    vector<list<string>> sliced_rotations;
    for (int i = 0; i < rot.size(); ++i) {
        sliced_rotations.push_back(split(rot[i]));
    }


    // create and align left block
    vector<string> words_vector = to_vector(sliced_words);
    vector<string> left_block = create_left_block(words_vector, sliced_rotations);
    // create and align right block
    vector<string> right_block = create_right_block(words_vector, sliced_rotations);
    vector<string> perm_index = hcat(left_block, right_block);

    for (int i = 0; i != perm_index.size(); ++i) {
        cout << perm_index[i] << endl;
    }

    return 0;
}
