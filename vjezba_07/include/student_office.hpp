#ifndef STUDENT_OFFICE_H
#define STUDENT_OFFICE_H

#include "student.hpp"

class StudentOffice
{
public:
    // Korisitite move semantiku. ??????????
    void moveStudent(Student &student, std::string new_study_program);

    void enroll_student(Student& student, const Course& course);
    void process_exam_results(std::vector<Student>& students);
    void update_student_years(std::vector<Student>& students);
};

#endif