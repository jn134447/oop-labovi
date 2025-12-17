#ifndef UNIVERSITY
#define UNIVERSITY

#include <iostream>
#include <string>
#include <memory>
#include <vector>

// 1. Kreirajte klasu Student koja ima:
// · privatne članove int id,
// · std::string name,
// · std::string study_program,
// · int year,
// · konstruktor koji koristi member initialization list,
// · operator<< i operator>> za ispis i unos.
// Testirajte tako što ćete kreirati vector studenata unoseći studente i
// ispisati ih.

// 2. U klasu Student dodajte:
// · static privatni član total_students,
// · static member funkciju get_total_students().
// · Napišite potrebne konstruktore i destruktore i u njima ažurirajte total_students.
// Testirajte!

// 3. Kreirajte strukturu UniversityConstants sa postavkama za pravila sveučilišta:
// · konstantu MAX_ETCS_PER_YEAR = 60,
// · konstantu REQUIRED_ECTS_PER_YEAR = 45,
// · member funkciju print_university_rules() koja ispisuje sve konstante.
// Testirajte!

// 4. Kreirajte klasu Course koja predstavlja kolegij i sadrži:
// · ime kolegija,
// · šifru kolegija,
// · broj ECTS bodova,
// · operator<< i operator>> za ispis i unos.
// Testirajte!

// 5. Proširite Student klasu s dinamičkim nizovima:
// · dodaj Course* enrolled_courses (niz na heapu),
// · dodaj size_t enrolled_count,
// · dodaj Course* completed_courses (niz na heapu),
// · dodaj size_t completed_count,
// · implementirajte Rule of Five,
// · implementirajte funkcije potrebne za upisivanje kolegija i polaganje kolegija.
// Na početku studija student ne mora imati nijedan upisan kolegij.
//  Studente upisuje
// referada (kasnije). Testirajte!

class Course
{
private:
    std::string id;
    std::string name;
    int ects;

public:
    Course();
    Course(std::string name, std::string ID, int ECTS);

    friend std::ostream &operator<<(std::ostream &os, const Course &course);
    friend std::istream &operator>>(std::istream &is, Course &course);
};

struct UniversityConstants
{
    const int MAX_ETCS_PER_YEAR = 60;
    const int REQUIRED_ECTS_PER_YEAR = 45;

    void print_university_rules() const;
};

class Student
{
private:
    int id;
    std::string name;
    std::string study_program;
    int year;

    static int total_students;

    std::unique_ptr<std::vector<Course>> enrolled_courses;
    std::size_t enrolled_count;
    std::unique_ptr<std::vector<Course>> completed_courses;
    std::size_t completed_count;

public:
    // int get_ID() const;
    // std::string get_name() const;
    // std::string get_study_program() const;
    // int get_year() const;
    static int get_total_students();

    Student();
    Student(int ID, std::string name, std::string study_program, int year);

    Student(Student &&other) noexcept;
    Student(const Student &other);

    ~Student();

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    friend std::istream &operator>>(std::istream &is, Student &student);
};

#endif