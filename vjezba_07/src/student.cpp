#include "student.hpp"

// int Student::get_ID() const { return this->ID; };
// std::string Student::get_name() const { return this->name; }
// std::string Student::get_study_program() const { return this->study_program; }
// int Student::get_year() const { return this->year; };

int Student::total_students = 0;

int Student::get_total_students() { return total_students; }

Student::Student(int ID,
                 std::string name,
                 std::string study_program,
                 int year)
    : id(ID),
      name(name),
      study_program(study_program),
      year(year)
{
    ++total_students;
}

Student::Student() : id(0),
                     name(""),
                     study_program(""),
                     year(0)
{
    ++total_students;
}

Student::~Student() { --total_students; };

std::ostream &operator<<(std::ostream &os, const Student &student)
{
    return os << student.id << "\t"
              << student.name << "\t"
              << student.study_program << "\t"
              << student.year;
}
std::istream &operator>>(std::istream &is, Student &student)
{
    std::string buffer;

    buffer.clear();
    std::cout << "ID: ";
    if (std::getline(is, buffer))
        student.id = std::stoi(buffer);

    buffer.clear();
    std::cout << "name: ";
    if (std::getline(is, buffer))
        student.name = buffer;

    buffer.clear();
    std::cout << "study_program: ";
    if (std::getline(is, buffer))
        student.study_program = buffer;

    buffer.clear();
    std::cout << "year: ";
    if (std::getline(is, buffer))
        student.year = std::stoi(buffer);

    return is;
}

void UniversityConstants::print_university_rules() const
{
    std::cout << "MAX_ETCS_PER_YEAR = " << MAX_ETCS_PER_YEAR << '\n';
    std::cout << "REQUIRED_ECTS_PER_YEAR = " << REQUIRED_ECTS_PER_YEAR << '\n';
}

Course::Course() : id(""), name(""), ects(0) {}

Course::Course(std::string ID,
               std::string name,
               int ECTS)
    : id(ID),
      name(name),
      ects(ECTS)
{
}

std::istream &operator>>(std::istream &is, Course &course)
{
    std::string buffer;

    buffer.clear();
    std::cout << "ID: ";
    if (std::getline(is, buffer))
        course.id = buffer;

    buffer.clear();
    std::cout << "name: ";
    if (std::getline(is, buffer))
        course.name = buffer;

    buffer.clear();
    std::cout << "ECTS: ";
    if (std::getline(is, buffer))
        course.ects = std::stoi(buffer);

    return is;
}
std::ostream &operator<<(std::ostream &os, const Course &course)
{
    return os << course.id << "\t"
              << course.name << "\t"
              << course.ects;
}
