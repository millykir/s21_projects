#include "../s21_matrix.h"

int s21_arihmetic_check(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_not_eq_size_matrix(A, B)) {
    return ERROR_CALC_MATRIX;
  }

  if (s21_error_matrix(A) || s21_error_matrix(B) ||
      s21_create_matrix(A->rows, A->columns, result) == INCORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  return CORRECT_MATRIX;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = s21_arihmetic_check(A, B, result);
  if (flag == CORRECT_MATRIX) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = s21_arihmetic_check(A, B, result);
  if (flag == CORRECT_MATRIX) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return flag;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_error_matrix(A) != CORRECT_MATRIX ||
      s21_create_matrix(A->rows, A->columns, result) != CORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }

  return CORRECT_MATRIX;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_error_matrix(A) == INCORRECT_MATRIX ||
      s21_error_matrix(B) == INCORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  if (A->columns != B->rows) {
    return ERROR_CALC_MATRIX;
  }

  int flag = s21_create_matrix(A->rows, B->columns, result);

  if (flag == CORRECT_MATRIX) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns && k < B->rows; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return flag;
}