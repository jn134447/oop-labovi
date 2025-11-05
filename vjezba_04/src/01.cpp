#include <iostream>
#include <vector>

#include "../include/first_task.h"

// 1. Napišite funkcije:
//   void input_vector(vector<int>& v) - unosi brojeve dok se ne unese 0
//   void print_vector(const vector<int>& v) - ispisuje vektor


int main() {
  std::vector<int> vec;

  input_vector(vec);
  print_vector(vec);
}
