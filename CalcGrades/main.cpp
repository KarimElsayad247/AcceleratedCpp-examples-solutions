#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <algorithm>
#include <vector>


using std::cin;            using std::setprecision;
using std::cout;           using std::string;
using std::endl;           using std::streamsize;
using std::vector;         using std::sort;

int main()
{
    cout << "Please enter your name: ";
    string name;
    cin >> name;
    cout << "Hello, " + name + "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double mid_grade, fin_grade;
    cin >> mid_grade >> fin_grade;

    cout << "Enter all your homework grades, "
                "followed by end of file: ";

//    int kount = 0;
//    double sum = 0;

    double x;
    vector<double> homework;


    while(cin >> x){
        homework.push_back(x);
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz hw_size = homework.size();

    if(hw_size == 0){
        cout << "You must Enter Grades! Try Again!" << endl;
        return -1;
    }

    sort(homework.begin(), homework.end());

    vec_sz mid = hw_size / 2;
    double median = hw_size % 2 ? (homework[mid] + homework[mid-1]) / 2
                                :  homework[mid];


    streamsize prec = cout.precision();
    cout << "Your final grade is: " << setprecision(3)
         << 0.2 * mid_grade + 0.4  * median
         << setprecision(prec) << endl;

    return 0;
}
