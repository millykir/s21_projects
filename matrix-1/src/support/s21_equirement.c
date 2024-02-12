#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_not_eq_size_matrix(A, B)) {
    return FAILURE;
  }

  int flag = SUCCESS;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >
          MAX_EPS_EQ_TRUE)  // максимально допустимая погрешность по заданию
        flag = FAILURE;
    }
  }

  return flag;
}