#include <iostream>
#include <string>

int main(){

        using std::cout;        using std::string;
        using std::cin;        using std::endl;

        cout << "What is your name? ";
        string name;
        cin >> name;

        const string greeting = "Hello, " + name + "!";

        int pad;
        cout << "How big the spaces? ";
        cin >> pad;

        const int raws = pad * 2 + 3;
        const string::size_type cols = greeting.size() + pad * 3 + 2;
        cout << endl;

        for(int r = 0; r != raws; ++r){

                string::size_type c = 0;

                while(c != cols){
                        if(r == pad + 1 && c == pad + 1){
                                cout << greeting;
                                c +=greeting.size();
                        } else {
                                if(r == 0 || r == raws - 1 || c == 0 || c == cols - 1)
                                {
                                        cout << "*";
                                        c++;
                                }

                                else{
                                        string spaces(cols-2, ' ');
                                        cout << spaces;
                                        c += cols -2;
                                }
                        }
                }
                cout << endl;
        }

//
//        const std::string spaces(greeting.size(), ' ');
//        const std::string second = "* " + spaces + " *";
//
//    //    const std::string astx(greeting.size(), '*');
//        const std::string first(second.size(), '*');
//
//        std::cout << std::endl;
//        std::cout << first      <<std::endl;
//        std::cout << second     <<std::endl;
//        std::cout << "* " << greeting << " *" <<std::endl;
//        std::cout << second     <<std::endl;
//        std::cout << first      <<std::endl;
        return 0;
}
