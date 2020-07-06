#include <string>
#include <vector>
#include <iostream>

class Student_info {
    public:
    //  iterface goes gere
    std::istream& read(std::istream&);
    double grade() const;
    std::string name() const {return n; }
    bool valid() const { return !homework.empty(); }
    Student_info();
    Student_info(std::istream&);
    Student_info(std::fstream&);

    private:
    // implementation goes gere
    std::string n;
    double midterm, final;
    double final_grade;
    std::vector<double> homework;
    std::istream& read_hw(std::istream& in, std::vector<double>& hw);
};

bool compare(const Student_info&x, const Student_info& y);

