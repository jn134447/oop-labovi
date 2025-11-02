#include <iomanip>
#include <iostream>

/*
1. Unesite sljedeći program i modificirajte ga testirajući gornje manipula-
tore.
*/

int main() {
  bool flag;
  std::cout << "unesi " << true << " - " << false << std::endl;
  std::cin >> flag;
  std::cout << std::boolalpha << flag << std::endl;

  int a = 255;
  std::cout << "hex " << std::hex << a << std::endl;
  std::cout << "dec " << std::dec << a << std::endl;
  std::cout << "oct " << std::oct << a << std::endl;

  double pi = 3.141592;
  std::cout << "pi = " << std::fixed << std::uppercase;
  std::cout << std::setprecision(20) << std::setw(20);
  std::cout << std::setfill('0');
  std::cout << pi << std::endl;
  std::cout << std::flush;
  // std::cout << std::resetiosflags;
  std::cout << std::setprecision(3) << std::setw(3) << std::endl;
  std::cout << pi << std::endl;
}
