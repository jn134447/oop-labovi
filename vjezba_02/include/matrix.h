#ifndef MATRIX
#define MATRIX

struct Matrix {
  float **elements;
  int m;
  int n;
};

Matrix create_empty_matrix(int row, int column);
Matrix user_defined_matrix(int row, int column);
Matrix range_defined_matrix(int row, int column, int start, int end);
Matrix transpose_matrix(Matrix &A);
Matrix operate_matrices(Matrix &A, Matrix &B, char op);
Matrix add_matrices(Matrix &A, Matrix &B);
Matrix subtract_matrices(Matrix &A, Matrix &B);
Matrix multiply_matrices(Matrix &A, Matrix &B);
void print_matrix(Matrix &matrix, int width = 10);

#endif
