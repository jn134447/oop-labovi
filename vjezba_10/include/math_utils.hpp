#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>
#include <cmath>
#include <numeric>
#include <iostream>
#include <fstream>
#include <iterator>
#include <filesystem>
#include <exception>

namespace math_utils
{
    struct Point
    {
        double x, y;
    };

    double calc_distance(const Point &a, const Point &b);
    Point calc_centroid(const std::vector<Point> &points);

    std::vector<Point> load_numbers(const std::filesystem::path &path);

    std::ostream &operator<<(std::ostream &os, const Point &point);
}

#endif
