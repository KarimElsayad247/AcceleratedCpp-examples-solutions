#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> v;
    cout << "enter elements: ";
    int x; 
    while(cin >> x) {
        v.push_back(x);
    }

    // remove zeros
    v.erase(remove(v.begin(), v.end(), 0), v.end());
     cout << "elements without zeros: ";
    for (int i = 0; i < v.size(); ++i) {
       cout << v[i] << " ";
    } 
    return 0;
}