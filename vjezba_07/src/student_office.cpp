#include "student_office.hpp"

void StudentOffice::moveStudent(Student &student, std::string new_study_program)
{
    student.study_program = std::move(new_study_program);
}

// enroll_student() koja studentu doda kolegij, ako broj ECTS upisanih kolegija stu-
// denta ne prelazi UniversityConstants::MAX_ETCS_PER_YEAR,
void StudentOffice::enroll_student(Student &student, const Course &course)
{
    UniversityConstants uni_consts;
    if (student.acquired_ects + course.get_ects() > uni_consts.MAX_ETCS_PER_YEAR)
        return;

    student.enroll_course(course);
}

void StudentOffice::process_exam_results(std::vector<Student> &students)
{
    // ECTS points are processed when completing a course,
    //  but fk it lets refresh it here again
    for (Student &student : students)
    {
        student.acquired_ects = 0;
        for (std::size_t i = 0; i < student.completed_count; i++)
        {
            student.acquired_ects += student.completed_courses[i].get_ects();
        }
    }

    return;
}

void StudentOffice::update_student_years(std::vector<Student> &students)
{
    for (Student &student : students)
        student++;
}
