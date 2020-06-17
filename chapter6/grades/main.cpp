#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "analyze_grades.h"

using std::cin;                 using std::setprecision;
using std::cout;                using std::sort;
using std::domain_error;        using std::streamsize;
using std::endl;                using std::string;
using std::max;                 using std::vector;

int main()
{
    vector<Student_info> did, didnt;
    Student_info student;
    // read all the records, separating them based on whether all homework was done
    while (read(cin, student)) {

        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // check that both groups contain data
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    // do the analysis
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0;
}










