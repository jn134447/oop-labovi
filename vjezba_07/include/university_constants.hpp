#ifndef UNIVERSITY_CONSTANTS_H
#define UNIVERSITY_CONSTANTS_H

#include <iostream>

struct UniversityConstants
{
    const int MAX_ETCS_PER_YEAR = 60;
    const int REQUIRED_ECTS_PER_YEAR = 45;
    const int MAX_AMOUNT_ENROLLED_CLASSES = 100;

    void print_university_rules() const;
};

#endif