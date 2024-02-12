#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define CORRECT_MATRIX 0
#define INCORRECT_MATRIX 1
#define ERROR_CALC_MATRIX 2

#define DETER_FOR_STRING 0

#define MAX_EPS_TRUE 1e-06
#define MAX_EPS_EQ_TRUE 1e-07

typedef struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_remove_matrix(matrix_t *A);
int s21_error_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_not_eq_size_matrix(matrix_t *A, matrix_t *B);

int s21_arihmetic_check(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_algebraic_additions(matrix_t *A, matrix_t *result);
double s21_calc_determinant(matrix_t *A);
int s21_minor(int rows, int columns, matrix_t *A, matrix_t *result);

#endif  // S21_MATRIX_H