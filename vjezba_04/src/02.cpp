#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "../include/first_task.h"

// 2. Koristeći funkcije iz zadatka 1:
//   unesite vektor cijelih brojeva
//   pronađite sve jedinstvene elemente iz vektora
//   sortirajte jedinstvene elemente po apsolutnoj vrijednosti (od najmanjeg do
//   najvećeg) ispišite sortirane jedinstvene elemente zajedno s njihovim
//   apsolutnim vrijednostima
// Napomena: Koristite STL algoritme std::find i std::sort s lambda izrazom.

int main() {
  std::vector<int> vec;
  std::vector<int> unique_numbers;
  input_vector(vec);

  for (int e : vec)
    if (std::count(unique_numbers.begin(), unique_numbers.end(), e) == 0)
      unique_numbers.push_back(e);

  auto abs_value_sort = [&](int x, int y) { return abs(x) < abs(y); };

  std::sort(unique_numbers.begin(), unique_numbers.end(), abs_value_sort);

  print_vector(unique_numbers);
}
