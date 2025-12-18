#include "courses.hpp"

Course::Course() : id("default_id"), name("default_name"), ects(0) {}

Course::Course(std::string ID,
               std::string name,
               int ECTS)
    : id(ID),
      name(name),
      ects(ECTS)
{
}

std::string Course::get_id() const { return id; }
std::string Course::get_name() const { return name; }
int Course::get_ects() const { return ects; }

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