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
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    //write top border
    ret.push_back(border);

    //write each interior row
    for(vector<string>::const_iterator i = v.begin(); i != v.end(); ++i){
        ret.push_back("* " + *(i) + string(maxlen - i->size(), ' ') + " *");
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
    for(vector<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter)
        ret.push_back(*iter);
//    ret.insert(ret.end(), bottom.begin(), bottom.end());

    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add 1 to leave space between pictures
    string::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    vector<string>::const_iterator i = left.begin(), j = right.begin();

    while (i != left.end() || j != right.end()) {
        string s;

        //copy row from left hand side, if there is one
        if (i != left.end())
            s = *(i++);

        // pad to full width
        s += string(width1 - s.size(), ' ');

        // copy a row from right-hand side, if there is one
        if (j != right.end())
            s += *(j++);

        // add s to the picture we are creating
        ret.push_back(s);
    }
    return ret;
}
