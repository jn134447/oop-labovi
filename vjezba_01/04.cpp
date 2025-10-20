#include <iostream>

/*
4. Napišite funkciju at koja vraća referencu na neki element C-niza. Koris-
teći povratnu vrijednost funkcije kao lvalue uvećajte i-ti element niza
za jedan.
*/

using namespace std;

int &at(int *arr, int i) { return arr[i]; }

int main() {
  int arr[] = {1, 2, 3, 4, 5};

  for (int i : arr)
    cout << i << " ";
  cout << endl;

  at(arr, 2) += 1;

  for (int i : arr)
    cout << i << " ";
  cout << endl;
}
