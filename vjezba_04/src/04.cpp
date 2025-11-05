#include <iostream>
#include <string>

// 4. Napišite funkciju std::string word_to_pig_latin(const std::string& word)
// koja:
//   ako riječ počinje samoglasnikom: dodaje ”hay”
//   ako počinje suglasnikom: premješta prvo slovo na kraj i dodaje ”ay”
// Primjer:
//  "apple" -> "applehay"
//  "hello" -> "ellohay"

std::string word_to_pig_latin(const std::string &word) {
  std::string new_word;
  auto is_vowel = [](char c) {
    return std::string("aeiouAEIOU").find(c) != std::string::npos;
  };
  if (is_vowel(word.at(0))) {
    new_word.append(word + "hay");
  } else {
    new_word.append(word.substr(1) + "ay");
  }
  return new_word;
}

int main() {
  std::string apple = "apple";
  std::string hello = "hello";
  std::string pl_apple = word_to_pig_latin(apple);
  std::string pl_hello = word_to_pig_latin(hello);
  std::cout << apple << " -> " << pl_apple << std::endl;
  std::cout << hello << " -> " << pl_hello << std::endl;
}
