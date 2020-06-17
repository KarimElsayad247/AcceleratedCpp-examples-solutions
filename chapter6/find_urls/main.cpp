#include <iostream>
#include <string>
#include <vector>

#include "urlops.h"

using namespace std;

int main() {
    string s = "you'll find a url https://website.com before this word also this ssh://goaway.org.de is a url";

    vector<string> v = find_urls(s);

    vector<string>::size_type i = 0;

    while (i != v.size()) {
        cout << v[i++] << endl;
    }
}