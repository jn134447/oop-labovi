#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

// 3. Napišite funkciju void fix_spaces(std::string& text) koja:
//   uklanja višestruke razmake (ostavlja samo jedan razmak između riječi),
//   uklanja razmake prije zareza i točke, a dodaje, ako već nema, razmak nakon
// zareza. Napomena: Koristite funkcije STL-a za pronalaženje, brisanje i
// dodavanje znakova.

void fix_spaces(std::string &text) {
  auto space = text.begin();
  while (true) {
    space = std::find(space, text.end(), ' ');
    if (space == text.end()) {
      break;
    }
    if (text.at(std::distance(text.begin(), space) + 1) == ' ') {
      text.erase(space);
    } else {
      space++;
    }
  }
  auto punctuation = [](char c) { return (c == ',' || c == '.'); };
  auto comma = text.begin();
  while (true) {
    comma = std::find_if(comma, text.end(), punctuation);
    if (comma == text.end()) {
      break;
    }
    if (comma + 1 != text.end()) {
      if (text.at(std::distance(text.begin(), comma) + 1) != ' ') {
        text.insert(comma + 1, ' ');
      }
    }
    if (text.at(std::distance(text.begin(), comma) - 1) == ' ') {
      text.erase(comma - 1);
    } else {
      comma++;
    }
  }
}

int main() {
  std::string str_a{"Primjer: Puno        razmaka   ,i tocka ."};

  std::cout << str_a << std::endl;
  fix_spaces(str_a);
  std::cout << str_a << std::endl;
}
