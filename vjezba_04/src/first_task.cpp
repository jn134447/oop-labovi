#include "../include/first_task.h"
#include <iostream>
#include <vector>

void input_vector(std::vector<int> &v) {
  int n;
  std::cout << "unesi brojeve: ";
  std::cin >> n;
  while (n != 0) {
    v.push_back(n);
    std::cin >> n;
  }
}

void print_vector(const std::vector<int> &v) {
  for (const int &e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}
