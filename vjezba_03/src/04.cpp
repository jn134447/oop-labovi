#include <cstddef>
#include <iostream>

// Definirajte strukturu Student koja sadrži ime, JMBAG, godinu studija, broj
// položenih ETCS bodova u godini i prosjek ocjena.
struct Student {
  std::string name;
  std::string JMBAG;
  unsigned short year;
  int ECTS;
  float GPA;
};

// Napišite funkciju za filtriranje studenata koja
// prima niz studenata i dva pointera na funkciju, jedan za akciju koja će se
// izvršiti, a druga za uvjet filtriranja.
void filter_students(Student students[], std::size_t arr_len,
                     void (*action)(Student &), bool (*filter)(Student &)) {

  for (std::size_t i = 0; i < arr_len; i++)
    if (filter(students[i]))
      action(students[i]);

  return;
}

void print_student(Student &student) {
  std::cout << student.name << ", ";
  std::cout << student.JMBAG << ", ";
  std::cout << student.year << ", ";
  std::cout << student.ECTS << ", ";
  std::cout << student.GPA << ", ";
  std::cout << std::endl;
}

inline void increment_year(Student &student) { student.year++; }

int main() {
  Student students[] = {
      {"name_1", "AAAAAAAAAA", 1, 0, 0},
      {"name_2", "BBBBBBBBBB", 2, 45, 3.50},
      {"name_3", "CCCCCCCCCC", 3, 40, 3.71},
      {"name_4", "DDDDDDDDDD", 4, 60, 4.07},
  };
  std::size_t arr_len = sizeof(students) / sizeof(students[0]);

  auto print_students = [&students]() {
    for (auto &student : students)
      print_student(student);
  };
  auto passed_an_exam = [](Student &student) {
    return (student.GPA != 0) ? true : false;
  };
  auto GPA_higher_than_3_point_5 = [](Student &student) {
    return (student.GPA > 3.5) ? true : false;
  };
  auto ECTS_45_or_higher = [](Student &student) {
    return (student.ECTS >= 45) ? true : false;
  };

  std::cout << "svi studenti: " << std::endl;
  print_students();
  std::cout << std::endl;

  // Ispis (akcija) svih studenata prve godine koji su položili barem jedan
  // ispit (uvjet).
  std::cout << "polozili baren jedan ispit: " << std::endl;
  filter_students(students, arr_len, print_student, passed_an_exam);
  std::cout << std::endl;

  // Ispis (akcija) svih studenata koji imaju prosjek veći od 3.5 (uvjet).
  std::cout << "prosjek veci od 3.5: " << std::endl;
  filter_students(students, arr_len, print_student, GPA_higher_than_3_point_5);
  std::cout << std::endl;

  // Povećanje broja godine studija (akcija) studenata koji su položili barem 45
  // ETCS bodova (uvjet).
  std::cout << "povecanje godine studenata sa ECTS priko 45: " << std::endl
            << "ispis svih studenata (azurirane godine): " << std::endl;
  filter_students(students, arr_len, increment_year, ECTS_45_or_higher);
  print_students();
}
