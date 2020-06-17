#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> u(10, 100);

//    for (int i = 0; i != u.size(); ++i) {
//        cout << u[i] << " ";
//    }

    vector<int> v;
//    copy(u.begin(), u.end(), back_inserter(v));
    copy(u.begin(), u.end(), inserter(v, v.begin()));

    for (int i = 0; i != v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}