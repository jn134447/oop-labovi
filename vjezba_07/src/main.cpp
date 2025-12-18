#include "student.hpp"

#include <vector>

int main()
{
    UniversityConstants uni_consts;

    std::vector<Student> students;
    students.reserve(3);

    for (int i = 0; i < 3; i++)
        students.emplace_back();

    for (Student &student : students)
    {
        std::cout << student << '\n';
    }

    std::vector<Course> courses;
    courses.reserve(3);

    courses.emplace_back("SRC101", "name1", 60);
    courses.emplace_back("SRC102", "name2", 5);
    courses.emplace_back("SRC103", "name3", 60);

    for (Course &course : courses)
    {
        std::cout << course << '\n';
    }

    uni_consts.print_university_rules();
    std::cout << '\n';

    students.at(0)
        .enroll_course(courses.at(0))
        .enroll_course(courses.at(1))
        .enroll_course(courses.at(2));
    students.at(0).print_enrolled_courses();

    students.at(0).print_completed_courses();
    students.at(0).complete_course(courses.at(2));
    std::cout << "after adding, ";
    students.at(0).print_completed_courses();

    ++students.at(0);
    students.at(1)++;

    std::cout << '\n'
              << students.at(0) << '\n'
              << students.at(1) << '\n';

    StudentOffice office;
    office.process_exam_results(students);
    office.update_student_years(students);

    std::cout << '\n'
              << students.at(0) << '\n'
              << students.at(1) << '\n';
}