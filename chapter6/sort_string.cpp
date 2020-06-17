#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    string s = "this is a bAAAAd string";
    sort(s.begin(), s.end());
    cout << s << endl;
}