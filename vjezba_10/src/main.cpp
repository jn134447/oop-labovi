#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "math_utils.hpp"
#include "student.hpp"

constexpr std::string_view POINTS_PATH("../points.txt");
constexpr std::string_view STUDENTS_PATH("../students.txt");
constexpr int SCORE_THRESHOLD = 40;

#define TASK 3
int main()
{
#if TASK == 1
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

#endif
#if TASK == 2
    // ------------ 2 ---------------
    {
        using namespace math_utils;
        std::vector<Point> points = load_numbers(POINTS_PATH);

        // 2.A sort the points via lambda
        Point plane_center = {0.0, 0.0};
        std::sort(points.begin(), points.end(),
                  [&plane_center](const Point &a, const Point &b)
                  {
                      return (calc_distance(a, plane_center) <
                              calc_distance(b, plane_center));
                  });

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

        // 2.E remove_if+erase for points in 3rd quadrant
        // NOTE: std::erase() is c++20 unfortunately
        points.erase(
            std::remove_if(points.begin(), points.end(),
                           [](const Point &point)
                           { return (point.x < 0 && point.y < 0); }),
            points.end());

        // 2.F output using std::ostream_iterator NOTE: assuming its to console
        std::cout << "\n2.F:\n";
        std::ostream_iterator<Point> oiter(std::cout, "\n");
        std::copy(points.begin(), points.end(), oiter);
    }

#endif
#if TASK == 3
    // ------------ 3 ---------------
    // WARN: STUDENTS.TXT IS A FILE WHERE VALUES ARE SEPERATED WITH WHITESPACE
    //       MAKE SURE THE SURNAME AND NAMES DONT CONTAIN WHITESPACES

    {
        using namespace student;
        // 3.A load from .txt file
        std::vector<Student> students = load_students(STUDENTS_PATH);

        // 3.B score_to_grade() function is a student member

        auto print_students = [&students]()
        {        for (Student &student : students)
        {
            std::cout << student.name << '\t'
                      << student.surname << '\t'
                      << student.score << '\n';
        } };

        // 3.C Map-Filter-Reduce
        // Filter
        students.erase(
            std::remove_if(
                students.begin(), students.end(),
                [](const Student &student)
                { return (student.score < SCORE_THRESHOLD); }),
            students.end());

        // Map
        std::transform(students.begin(), students.end(), students.begin(),
                       [](Student &student)
                       {
                           student.score = student.score_to_grade();
                           return student;
                       });
        // Reduce
        double students_gpa =
            std::accumulate(students.begin(), students.end(), 0.0,
                            [](double acc, const Student &student) { // its a grade here due to transform
                                return acc + student.score;
                            })

            / students.size();  // does not need a cast

        // 3.D sort by surname (ascending)
        std::sort(students.begin(), students.end(),
                  [](const Student &a, const Student &b)
                  { return (a.surname.compare(b.surname) <= 0); });

        print_students();
        std::cout << "students_gpa: " << students_gpa << '\n';
    }
#endif
}
