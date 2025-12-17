#include "student.hpp"

#include <vector>

int main()
{
    UniversityConstants uni_consts;
    std::vector<Student> students;
    students.reserve(3);

    for (int i = 0; i < 3; i++)
        students.emplace_back();

    std::cout << "total_studens:\t" << Student::get_total_students() << '\n';
    for (Student &student : students)
    {
        std::cout << student << '\n';
        students.erase(students.begin());
        std::cout << "total_studens:\t" << Student::get_total_students() << '\n';
    }

    uni_consts.print_university_rules();
}