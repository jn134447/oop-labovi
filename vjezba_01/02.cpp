#include <iostream>

/*
2. Napišite dvije funkcije istog imena (preopterećenje za različite tipove,
npr. int i double) koje ograničavaju vrijednost na interval [low, high]. Mo-
žete pretpostaviti da je low <= high.

Ako je vrijednost manja od low, funkcija vraća low; ako je veća od high,
vraća high; inače vraća izvornu vrijednost.

Za low i high postavite pretpostavljene vrijednosti. U main pozovite obje
varijante za nekoliko ulaza i ispišite rezultate.
*/

using namespace std;

int function(int x, int low = 2, int high = 5) {
  if (x < low)
    return low;
  if (x > high)
    return high;
  return x;
}
double function(double x, double low = 2, double high = 5) {
  if (x < low)
    return low;
  if (x > high)
    return high;
  return x;
}

int main() {
  int x = 0;
  double y = 0;

  cout << "low: 2, high: 5" << endl;

  cout << "use int: " << endl;
  cin >> x;
  cout << "returned: " << function(x) << endl;

  cout << "use double: " << endl;
  cin >> y;
  cout << "returned: " << function(y) << endl;
}
