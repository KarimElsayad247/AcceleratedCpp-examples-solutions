#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{

    std::string x;
    vector<string>::size_type longest = 0;
    vector<string>::size_type shortest = 1000;
    vector<string>::size_type n = 0;


    while(cin >> x){
        n = x.size();
        longest = max(n, longest);
        shortest = min(n, shortest);

        cout << "Longest " << longest << "\nshortest " << shortest <<endl;
    }
}
