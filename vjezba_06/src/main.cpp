#include <array>
#include <iostream>
#include <string>

#include "container.hpp"

/*
U main funkciji demonstrirajte sljedeće:
1. Kreiranje containera default konstruktorom i dodavanje elemenata.
2. Kopiranje containera pomoću copy konstruktora.
3. Korištenje move konstruktora za prijenos resursa
(container novi=std::move(original);.
4. Prosljeđivanje containera funkciji po vrijednosti (poziva copy konstruktor).
5. Vraćanje containera iz funkcije (može pozvati move konstruktor).
(for clang++: "-fno-elide-constructors")
6. Realokaciju memorije dodavanjem elemenata preko kapaciteta.
7. Ispis svih elemenata containera s indeksima i vrijednostima.
*/

void
print_alloc_elem_size(Container<std::string> container)
{
  std::cout << "there should be a copied constructor msg before this one."
            << '\n';

  std::cout << "container.capacity(): " << std::to_string(container.capacity())
            << '\n'; // cant change it (private) but changing this should
                     // NOT change the original container alloc_elem_size
}

Container<int>
fun()
{
  Container<int> temp;
  for (int i = -3; i < 3; i++)
    temp.push_back(i);

  return temp; // compiler flag for clang++: "-fno-elide-constructors"
  // without it ROV will optimize this code and will not implicitly move
}

int
main()
{
  std::cout << '\n' << "1, ctor+pushback: " << '\n';
  // 1. Kreiranje containera default konstruktorom i dodavanje elemenata.
  Container<std::string> c1;
  std::array<std::string, 5> temp{ "one", "two", "three", "four", "five" };
  for (std::string e : temp) {
    // 6. Realokaciju memorije dodavanjem elemenata preko kapaciteta.
    c1.push_back(e);
  }

  std::cout << '\n' << "2, explicit copy ctor: " << '\n';
  // 2. Kopiranje containera pomoću copy konstruktora.
  Container<std::string> c2(c1); // c1=source, c2=dest

  std::cout << '\n' << "3, explicit move ctor " << '\n';
  // 3. Korištenje move konstruktora za prijenos resursa
  Container<std::string> c3(std::move(c1)); // c1 is empty after this line

  std::cout << '\n' << "4, function call(implicit copy ctor): " << '\n';
  // 4. Prosljeđivanje containera funkciji po vrijednosti (poziva copy
  // konstruktor).
  print_alloc_elem_size(c3);

  std::cout << '\n' << "5, function return(implicit move ctor): " << '\n';
  // 5. Vraćanje containera iz funkcije (može pozvati move konstruktor).
  Container<int> c4 = fun();
  c4.print("c4: ");

  std::cout << '\n' << "6, pushing 4 items" << '\n';
  // 6. Realokaciju memorije dodavanjem elemenata preko kapaciteta.
  c3.push_back("six");
  c3.push_back("seven");
  c3.push_back("eight");
  c3.push_back("nine");

  std::cout << '\n' << "7, print elems and indexes" << '\n';
  // 7. Ispis svih elemenata containera s indeksima i vrijednostima.
  c3.print("c3: ");

  std::cout << '\n' << "8, defined initial_capacity" << '\n';
  Container<int> c5(5);
  std::cout << "c5.cap(): " << c5.capacity() << '\n'
            << "c5.size(): " << c5.size() << '\n';

  std::cout << '\n' << "end of main (5 destructions should be here)" << '\n';
}
