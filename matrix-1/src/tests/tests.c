#include <check.h>
#include <time.h>

#include "../s21_matrix.h"

//
// create/remove
//
START_TEST(create_incorrect_1) {
  matrix_t test = {0};
  ck_assert_int_eq(s21_create_matrix(-3, -4, &test), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_incorrect_2) {
  matrix_t test = {0};
  ck_assert_int_eq(s21_create_matrix(0, 0, &test), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_remove_1) {
  matrix_t test = {0};
  ck_assert_int_eq(s21_create_matrix(5, 2, &test), CORRECT_MATRIX);
  if (test.matrix) {
    s21_remove_matrix(&test);
    ck_assert(!test.matrix);
  }
}
END_TEST

START_TEST(create_remove_2) {
  matrix_t test = {0};
  ck_assert_int_eq(s21_create_matrix(1, 1, &test), CORRECT_MATRIX);
  if (test.matrix) {
    s21_remove_matrix(&test);
    ck_assert(!test.matrix);
  }
}
END_TEST

START_TEST(create_remove_3) {
  matrix_t test = {0};
  ck_assert_int_eq(s21_create_matrix(5, 1, &test), CORRECT_MATRIX);
  if (test.matrix) {
    s21_remove_matrix(&test);
    ck_assert(!test.matrix);
  }
}
END_TEST

START_TEST(create_remove_4) {
  matrix_t test = {0};
  ck_assert_int_eq(s21_create_matrix(11, 11, &test), CORRECT_MATRIX);
  if (test.matrix) {
    s21_remove_matrix(&test);
    ck_assert(!test.matrix);
  }
}
END_TEST

//
// equal
//
START_TEST(equal_1) {
  matrix_t test_1 = {0}, test_2 = {0};

  s21_create_matrix(2, 6, &test_1);
  s21_create_matrix(3, 4, &test_2);

  ck_assert_int_eq(s21_eq_matrix(&test_1, &test_2), FAILURE);

  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
}
END_TEST

START_TEST(equal_2) {
  matrix_t test_1 = {0}, test_2 = {0};

  ck_assert_int_eq(s21_create_matrix(3, 2, &test_1), CORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(3, 2, &test_2), CORRECT_MATRIX);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) test_1.matrix[i][j] = 2;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) test_2.matrix[i][j] = 2.0000001;
  ck_assert_int_eq(s21_eq_matrix(&test_1, &test_2), SUCCESS);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
}
END_TEST

START_TEST(equal_3) {
  matrix_t test_1 = {0}, test_2 = {0};

  s21_create_matrix(2, 4, &test_1);
  s21_create_matrix(2, 4, &test_2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 4; j++) {
      test_1.matrix[i][j] = (rand() - rand()) / 987654.3210987;
      test_2.matrix[i][j] = (rand() - rand()) / 987654.3210987;
    }

  ck_assert_int_eq(s21_eq_matrix(&test_1, &test_2), FAILURE);

  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
}
END_TEST

//
// sum
//
START_TEST(sum_1) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int M = 1 + rand() % 9, N = 1 + rand() % 9;

  s21_create_matrix(M, N, &test_1);
  s21_create_matrix(M, N, &test_2);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) {
      test_1.matrix[i][j] = (rand() - rand()) / 987654.3210987;
      test_2.matrix[i][j] = (rand() - rand()) / 987654.3210987;
    }

  ck_assert_int_eq(s21_sum_matrix(&test_1, &test_2, &result), CORRECT_MATRIX);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      ck_assert_double_eq_tol((test_1.matrix[i][j] + test_2.matrix[i][j]),
                              result.matrix[i][j], MAX_EPS_TRUE);

  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_2) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};

  s21_create_matrix(3, 5, &test_1);
  s21_create_matrix(2, 4, &test_2);

  ck_assert_int_eq(s21_sum_matrix(&test_1, &test_2, &result),
                   ERROR_CALC_MATRIX);

  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
}
END_TEST

START_TEST(sum_3) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};

  s21_create_matrix(3, 5, &test_1);

  ck_assert_int_eq(s21_sum_matrix(&test_1, &test_2, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&test_1);
}
END_TEST

//
// sub
//
START_TEST(sub_1) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int M = 1 + rand() % 9, N = 1 + rand() % 9;

  s21_create_matrix(M, N, &test_1);
  s21_create_matrix(M, N, &test_2);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) {
      test_1.matrix[i][j] = (rand() - rand()) / 987654.3210987;
      test_2.matrix[i][j] = (rand() - rand()) / 987654.3210987;
    }

  ck_assert_int_eq(s21_sub_matrix(&test_1, &test_2, &result), CORRECT_MATRIX);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      ck_assert_double_eq_tol((test_1.matrix[i][j] - test_2.matrix[i][j]),
                              result.matrix[i][j], MAX_EPS_TRUE);

  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_2) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};

  s21_create_matrix(3, 5, &test_1);
  s21_create_matrix(2, 5, &test_2);

  ck_assert_int_eq(s21_sub_matrix(&test_1, &test_2, &result),
                   ERROR_CALC_MATRIX);

  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
}
END_TEST

START_TEST(sub_3) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};

  s21_create_matrix(3, 5, &test_1);

  ck_assert_int_eq(s21_sub_matrix(&test_1, &test_2, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&test_1);
}
END_TEST

//
// mult number
//
START_TEST(mult_number_1) {
  matrix_t test = {0}, result = {0};
  double num = 123.4567 * (rand() % 100);
  int M = 1 + rand() % 9, N = 1 + rand() % 9;

  s21_create_matrix(M, N, &test);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      test.matrix[i][j] = (rand() - rand()) / 987654.3210987;

  ck_assert_int_eq(s21_mult_number(&test, num, &result), CORRECT_MATRIX);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      ck_assert_double_eq_tol((test.matrix[i][j] * num), result.matrix[i][j],
                              MAX_EPS_TRUE);

  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t test = {0}, result = {0};
  double num = -9876.54321;

  ck_assert_int_eq(s21_mult_number(&test, num, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t test = {0}, result = {0};
  double num = 0;
  int M = 1 + rand() % 9, N = 1 + rand() % 9;

  s21_create_matrix(M, N, &test);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      test.matrix[i][j] = (rand() - rand()) / 9876543.2109876;

  ck_assert_int_eq(s21_mult_number(&test, num, &result), CORRECT_MATRIX);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      ck_assert_double_eq_tol((test.matrix[i][j] * num), result.matrix[i][j],
                              MAX_EPS_TRUE);

  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

//
// mult matrix
//
START_TEST(mult_matrix_1) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int M = 1 + rand() % 9, N = 1 + rand() % 9, K = 1 + rand() % 9;

  s21_create_matrix(M, K, &test_1);
  s21_create_matrix(K, N, &test_2);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < K; j++)
      test_1.matrix[i][j] = (rand() - rand()) / 987654.3210987;
  for (int i = 0; i < K; i++)
    for (int j = 0; j < N; j++)
      test_2.matrix[i][j] = (rand() - rand()) / 987654.3210987;

  M = rand() % M;
  N = rand() % N;

  ck_assert_int_eq(s21_mult_matrix(&test_1, &test_2, &result), CORRECT_MATRIX);

  double mult = 0;
  for (int k = 0; k < K; k++) mult += test_1.matrix[M][k] * test_2.matrix[k][N];

  ck_assert_double_eq_tol(mult, result.matrix[M][N], MAX_EPS_TRUE);

  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};

  s21_create_matrix(2, 8, &test_1);
  s21_create_matrix(6, 7, &test_2);

  ck_assert_int_eq(s21_mult_matrix(&test_1, &test_2, &result),
                   ERROR_CALC_MATRIX);

  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};

  ck_assert_int_eq(s21_mult_matrix(&test_1, &test_2, &result),
                   INCORRECT_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

//
// transpose
//
START_TEST(transpose_1) {
  matrix_t test = {0}, result = {0};
  int M = 1 + rand() % 9, N = 1 + rand() % 9;

  s21_create_matrix(M, N, &test);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      test.matrix[i][j] = (rand() - rand()) / 987654.3210987;

  ck_assert_int_eq(s21_transpose(&test, &result), CORRECT_MATRIX);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      ck_assert_double_eq(test.matrix[i][j], result.matrix[j][i]);

  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t test = {0}, result = {0};

  ck_assert_int_eq(s21_transpose(&test, &result), INCORRECT_MATRIX);
}
END_TEST

//
// complements calculation

START_TEST(complements_1) {
  matrix_t test = {0}, result = {0};
  int M = 3, N = 3;

  s21_create_matrix(M, N, &test);
  test.matrix[0][0] = 1;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = 3;

  test.matrix[1][0] = 0;
  test.matrix[1][1] = 4;
  test.matrix[1][2] = 2;

  test.matrix[2][0] = 5;
  test.matrix[2][1] = 2;
  test.matrix[2][2] = 1;

  ck_assert_int_eq(s21_calc_complements(&test, &result), CORRECT_MATRIX);

  test.matrix[0][0] = 0;
  test.matrix[0][1] = 10;
  test.matrix[0][2] = -20;

  test.matrix[1][0] = 4;
  test.matrix[1][1] = -14;
  test.matrix[1][2] = 8;

  test.matrix[2][0] = -8;
  test.matrix[2][1] = -2;
  test.matrix[2][2] = 4;

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      ck_assert_double_eq(test.matrix[i][j], result.matrix[i][j]);

  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_2) {
  matrix_t test = {0}, result = {0};

  s21_create_matrix(3, 7, &test);

  ck_assert_int_eq(s21_calc_complements(&test, &result), ERROR_CALC_MATRIX);

  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_3) {
  matrix_t test = {0}, result = {0};

  ck_assert_int_eq(s21_calc_complements(&test, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_4) {
  matrix_t test = {0}, result = {0};
  int M = 1, N = 1;

  s21_create_matrix(M, N, &test);
  test.matrix[0][0] = 1;

  ck_assert_int_eq(s21_calc_complements(&test, &result), CORRECT_MATRIX);
  ck_assert_double_eq(test.matrix[0][0], result.matrix[0][0]);

  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

//
// determinant
//
START_TEST(determinant_1) {
  matrix_t test = {0};
  double result = 0;
  int M = 3, N = 3;

  s21_create_matrix(M, N, &test);
  test.matrix[0][0] = 1.2;
  test.matrix[0][1] = -3.4;
  test.matrix[0][2] = 5.6;

  test.matrix[1][0] = -7.8;
  test.matrix[1][1] = 9;
  test.matrix[1][2] = 3.14159265359;

  test.matrix[2][0] = 2.7182818285;
  test.matrix[2][1] = 0;
  test.matrix[2][2] = 0.00000001;

  double d_1 = test.matrix[0][0] * test.matrix[1][1] * test.matrix[2][2];
  double d_2 = test.matrix[0][1] * test.matrix[1][2] * test.matrix[2][0];
  double d_3 = test.matrix[0][2] * test.matrix[1][0] * test.matrix[2][1];
  double d_4 = test.matrix[0][2] * test.matrix[1][1] * test.matrix[2][0];
  double d_5 = test.matrix[0][1] * test.matrix[1][0] * test.matrix[2][2];
  double d_6 = test.matrix[0][0] * test.matrix[1][2] * test.matrix[2][1];
  double dtr = d_1 + d_2 + d_3 - d_4 - d_5 - d_6;

  ck_assert_int_eq(s21_determinant(&test, &result), CORRECT_MATRIX);
  ck_assert_double_eq_tol(result, dtr, MAX_EPS_TRUE);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t test = {0};
  double result = 0;

  s21_create_matrix(3, 7, &test);

  ck_assert_int_eq(s21_determinant(&test, &result), ERROR_CALC_MATRIX);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t test = {0};
  double result = 0;

  ck_assert_int_eq(s21_determinant(&test, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t test = {0};
  double result = 0;
  int M = 5, N = 5;

  s21_create_matrix(M, N, &test);
  test.matrix[0][0] = 5;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = -2;
  test.matrix[0][3] = 3;
  test.matrix[0][4] = 6;

  test.matrix[1][0] = 6.9;
  test.matrix[1][1] = 3;
  test.matrix[1][2] = 4;
  test.matrix[1][3] = 5;
  test.matrix[1][4] = 7;

  test.matrix[2][0] = -1;
  test.matrix[2][1] = 1;
  test.matrix[2][2] = 6;
  test.matrix[2][3] = -3;
  test.matrix[2][4] = 9;

  test.matrix[3][0] = 1;
  test.matrix[3][1] = 0;
  test.matrix[3][2] = -8;
  test.matrix[3][3] = 0;
  test.matrix[3][4] = 5;

  test.matrix[4][0] = 9;
  test.matrix[4][1] = 2;
  test.matrix[4][2] = 3;
  test.matrix[4][3] = 0;
  test.matrix[4][4] = 3;

  ck_assert_int_eq(s21_determinant(&test, &result), CORRECT_MATRIX);
  ck_assert_double_eq_tol(result, -1611.1, MAX_EPS_TRUE);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t test = {0};
  double result = 0;
  int M = 5, N = 5;

  s21_create_matrix(M, N, &test);
  test.matrix[0][0] = 5;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = -2;
  test.matrix[0][3] = 3;
  test.matrix[0][4] = 6;

  test.matrix[1][0] = 6.9;
  test.matrix[1][1] = 3;
  test.matrix[1][2] = 4;
  test.matrix[1][3] = 5;
  test.matrix[1][4] = 7;

  test.matrix[2][0] = -1;
  test.matrix[2][1] = 1;
  test.matrix[2][2] = 6;
  test.matrix[2][3] = -3;
  test.matrix[2][4] = 9;

  test.matrix[3][0] = 0;
  test.matrix[3][1] = 0;
  test.matrix[3][2] = 0;
  test.matrix[3][3] = 0;
  test.matrix[3][4] = 0;

  test.matrix[4][0] = 9;
  test.matrix[4][1] = 2;
  test.matrix[4][2] = 3;
  test.matrix[4][3] = 0;
  test.matrix[4][4] = 3;

  ck_assert_int_eq(s21_determinant(&test, &result), CORRECT_MATRIX);
  ck_assert_double_eq(result, 0.0);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_6) {
  matrix_t test = {0};
  double result = 0;
  int M = 1, N = 1;

  s21_create_matrix(M, N, &test);
  test.matrix[0][0] = 8.0 / 7.0;

  ck_assert_int_eq(s21_determinant(&test, &result), CORRECT_MATRIX);
  ck_assert_double_eq(result, test.matrix[0][0]);

  s21_remove_matrix(&test);
}
END_TEST

// inverse matrix

START_TEST(inverse_1) {
  matrix_t test = {0}, result = {0};
  int M = 3, N = 3;

  s21_create_matrix(M, N, &test);
  test.matrix[0][0] = 2;
  test.matrix[0][1] = 5;
  test.matrix[0][2] = 7;

  test.matrix[1][0] = 6;
  test.matrix[1][1] = 3;
  test.matrix[1][2] = 4;

  test.matrix[2][0] = 5;
  test.matrix[2][1] = -2;
  test.matrix[2][2] = -3;

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), CORRECT_MATRIX);

  test.matrix[0][0] = 1;
  test.matrix[0][1] = -1;
  test.matrix[0][2] = 1;

  test.matrix[1][0] = -38;
  test.matrix[1][1] = 41;
  test.matrix[1][2] = -34;

  test.matrix[2][0] = 27;
  test.matrix[2][1] = -29;
  test.matrix[2][2] = 24;

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      ck_assert_double_eq_tol(test.matrix[i][j], result.matrix[i][j],
                              MAX_EPS_TRUE);

  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t test = {0}, result = {0};

  s21_create_matrix(3, 7, &test);

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), ERROR_CALC_MATRIX);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t test = {0}, result = {0};

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_5) {
  matrix_t test = {0}, result = {0};
  int M = 5, N = 5;

  s21_create_matrix(M, N, &test);

  test.matrix[0][0] = 5.5;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = -2.7;
  test.matrix[0][3] = 3.09;
  test.matrix[0][4] = 6.01;

  test.matrix[1][0] = 6.9;
  test.matrix[1][1] = 3;
  test.matrix[1][2] = 4.0000004;
  test.matrix[1][3] = 5.7;
  test.matrix[1][4] = 7.5;

  test.matrix[2][0] = -1;
  test.matrix[2][1] = 1;
  test.matrix[2][2] = 6;
  test.matrix[2][3] = -3;
  test.matrix[2][4] = 9;

  test.matrix[3][0] = 0.1;
  test.matrix[3][1] = 0.3;
  test.matrix[3][2] = 0.5;
  test.matrix[3][3] = 0.7;
  test.matrix[3][4] = 0.8;

  test.matrix[4][0] = 9;
  test.matrix[4][1] = 2;
  test.matrix[4][2] = 3;
  test.matrix[4][3] = 0;
  test.matrix[4][4] = 3;

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), CORRECT_MATRIX);

  test.matrix[0][0] = -0.0460335;
  test.matrix[0][1] = 0.3123385;
  test.matrix[0][2] = 0.0022876;
  test.matrix[0][3] = -2.330319;
  test.matrix[0][4] = -0.0740702;

  test.matrix[1][0] = 0.4158582;
  test.matrix[1][1] = -2.0969712;
  test.matrix[1][2] = -0.1994096;
  test.matrix[1][3] = 14.3850073;
  test.matrix[1][4] = 1.1715523;

  test.matrix[2][0] = -0.1755723;
  test.matrix[2][1] = 0.1767694;
  test.matrix[2][2] = 0.0256331;
  test.matrix[2][3] = -0.554526;
  test.matrix[2][4] = -0.0192196;

  test.matrix[3][0] = -0.0878788;
  test.matrix[3][1] = 0.4030231;
  test.matrix[3][2] = -0.0479679;
  test.matrix[3][3] = -1.6708425;
  test.matrix[3][4] = -0.2420455;

  test.matrix[4][0] = 0.036434;
  test.matrix[4][1] = 0.2841958;
  test.matrix[4][2] = 0.1004439;
  test.matrix[4][3] = -2.044522;
  test.matrix[4][4] = -0.2062713;

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      ck_assert_double_eq_tol(test.matrix[i][j], result.matrix[i][j],
                              MAX_EPS_TRUE);

  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_6) {
  matrix_t test = {0}, result = {0};
  int M = 2, N = 2;

  s21_create_matrix(M, N, &test);

  test.matrix[0][0] = 4;
  test.matrix[0][1] = 2;
  test.matrix[1][0] = 0.6;
  test.matrix[1][1] = 0.3;

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), ERROR_CALC_MATRIX);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(inverse_7) {
  matrix_t test = {0}, result = {0};
  s21_create_matrix(4, 4, &test);

  test.matrix[0][0] = 1;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = 3;
  test.matrix[0][3] = 4;

  test.matrix[1][0] = 4;
  test.matrix[1][1] = 0;
  test.matrix[1][2] = 0;
  test.matrix[1][3] = 3;

  test.matrix[2][0] = 0;
  test.matrix[2][1] = 3;
  test.matrix[2][2] = 3;
  test.matrix[2][3] = 1;

  test.matrix[3][0] = 0;
  test.matrix[3][1] = 7;
  test.matrix[3][2] = 2;
  test.matrix[3][3] = 6;

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), CORRECT_MATRIX);

  test.matrix[0][0] = -45.0 / 199.0;
  test.matrix[0][1] = 61.0 / 199.0;
  test.matrix[0][2] = 51.0 / 199.0;
  test.matrix[0][3] = -9.0 / 199.0;

  test.matrix[1][0] = -64.0 / 199.0;
  test.matrix[1][1] = 16.0 / 199.0;
  test.matrix[1][2] = 46.0 / 199.0;
  test.matrix[1][3] = 27.0 / 199.0;

  test.matrix[2][0] = 44.0 / 199.0;
  test.matrix[2][1] = -11.0 / 199.0;
  test.matrix[2][2] = 43.0 / 199.0;
  test.matrix[2][3] = -31.0 / 199.0;

  test.matrix[3][0] = 60.0 / 199.0;
  test.matrix[3][1] = -15.0 / 199.0;
  test.matrix[3][2] = -68.0 / 199.0;
  test.matrix[3][3] = 12.0 / 199.0;

  ck_assert_uint_eq(s21_eq_matrix(&result, &test), SUCCESS);

  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_matrix_suite(void) {
  Suite *suite = suite_create("s21_matrix");

  TCase *tcase_create_remove = tcase_create("create/remove_matrix");
  tcase_add_test(tcase_create_remove, create_incorrect_1);
  tcase_add_test(tcase_create_remove, create_incorrect_2);
  tcase_add_test(tcase_create_remove, create_remove_1);
  tcase_add_test(tcase_create_remove, create_remove_2);
  tcase_add_test(tcase_create_remove, create_remove_3);
  tcase_add_test(tcase_create_remove, create_remove_4);
  suite_add_tcase(suite, tcase_create_remove);

  TCase *tcase_equal = tcase_create("eq_matrix");
  tcase_add_test(tcase_equal, equal_1);
  tcase_add_test(tcase_equal, equal_2);
  tcase_add_test(tcase_equal, equal_3);
  suite_add_tcase(suite, tcase_equal);

  TCase *tcase_sum = tcase_create("sum_matrix");
  tcase_add_test(tcase_sum, sum_1);
  tcase_add_test(tcase_sum, sum_2);
  tcase_add_test(tcase_sum, sum_3);
  suite_add_tcase(suite, tcase_sum);

  TCase *tcase_sub = tcase_create("sub_matrix");
  tcase_add_test(tcase_sub, sub_1);
  tcase_add_test(tcase_sub, sub_2);
  tcase_add_test(tcase_sub, sub_3);
  suite_add_tcase(suite, tcase_sub);

  TCase *tcase_mult_number = tcase_create("mult_number");
  tcase_add_test(tcase_mult_number, mult_number_1);
  tcase_add_test(tcase_mult_number, mult_number_2);
  tcase_add_test(tcase_mult_number, mult_number_3);
  suite_add_tcase(suite, tcase_mult_number);

  TCase *tcase_mult_matrix = tcase_create("mult_matrix");
  tcase_add_test(tcase_mult_matrix, mult_matrix_1);
  tcase_add_test(tcase_mult_matrix, mult_matrix_2);
  tcase_add_test(tcase_mult_matrix, mult_matrix_3);
  suite_add_tcase(suite, tcase_mult_matrix);

  TCase *tcase_transpose = tcase_create("transpose_matrix");
  tcase_add_test(tcase_transpose, transpose_1);
  tcase_add_test(tcase_transpose, transpose_2);
  suite_add_tcase(suite, tcase_transpose);

  TCase *tcase_complements = tcase_create("calc_complements");
  tcase_add_test(tcase_complements, complements_1);
  tcase_add_test(tcase_complements, complements_2);
  tcase_add_test(tcase_complements, complements_3);
  tcase_add_test(tcase_complements, complements_4);
  suite_add_tcase(suite, tcase_complements);

  TCase *tcase_determinant = tcase_create("determinant");
  tcase_add_test(tcase_determinant, determinant_1);
  tcase_add_test(tcase_determinant, determinant_2);
  tcase_add_test(tcase_determinant, determinant_3);
  tcase_add_test(tcase_determinant, determinant_4);
  tcase_add_test(tcase_determinant, determinant_5);
  tcase_add_test(tcase_determinant, determinant_6);
  suite_add_tcase(suite, tcase_determinant);

  TCase *tcase_inverse = tcase_create("inverse_matrix");
  tcase_add_test(tcase_inverse, inverse_1);
  tcase_add_test(tcase_inverse, inverse_2);
  tcase_add_test(tcase_inverse, inverse_3);
  tcase_add_test(tcase_inverse, inverse_5);
  tcase_add_test(tcase_inverse, inverse_6);
  tcase_add_test(tcase_inverse, inverse_7);
  suite_add_tcase(suite, tcase_inverse);

  return suite;
}

int main() {
  srand(time(NULL));
  Suite *suite = s21_matrix_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, 4);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? 0 : 1;
}
