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

// definition of range for this function is too vague
Matrix range_defined_matrix(int row, int column, int start, int end) {
  Matrix matrix = create_empty_matrix(row, column);

  int range_len = end - start + 2;
  if (range_len <= (matrix.m * matrix.n)) {
    cout << "error: range[" << start << ", " << end
         << "] is too small to cover the entire matrix of "
         << (matrix.m * matrix.n) << endl;
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

Matrix transpose_matrix(Matrix &A) {
  Matrix A_t = create_empty_matrix(A.n, A.m);
  for (int i = 0; i < A_t.m; i++) {
    for (int j = 0; j < A_t.n; j++) {
      A_t.elements[i][j] = A.elements[j][i];
    }
  }
  return A_t;
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

/* WIKIPEDIA:
 *  Input: matrices A[n*m] and B[m*p]
 *  Let C[n*p] be a new matrix of the appropriate size
 *  For i from 1 to n:
 *      For j from 1 to p:
 *          Let sum = 0
 *          For k from 1 to m:
 *              Set sum ← sum + Aik × Bkj
 *          Set Cij ← sum
 *  Return C
 */
Matrix multiply_matrices(Matrix &A, Matrix &B) {
  if (A.n != B.m) {
    cout << "error: cant multiply incompatable matrices" << endl;
    return Matrix{nullptr, 0, 0};
  }

  Matrix C = create_empty_matrix(A.m, B.n);
  int sum;
  for (int i = 0; i < C.m; i++) {
    for (int j = 0; j < C.n; j++) {
      sum = 0;
      for (int k = 0; k < B.m; k++) // or A.n
        sum = sum + A.elements[i][k] * B.elements[k][j];
      C.elements[i][j] = sum;
    }
  }

  return C;
}

void print_matrix(Matrix &matrix, int width) {
  cout << endl;
  for (int i = 0; i < matrix.m; i++) {
    for (int j = 0; j < matrix.n; j++) {
      cout << right << setw(width) << fixed << setprecision(4)
           << matrix.elements[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
