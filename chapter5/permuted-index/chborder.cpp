#include <vector>
#include <string>
#include <algorithm>

#include "chborder.h"

using namespace std;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    vector<string>::size_type n = v.size();
    for(vector<string>::size_type i = 0; i != n; ++i){
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    vector<string>::size_type n = v.size();
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    //write top border
    ret.push_back(border);

    //write each interior row
    for(string::size_type i = 0; i != n; ++i){
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

    //write bottom border
    ret.push_back(border);

    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    //copy the top picture
    vector<string> ret = top;

    //copy entire bottom picture
//    for(vector<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter)
//        ret.push_back(*iter);
    ret.insert(ret.end(), bottom.begin(), bottom.end());

    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;// continue until we've seen all rows from both pictures

    while (i != left.size() || j != right.size()) {

        // construct new string to hold characters from both pictures
        string s;

        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];

        // pad to full width
        s += string(width1 - s.size(), ' ');

        // copy a row from the right-hand side, if there is one
        if (j != right.size())
            s += right[j++];

        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}









