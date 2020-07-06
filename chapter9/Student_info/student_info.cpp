#include <iostream>

#include "student_info.h"
#include "grade.h"

using namespace std;

Student_info::Student_info(): midterm(0), final(0) { }

Student_info::Student_info(istream& is) { read(is); }

istream& Student_info::read(istream& in) {
    cout << "enter name then mid then final " << endl;
    in >> n >> midterm >> final;
    
    cout << "enter hw grades " << endl;
    read_hw(in, homework);

    final_grade = ::grade(midterm, final, homework);

    return in;
}

double Student_info::grade() const {
    return final_grade;
}

bool compare(const Student_info&x, const Student_info& y) {
    return x.name() < y.name();
}

// read homework grades from an input stream into a `vector'
istream& Student_info::read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read homework grades
        string x;
        string::size_type sz;
        while ( (in >> x) && x != "e")
            hw.push_back(stod(x, &sz));
    }
    return in;
}