#include <iostream>

using namespace std;


void drawSquare(int cols){
    for(int r = 0; r != cols; ++r) {
        string::size_type c = 0;
        //invariant: we have written c columns so far
        while(c != cols) {
            if(r == 0 || c == 0 || c == cols - 1 || r == cols -1){
                cout << "*";
                c++;
            }
            else{
                cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
}

void drawTriangle(int width){
    int mid = width/2;
    for(int r = 0; r != mid; ++r){
        string::size_type c = 0;
        while(c != width) {
            if(c == mid + r || c == mid - r)
                cout << "*";
            else
                cout << " ";
            ++c;
        }
        cout << endl;
    }
    string str(width+!(width%2), '*');
    cout << str;
}

int main()
{
    int howMuch;
    cout << "enter size: ";
    cin >> howMuch;
    drawTriangle(howMuch);
}
