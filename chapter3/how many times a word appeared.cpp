#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> words;

    std::string x = "Hellos";
    vector<string>::size_type n;

    while(cin >> x){
        int counter = 0;

        words.push_back(x);

        for(n = 0; n < words.size(); ++n)
        {
            if(words[n].compare(x) == 0)
            {
                ++counter;
            }
        }
        cout << "Word appeared " << counter << " times so far in input" << endl;
        counter = 0; //reset counter
    }
}
