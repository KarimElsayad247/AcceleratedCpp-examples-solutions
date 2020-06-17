#include <iostream>
#include <vector>

using namespace std;


istream& read(istream& in, vector<string>& words) {
    if(in){

        words.clear;

        string x;
        while(in >> x) {
            words.push_back(x);
        }

        return in;
    }
}