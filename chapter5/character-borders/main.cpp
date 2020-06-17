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
    while(cin >> x){
        v.push_back(x);
    }

    vector<string> framed_pic = frame(v);
    vector<string> concat = vcat(v, framed_pic);

    for (vector<string>::size_type i = 0; i != concat.size(); i++)
    {
        cout << concat[i] << endl;
    }
}
