#include <iostream>
#include <string>

int main()
{

    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    cout << "What is your name? ";
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    int pad;
    cout << "How big the spaces? ";
    cin >> pad;

    pad = 1;

    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;
    cout << endl;

    for (int r = 0; r != rows; ++r)
    {

        string::size_type c = 0;

        while (c != cols)
        {
            if(r == 0 || r == rows - 1){
                cout << (cols, '*');
                c += cols - 1;
            }
        }
        cout << endl;
    }
    return 0;
}