#include <iostream>
#include <iomanip>

using namespace std;

int square(int x){
    return x*x;
}

int main() {
    cout << "Number" << setw(10) << "Square" << endl;
    for(int i = 0; i != 1000; ++i) {
        cout << i << setw(10) << i*i << endl;
    }
}