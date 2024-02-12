#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_error_matrix(A) == INCORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return ERROR_CALC_MATRIX;
  }

  double determinant = 0.0;
  int flag = s21_determinant(A, &determinant);
  if (fabs(determinant) < MAX_EPS_TRUE || flag != CORRECT_MATRIX) {
    return ERROR_CALC_MATRIX;
  }

  matrix_t minor = {0}, transpose = {0};
  s21_calc_complements(A, &minor);
  s21_transpose(&minor, &transpose);
  s21_create_matrix(A->rows, A->rows, result);

  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->rows; y += 1) {
      result->matrix[x][y] = transpose.matrix[x][y] / determinant;
    }
  }

  s21_remove_matrix(&transpose);
  s21_remove_matrix(&minor);

  return 0;
}