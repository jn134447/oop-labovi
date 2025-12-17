#include "student.hpp"

// int Student::get_ID() const { return this->ID; };
// std::string Student::get_name() const { return this->name; }
// std::string Student::get_study_program() const { return this->study_program; }
// int Student::get_year() const { return this->year; };

int Student::total_students = 0;

int Student::get_total_students() { return total_students; }

Student &Student::enroll_course(const Course &course)
{
    enrolled_courses[enrolled_count] = course;
    enrolled_count += 1;
    return *this;
}

Student &Student::complete_course(const Course &course)
{
    bool found_course = false;
    for (std::size_t i = 0; i < enrolled_count; i++)
    {
        if (enrolled_courses[i].get_id() == course.get_id() &&
            enrolled_courses[i].get_name() == course.get_name() &&
            enrolled_courses[i].get_ects() == course.get_ects())
        {
            completed_courses[completed_count] = std::move(enrolled_courses[i]);
            completed_count += 1;
            found_course = true;
            acquired_ects += course.get_ects();
            break;
        }
    }
    if (!found_course)
        std::cout << "Couldnt find course";

    return *this;
}

void Student::print_enrolled_courses() const
{
    std::cout << "enrolled courses: " << '\n';
    std::cout << "student: " << *this << '\n';

    for (std::size_t i = 0; i < enrolled_count; i++)
        std::cout << enrolled_courses[i] << '\n';
}

void Student::print_completed_courses() const
{
    std::cout << "completed courses: " << '\n';
    std::cout << "student: " << *this << '\n';

    for (std::size_t i = 0; i < completed_count; i++)
        std::cout << completed_courses[i] << '\n';
}

Student::Student(int ID,
                 std::string name,
                 std::string study_program,
                 int year)
    : id(ID),
      name(name),
      study_program(study_program),
      year(year)
{
    enrolled_courses = std::make_unique<Course[]>(MAX_COURSES_ARRAY_SIZE);
    completed_courses = std::make_unique<Course[]>(MAX_COURSES_ARRAY_SIZE);
    ++total_students;
}

Student::Student() : id(0),
                     name("default_name"),
                     study_program("default_program"),
                     year(0)
{
    enrolled_courses = std::make_unique<Course[]>(MAX_COURSES_ARRAY_SIZE);
    completed_courses = std::make_unique<Course[]>(MAX_COURSES_ARRAY_SIZE);
    ++total_students;
}

Student::Student(Student &&other) noexcept
    : id(other.id),
      name(std::move(other.name)),
      study_program(std::move(other.study_program)),
      year(other.year),
      enrolled_courses(std::move(other.enrolled_courses)),
      enrolled_count(other.enrolled_count),
      completed_courses(std::move(other.completed_courses)),
      completed_count(other.completed_count)
{
}

Student::Student(const Student &other)
    : id(other.id),
      name(other.name),
      study_program(other.study_program),
      year(other.year),
      enrolled_count(other.enrolled_count),
      completed_count(other.completed_count)
{
    enrolled_courses = std::make_unique<Course[]>(MAX_COURSES_ARRAY_SIZE);
    for (std::size_t i = 0; i < other.enrolled_count; i++)
        enrolled_courses[i] = other.enrolled_courses[i];

    completed_courses = std::make_unique<Course[]>(MAX_COURSES_ARRAY_SIZE);
    for (std::size_t i = 0; i < other.completed_count; i++)
        completed_courses[i] = other.completed_courses[i];
}

Student &Student::operator+=(const Course &course)
{
    this->enroll_course(course);
    return *this;
}

Student &Student::operator++()
{
    // actual increment takes place here
    UniversityConstants uni_const;
    if (acquired_ects >= uni_const.REQUIRED_ECTS_PER_YEAR)
    {
        this->year++;
    }

    return *this; // return new value by reference
}
Student Student::operator++(int)
{
    Student old = *this; // copy old value
    operator++();        // prefix increment
    return old;          // return old value
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
