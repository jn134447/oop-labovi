#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 5. Napišite funkciju void reverse_strings(vector<string>& words) koja svaki
// string u vek- toru okrene naopako. Inicijalizirajte vektor stringova s
// nekoliko riječi. Ispišite vektor prije i nakon okretanja.
//
// Primjer: ["hello", "world", "c++"] -> ["olleh", "dlrow", "++c"]
//
// Napomena: Koristite std::reverse za okretanje stringova.

void reverse_strings(std::vector<std::string> &words) {
  for (std::string &word : words) {
    std::reverse(word.begin(), word.end());
  }
}

int main() {
  std::vector<std::string> words{"hello", "world", "c++"};
  auto print_vec = [&words]() {
    for (std::string &word : words)
      std::cout << word << " ";
    std::cout << std::endl;
  };

  print_vec();
  reverse_strings(words);
  print_vec();
}
