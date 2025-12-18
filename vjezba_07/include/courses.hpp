#ifndef COURSES
#define COURSES

#include <string>
#include <iostream>

class Course
{
private:
    std::string id;
    std::string name;
    int ects;

public:
    Course();
    Course(std::string name, std::string ID, int ECTS);

    std::string get_id() const;
    std::string get_name() const;
    int get_ects() const;

    friend std::ostream &operator<<(std::ostream &os, const Course &course);
    friend std::istream &operator>>(std::istream &is, Course &course);
};



#endif