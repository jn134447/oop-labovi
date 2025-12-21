#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cmath>

#include "math_utils.hpp"

constexpr std::string_view PATH("../points.txt");

int main()
{
    // ------------ 1 ---------------
    std::vector<int> numbers{2, 4, 6, 7, 8, 9, 10, 11, 3, 16};

    auto is_odd = [](int n)
    { return (n % 2 != 0) ? true : false; };

    // 1.A find first odd number
    auto found_odd =
        std::find_if(numbers.begin(), numbers.end(),
                     [is_odd](int &e)
                     { return is_odd(e); });
    std::cout << "first odd number: " << *found_odd << '\n';

    // 1.B count the odd numbers
    int odd_count =
        std::accumulate(
            numbers.begin(), numbers.end(), 0,
            [is_odd](int acc, auto &elem)
            {
                if (is_odd(elem))
                    acc += 1;
                return acc;
            });
    std::cout << "odd count: " << odd_count << '\n';

    // 1.C avg over odd numbers
    double odd_avg =
        std::accumulate(
            numbers.begin(), numbers.end(), 0.0,
            [is_odd](double acc, auto &elem)
            {
                if (is_odd(elem))
                    acc += elem;
                return acc;
            })

        / static_cast<double>(odd_count);

    std::cout << "odd average: " << odd_avg << '\n';

    // 1.D change all numbers that are to power of 2 into 2
    std::for_each(numbers.begin(), numbers.end(),
                  [](auto &elem)
                  {
                      // math algo shenanigans
                      if ((elem != 0) && ((elem & (elem - 1)) == 0))
                          elem = 2;
                  });

    for (auto &i : numbers)
        std::cout << i << ", ";
    std::cout << '\n';

    // 1.E print even numbers (ascending), then odd numbers (ascending)
    std::sort(numbers.begin(), numbers.end());
    std::stable_partition(numbers.begin(), numbers.end(),
                          [](auto elem)
                          { return (elem % 2 == 0) ? true : false; });

    for (auto &i : numbers)
        std::cout << i << ", ";
    std::cout << '\n';

    // ------------ 2 ---------------
    {
        using namespace math_utils;
        std::vector<Point> points = load_numbers(PATH);

        // 2.A sort the points via lambda
        Point plane_center = {0.0, 0.0};
        std::sort(points.begin(), points.end(),
                  [&plane_center](const Point &a, const Point &b)
                  {
                      return (calc_distance(a, plane_center) <
                              calc_distance(b, plane_center));
                  });
        for (Point &point : points)
            std::cout << point.x << '\t' << point.y << '\n';

        // 2.B count points in first quadrant
        std::size_t first_quad_count =
            std::count_if(
                points.begin(), points.end(),
                [](const Point &point)
                {
                    return (point.x > 0 && point.y > 0);
                });
        std::cout << "first_quad_count: " << first_quad_count << '\n';

        // 2.C calculate centroid
        Point points_centroid = calc_centroid(points);
        std::cout << "points_centroid: "
                  << points_centroid.x << '\t'
                  << points_centroid.y << '\n';

        // 2.D move all points by (+5,+3)  NOTE: assuming its on the same vector
        std::transform(points.begin(), points.end(), points.begin(),
                       [](Point &point)
                       {
                           point.x += 5;
                           point.y += 3;
                           return point;
                       });
        for (Point &point : points)
            std::cout << point.x << '\t' << point.y << '\n';

        // 2.E remove_if+erase for points in 3rd quadrant
        // NOTE: std::erase() is c++20 unfortunately
        points.erase(
            std::remove_if(points.begin(), points.end(),
                           [](const Point &point)
                           { return (point.x < 0 && point.y < 0); }),
            points.end());

        // for (Point &point : points)
        //     std::cout << point.x << '\t' << point.y << '\n';

        // 2.F output using std::ostream_iterator NOTE: assuming its to console
        std::cout << "\n2.F:\n";
        std::ostream_iterator<Point> oiter(std::cout, "\n");
        std::copy(points.begin(), points.end(), oiter);
    }
}