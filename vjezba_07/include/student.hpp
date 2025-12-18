#ifndef UNIVERSITY
#define UNIVERSITY

#include "courses.hpp"
#include "university_constants.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <vector>

constexpr unsigned short MAX_COURSES_ARRAY_SIZE = 100;

class Student
{
private:
    int id;
    std::string name;
    std::string study_program;
    int year;

    static int total_students;

    std::unique_ptr<Course[]> enrolled_courses;
    std::size_t enrolled_count = 0;

    std::unique_ptr<Course[]> completed_courses;
    std::size_t completed_count = 0;
    int acquired_ects = 0;

public:
    static int get_total_students();

    Student &enroll_course(const Course &course);
    Student &complete_course(const Course &course);
    void print_enrolled_courses() const;
    void print_completed_courses() const;

    Student();
    Student(int ID, std::string name, std::string study_program, int year);

    Student(Student &&other) noexcept;
    Student(const Student &other);
    Student &operator=(Student &&other) = delete; // no.
    Student &operator=(const Student &other) = delete;

    Student &operator+=(const Course &course);
    // prefix increment
    Student &operator++();

    // postfix increment
    Student operator++(int);

    ~Student();

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    friend std::istream &operator>>(std::istream &is, Student &student);

    friend class StudentOffice;
};

#include "student_office.hpp"

#endif