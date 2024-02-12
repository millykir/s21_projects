#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 1 || columns < 1) {
    return INCORRECT_MATRIX;
  }

  int flag = CORRECT_MATRIX;

  result->matrix = calloc(rows, sizeof(double *));
  if (result->matrix == NULL) {
    flag = ERROR_CALC_MATRIX;
  }

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      flag = ERROR_CALC_MATRIX;
    }
  }

  result->rows = rows;
  result->columns = columns;

  return flag;
}