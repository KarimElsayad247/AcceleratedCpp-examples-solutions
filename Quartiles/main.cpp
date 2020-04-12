#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<double> nums;

    double x;
    while(cin >> x){
        nums.push_back(x);
    }

    typedef vector<double>::size_type vec_sz;

    sort(nums.begin(), nums.end());

    vec_sz my_size = nums.size();
    vec_sz mid = my_size / 2;

    vec_sz median = mid % 2 ? (nums[mid] + nums[mid-1]) / 2
                            : nums[mid];

    cout << "My size " << my_size << "Mid " << mid << endl;

    vec_sz st_qtr_i = mid / 2;
    vec_sz st_qtr = st_qtr_i % 2 ? (nums[st_qtr_i] + nums[st_qtr_i-1]) / 2
                     : nums[st_qtr_i];


    vec_sz nd_qtr_i = ((my_size - mid) / 2) + mid;
    vec_sz nd_qtr = nd_qtr_i % 2 ? (nums[nd_qtr_i] + nums[nd_qtr_i-1]) / 2
                     : nums[nd_qtr_i];

    cout << "First Quartile is " << st_qtr << endl;
    cout << "Median is " << median << endl;
    cout << "Second Quartile is " << nd_qtr << endl;
}
