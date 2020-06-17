#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
    int arr[5] = {5,6,2,57,1};
    sort(arr, arr+5);
    cout << arr[4];
//    std::string x;
//    vector<string>::size_type longest = 0;
//    vector<string>::size_type shortest = 1000;
//    vector<string>::size_type n = 0;


//    while(cin >> x){
//        n = x.size();
//        longest = max(n, longest);
//        shortest = min(n, shortest);
//
//        cout << "Longest " << longest << "\nshortest " << shortest <<endl;
//    }
}
