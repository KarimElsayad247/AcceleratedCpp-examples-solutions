//
// Created by karim on 13-Jun-20.
//

#include <algorithm>
#include <stdexcept>

#include "analyze_grades.h"
#include "grade.h"
#include "median.h"
#include "average.h"

using namespace std;

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

// median of the nonzero elemnts of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info&s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

bool did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0))
            == s.homework.end());
}

double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

    return median(grades);
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), average_grade);

    return median(grades);
}


// I wrote this one myself, it's an exercise
double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);

    return median(grades);
}

void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did) <<
                    ", median(didnt) = " << analysis(didnt) << endl;
}

void write_analysis_merged(ostream& out, const string& name,
                           double analysis(const Student_info&),
                           const vector<Student_info>& did,
                           const vector<Student_info>& didnt) {
    vector<double> gradesDid;
    vector<double> gradesDidnt;

    transform(did.begin(), did.end(), back_inserter(gradesDid), analysis);
    transform(didnt.begin(), didnt.end(), back_inserter(gradesDidnt), analysis);

    out << name << ": median(did) = " << median(gradesDid) <<
        ", median(didnt) = " << median(gradesDidnt) << endl;
}