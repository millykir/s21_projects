#include "../s21_matrix.h"

int s21_remove_matrix(matrix_t *A) {
  if (s21_error_matrix(A)) {
    return INCORRECT_MATRIX;
  }

  int flag = CORRECT_MATRIX;

  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);

  A->rows = 0;
  A->columns = 0;

  A->matrix = NULL;

  return flag;
}
