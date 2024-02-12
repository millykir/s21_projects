#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (s21_error_matrix(A) != CORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return ERROR_CALC_MATRIX;
  }

  int flag = s21_create_matrix(A->rows, A->columns, result);

  if (flag == CORRECT_MATRIX) {
    flag = s21_algebraic_additions(A, result);
  }
  return flag;
}

int s21_algebraic_additions(matrix_t *A, matrix_t *result) {
  if (A->rows == 1) {
    result->matrix[0][0] = A->matrix[0][0];
    result->rows = A->rows;
    result->columns = A->columns;
    return CORRECT_MATRIX;
  }

  int flag = 0;
  double minor_deter = 0.0;
  result->matrix[0][0] = 1;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      minor_deter = 0.0;
      matrix_t minor = {0};
      if (s21_minor(i, j, A, &minor) == CORRECT_MATRIX &&
          s21_determinant(&minor, &minor_deter) == CORRECT_MATRIX) {
        result->matrix[i][j] =
            (((i + j) % 2 == 1) ? -1 : 1) * minor_deter;  // if znak
        s21_remove_matrix(&minor);
      } else {
        flag = INCORRECT_MATRIX;
      }
    }
  }

  return flag;
}

int s21_minor(int rows, int columns, matrix_t *A, matrix_t *result) {
  if (s21_error_matrix(A) != CORRECT_MATRIX ||
      s21_create_matrix(A->rows - 1, A->columns - 1, result) !=
          CORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }
  int flag = CORRECT_MATRIX;

  int i_new = 0;
  int j_new = 0;

  for (int i = 0; i < A->rows; i++, j_new = 0) {
    if (i != rows) {
      for (int j = 0; j < A->columns; j++) {
        if (j != columns) {
          result->matrix[i_new][j_new] = A->matrix[i][j];
          j_new++;
        }
      }
      i_new++;
    }
  }

  return flag;
}