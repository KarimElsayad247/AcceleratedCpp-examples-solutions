#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool is_palindrome(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
    string s;
    while (getline(cin, s)) {
        cout << (is_palindrome(s) ? "Is palindrome" : "Not palindrome") << endl;
    }
}