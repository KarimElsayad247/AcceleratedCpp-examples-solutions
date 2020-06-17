#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

double calc_average(const vector<double>& my_vec)
{
    if(my_vec.size() == 0) 
        throw domain_error("Vector is empty!");

    double sum;
    for(vector<double>::size_type i = 0; i != my_vec.size(); ++i){
        sum += my_vec[i];
    }
    return sum/my_vec.size();
}

int main()
{
    vector<double> my_vec;

    double x;
    while(cin >> x) {
        my_vec.push_back(x);
    }

    try {
        double avg = calc_average(my_vec);
        cout << "average = " << avg << endl;
    } catch(domain_error e) {
        cout << e.what() << endl;
    }
}