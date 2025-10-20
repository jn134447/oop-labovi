#include "../include/matrix.h"
#include <iomanip>
#include <iostream>

using namespace std;

// m = row
// n = column
Matrix create_empty_matrix(int row, int column) {
  Matrix matrix;
  matrix.m = row;
  matrix.n = column;
  matrix.elements = new float *[matrix.m]();
  for (int i = 0; i < row; i++)
    matrix.elements[i] = new float[matrix.n]();
  return matrix;
}

Matrix user_defined_matrix(int row, int column) {
  Matrix matrix = create_empty_matrix(row, column);
  for (int i = 0; i < matrix.m; i++)
    for (int j = 0; j < matrix.n; j++)
      cin >> matrix.elements[i][j];
  return matrix;
}

// biggest BS in the task, the `end`(b) param is legit only for error checking,
// it is NOT used as an "end" to the sequence as a matrix already has limited
// space, meaning any overflow from range is never accounted for, making `end`
// useless as the sequence ends when the matrix ends.
// The requirements are insanely vague anyways, this [a,b] could mean anything.
// i'm assuming its a range of natural numbers
Matrix range_defined_matrix(int row, int column, int start, int end) {
  Matrix matrix = create_empty_matrix(row, column);

  int range_len = end - start + 2;
  if (range_len <= (matrix.m * matrix.n)) {
    cout << "error: range(" << start << ", " << end
         << ") is too small to cover the entire matrix " << endl;
    return matrix;
  }
  if (start > end) {
    cout << "error: start bigger than end of sequence" << endl;
    return matrix;
  }

  for (int i = 0; i < matrix.m; i++)
    for (int j = 0; j < matrix.n; j++)
      matrix.elements[i][j] = start++;
  return matrix;
}

Matrix operate_matrices(Matrix &A, Matrix &B, char op) {
  if (A.m != B.m || A.n != B.n) {
    cout << "error: Matrices with different dimensions cant be added/subtracted"
         << endl;
    return Matrix{nullptr, 0, 0};
  }

  Matrix C = create_empty_matrix(A.m, A.n);

  for (int i = 0; i < C.m; i++) {
    for (int j = 0; j < C.n; j++) {
      if (op == '+')
        C.elements[i][j] = A.elements[i][j] + B.elements[i][j];
      else if (op == '-')
        C.elements[i][j] = A.elements[i][j] - B.elements[i][j];
    }
  }
  return C;
}
Matrix add_matrices(Matrix &A, Matrix &B) {
  return operate_matrices(A, B, '+');
}
Matrix subtract_matrices(Matrix &A, Matrix &B) {
  return operate_matrices(A, B, '-');
}

void print_matrix(Matrix &matrix) {
  cout << endl;
  for (int i = 0; i < matrix.m; i++) {
    for (int j = 0; j < matrix.n; j++) {
      cout << right << setw(9) << fixed << setprecision(4)
           << matrix.elements[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

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
  Matrix matrix_d = range_defined_matrix(3, 2, 1, 6);

  print_matrix(matrix_a);
  print_matrix(matrix_b);
  print_matrix(matrix_c);
  print_matrix(matrix_d);

  Matrix matrix_c_add_d = add_matrices(matrix_c, matrix_d);
  Matrix matrix_c_sub_d = subtract_matrices(matrix_c, matrix_d);

  cout << "add/sub: ";
  print_matrix(matrix_c_add_d);
  print_matrix(matrix_c_sub_d);
}
