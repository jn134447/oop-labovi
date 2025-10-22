#include "../include/matrix.h"
#include <iostream>

using namespace std;

int main() {
  int m;
  int n;
  cout << "m: ";
  cin >> m;
  cout << "n: ";
  cin >> n;

  Matrix matrix_a = user_defined_matrix(m, n);
  Matrix matrix_b = range_defined_matrix(3, 2, 1, 6);
  Matrix matrix_c = range_defined_matrix(3, 2, -6, 0);
  Matrix matrix_d = range_defined_matrix(5, 2, 1, 10);

  cout << "A: ";
  print_matrix(matrix_a);
  cout << "B: ";
  print_matrix(matrix_b);
  cout << "C: ";
  print_matrix(matrix_c);
  cout << "D: ";
  print_matrix(matrix_d);

  Matrix matrix_add_exmpl = add_matrices(matrix_b, matrix_c);
  if (!matrix_add_exmpl.elements)
    return 1;

  Matrix matrix_sub_exmpl = subtract_matrices(matrix_b, matrix_c);
  if (!matrix_sub_exmpl.elements)
    return 2;

  Matrix matrix_d_transposed = transpose_matrix(matrix_d);

  Matrix matrix_mul_exmpl = multiply_matrices(matrix_c, matrix_d_transposed);
  if (!matrix_mul_exmpl.elements)
    return 3;

  cout << "D_transposed:";
  print_matrix(matrix_d_transposed);
  cout << "add(B+C): ";
  print_matrix(matrix_add_exmpl);
  cout << "sub(B-C): ";
  print_matrix(matrix_sub_exmpl);
  cout << "mul(C*D_t): ";
  print_matrix(matrix_mul_exmpl);
}
