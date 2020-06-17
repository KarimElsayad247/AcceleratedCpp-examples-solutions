#include <iostream>
#include <vector>

#include "chborder.h"

using namespace std;

int main()
{
    vector<string> v;

    string x;
    while(cin >> x) {
        v.push_back(x);
    }
    vector<string> framed_pic = frame(v);
//
//    for (vector<string>::size_type i = 0; i != framed_pic.size(); i++) {
//        cout << framed_pic[i] << endl;
//    }

    vector<string> concat = hcat(framed_pic, framed_pic);

    for (vector<string>::const_iterator i = concat.begin(); i != concat.end(); ++i) {
        cout << *(i) << endl;
    }

    return 0;
}