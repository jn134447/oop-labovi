
#ifndef STUDENT_H
#define STUDENT_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace student
{

    class Student
    {
    public:
        std::string name;
        std::string surname;
        int score;

        Student() = default;
        Student(std::istream &is);

        int score_to_grade() const;
    };

    std::istream &operator>>(std::istream &is, Student &student);

    std::vector<Student> load_students(const std::filesystem::path &path);

} 
#endif