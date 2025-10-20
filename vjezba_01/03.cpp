#include <cctype>
#include <iostream>
#include <string>

/*
3. Učitajte jedan redak u std::string s (std::getline). Koristeći range-based
for sva slova pretvorite u velika, znamenke zamijenite znakom '*', a
razmake i tabove znakom '_'. Ispišite dobiveni string.
Napomena: za std::string koristite #include <string>, a za std::toupper
koristite #include <cctype>
*/

using namespace std;

int main() {
  string s;
  getline(cin, s);

  for (char &i : s) {
    i = toupper(i);
    if (isdigit(i))
      i = '*';
    else if (i == ' ' || i == '\t')
      i = '_';
  }

  cout << s << endl;
}
