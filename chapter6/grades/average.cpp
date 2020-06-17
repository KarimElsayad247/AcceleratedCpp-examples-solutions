//
// Created by karim on 13-Jun-20.
//

#include <numeric>
#include <algorithm>

#include "average.h"

double average(const std::vector<double>& v) {
    return accumulate(v.begin(), v.end(), 0.0) / v.size();

}
