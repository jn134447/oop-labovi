#ifndef STUDENT_OFFICE
#define STUDENT_OFFICE

#include "student.hpp"

class StudentOffice
{
public:
    // Korisitite move semantiku. ??????????
    void moveStudent(Student &student, std::string new_study_program);

    void enroll_student(Student& student, const Course& course);
    void process_exam_results(std::vector<Student>& students);
};

#endif