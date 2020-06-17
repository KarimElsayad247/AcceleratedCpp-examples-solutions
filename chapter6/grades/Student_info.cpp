// source file for Student_info-related functions
#include <string>
#include <algorithm>
#include <iterator>
#include "grade.h"
#include "Student_info.h"


using namespace std;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}


istream& read(istream& is, Student_info& s)
{
    // read and store the student's name and midterm and final exam grades
    cout << "enter name then mid then final " << endl;
    is >> s.name >> s.midterm >> s.final;

    cout << "enter hw grades " << endl;
    read_hw(is, s.homework); // read and store all the student's homework grades
    return is;
}


// read homework grades from an input stream into a `vector'
istream& read_hw(istream& in, vector<double>& hw)
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

// extract fails two pass solution
vector<Student_info> extract_fails_oen_pass(vector<Student_info>& students) {
    vector<Student_info> fail;
    remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
    return fail;
}

// extract fails in one pass solution
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info>::iterator iter =
            stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());

    return fail;
}

