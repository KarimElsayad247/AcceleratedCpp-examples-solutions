#include <iostream>
#include <vector>
#include <string>

using namespace std;

 vector<string>::size_type read(istream& in, vector<string>& words) {
    vector<string>::size_type c = 0;
    string x;
    while(in >> x) {
        words.push_back(x);
        ++c;
    }
    return c;
}

int main() {
    vector<string> words;
    vector<string>::size_type c = read(cin, words);
    cout << c << " Words" << endl;
}