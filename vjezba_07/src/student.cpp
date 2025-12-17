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
    : ID(ID),
      name(name),
      study_program(study_program),
      year(year)
{
    ++total_students;
}

Student::Student() : ID(0),
                     name(""),
                     study_program(""),
                     year(0)
{
    ++total_students;
}

// Student::Student(Student &&other) noexcept
//     : ID(other.ID),
//       name(std::move(other.name)),
//       study_program(std::move(other.study_program)),
//       year(other.year)
// {
//     ++total_students;
// }

// Student::Student(const Student &other)
//     : ID(other.ID),
//       name(other.name),
//       study_program(other.study_program),
//       year(other.year)
// {
//     ++total_students;
// }

Student::~Student() { --total_students; };

std::ostream &operator<<(std::ostream &os, const Student &student)
{
    return os << student.ID << "\t" << student.name << "\t"
              << student.study_program << "\t" << student.year;
}

std::istream &operator>>(std::istream &is, Student &student)
{
    std::string buffer;

    buffer.clear();
    std::cout << "ID: ";
    if (std::getline(is, buffer))
        student.ID = std::stoi(buffer);

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
