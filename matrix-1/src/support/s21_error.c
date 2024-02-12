#include "../s21_matrix.h"

int s21_error_matrix(matrix_t *A) {
  return (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0);
}

int s21_not_eq_size_matrix(matrix_t *A, matrix_t *B) {
  if (s21_error_matrix(A) == 0 && s21_error_matrix(B) == 0) {
    return (A->rows == B->rows && A->columns == B->columns) ? 0 : 1;
  }
  return 0;
}
