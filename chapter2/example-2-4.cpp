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
            if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == raws - 1 || c == 0 || c == cols - 1)
                {
                    cout << "*";
                    c++;
                }

                else
                {
                    string spaces(cols - 2, ' ');
                    cout << spaces;
                    c += cols - 2;
                }
            }
            cout << endl;
        }
        return 0;
    }