#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

string cat_all(vector<string> s)
{
    string ret;

    for (vector<string>::const_iterator i = s.begin(); i != s.end(); ++i) {
        copy(i->begin(), i->end(), back_inserter(ret));
    }
    return ret;
}

int main()
{
    vector<string> v;
    string x;
    while(cin >> x) {
        v.push_back(x);
    }

    x = cat_all(v);
    cout << x << endl;

    // for (vector<string>::const_iterator i = v.begin(), i != v.end(), ++i)
}