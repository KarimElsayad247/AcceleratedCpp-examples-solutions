#ifndef PERMUTED_INDEX_PRMINDX_H
#define PERMUTED_INDEX_PRMINDX_H

#include <string>
#include <vector>
#include <list>

// given a vector of words, obtain a string of them but cycled
// first step of the algorithm
std::vector<std::string> generate_rotations(std::list<std::string>& spliced_words);

// function described in 5.9
// use to obtain a vector of individual words
std::list<std::string> split(const std::string& s);

// the compare function is obtained through mathalope.co.uk
// couldn't think for one myself
std::string lowcase(const std::string& s);

bool compare(const std::string& x, const std::string& y);

void sort_perm_indx_collection(std::vector<std::string>& v);

// given a list of  representing a rotation
// and a string list containing original order
// create the left and right blocks of the index
std::vector<std::string> create_left_block(const std::vector<std::string>&, const std::vector<std::list<std::string>>&);
std::vector<std::string> create_right_block(const std::vector<std::string>&, const std::vector<std::list<std::string>>&);

std::string::size_type get_left_block_width(const std::vector<std::string>& original);

// turn the lists to vectors in order to work with imported
// character border functions width and hcat
std::vector<std::string> to_vector(std::list<std::string>& list_of_strings);
#endif //PERMUTED_INDEX_PRMINDX_H
