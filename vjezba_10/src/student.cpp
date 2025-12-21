#include "student.hpp"

std::istream &student::operator>>(std::istream &is, Student &student)
{
    student = Student(is);
    return is;
}

std::vector<student::Student>
student::load_students(const std::filesystem::path &path)
{
    std::ifstream file(path);
    if (!file)
        throw std::ios_base::failure("File students.txt not found");

    std::vector<Student> students;

    Student temp;
    while (file >> temp)
        students.emplace_back(temp);

    return students;
}


student::Student::Student(std::istream &is) { is >> name >> surname >> score; }

int student::Student::score_to_grade() const
{
    if (score < 0 || score > 100)
        throw std::out_of_range("score must be 0..100");
    if (score <= 39)
        return 1;
    if (score <= 54)
        return 2;
    if (score <= 69)
        return 3;
    if (score <= 84)
        return 4;
    return 5; // 85..100
}
