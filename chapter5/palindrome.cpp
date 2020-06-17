#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool check_palindrome(const string& s) {
    string::size_type n = s.size()/2;
    for (string::size_type i = 0; i != n; i++) {
        if(s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

int count_palindrome(fstream& f) {
    int c = 0;
    string s;
    while (f >> s) {
        if(check_palindrome(s))
            ++c;
    }
    return c;
}

string find_longest_palindrome(fstream& f) {
    string::size_type maxlen = 0;
    string s;
    string ret;
    while(f >> s) {
        if(check_palindrome(s) && s.size() > maxlen) {
            maxlen = s.size();
            ret = s;
        }
    }
    f.clear();
    f.seekg(0, ios::beg);
    return ret;
}

int main() {
    int c = 0;
    fstream dictionary;
    string name;
    cout << "Enter name: "; cin >> name;
    dictionary.open(name, ios::in); 
    c = count_palindrome(dictionary);
    dictionary.clear();
    dictionary.seekg(0, ios::beg);
    cout << "There are " << c << " palindromes" << endl;
    cout << "longest palindrome is " << find_longest_palindrome(dictionary) << endl;
    return 0;
}