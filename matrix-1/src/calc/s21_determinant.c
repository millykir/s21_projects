#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (s21_error_matrix(A) == INCORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return ERROR_CALC_MATRIX;
  }

  *result = s21_calc_determinant(A);

  return CORRECT_MATRIX;
}

double s21_calc_determinant(matrix_t *A) {
  if (!A->rows || !A->columns || !A->matrix) {
    return 0.0;
  }

  if (A->rows == 1) {
    return A->matrix[0][0];
  }

  double result = 0.0;

  if (A->rows == 2) {
    result = (A->matrix[0][0] * A->matrix[1][1]) -
             (A->matrix[0][1] * A->matrix[1][0]);
  } else {
    int sign = 1;
    for (int i = 0; i < A->rows; i++) {
      matrix_t minor_matrix = {0};
      int flag = s21_minor(DETER_FOR_STRING, i, A, &minor_matrix);
      if (flag == CORRECT_MATRIX) {
        result += sign * A->matrix[0][i] * s21_calc_determinant(&minor_matrix);
        sign *= -1;
        s21_remove_matrix(&minor_matrix);
      }
    }
  }

  return result;
}
