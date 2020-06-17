#include <iostream>
#include <vector>
#include <string>

#include "chborder.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<string> v;
    string x;
    int t = 5;
    while(cin >> x){
        v.push_back(x);
    }

    vector<string> framed_pic = frame(v);

    for (vector<string>::size_type i = 0; i != framed_pic.size(); i++)
    {
        cout << framed_pic[i] << endl;
    }
}
