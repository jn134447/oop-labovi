#include <iostream>

using namespace std;

// m = row
// n = column

int **user_defined_matrix(unsigned int row, unsigned int column) {
  // init 2D array
  int **matrix = new int *[row]();
  for (int i = 0; i < row; i++)
    matrix[i] = new int[column]();


}

int main() {
  int m;
  int n;
  cout << "m: " << m << endl;
  cout << "n: " << n << endl;
  int **matrix = user_defined_matrix(m, n);
}
