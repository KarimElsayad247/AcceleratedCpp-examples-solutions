//
// Created by karim on 13-Jun-20.
//

#ifndef GRADES_ANALYZE_GRADES_H
#define GRADES_ANALYZE_GRADES_H


#include "Student_info.h"

double grade_aux(const Student_info&);
double average_grade(const Student_info& s);

bool did_all_hw(const Student_info& s);

double median_analysis(const std::vector<Student_info>&);

double average_analysis(const std::vector<Student_info>&);

double optimistic_median(const Student_info&);

double optimistic_median_analysis(const std::vector<Student_info>& students);

void write_analysis(std::ostream& out, const std::string& name,
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt);

#endif //GRADES_ANALYZE_GRADES_H
