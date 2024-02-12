#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  clear(result);
  int flag = OK_RET;
  int sign1 = get_sign(&value_1);
  int sign2 = get_sign(&value_2);

  if (get_decimal_zero(value_1) || get_decimal_zero(value_2)) {
    return OK_RET;
  }

  s21_big_decimal mul1 = {0}, mul2 = {0}, result_big = {0};
  int exp = get_exp(&value_1) + get_exp(&value_2);

  dec_to_big(&mul1, &value_1);
  dec_to_big(&mul2, &value_2);

  while (mul2.bits[0] != 0 || mul2.bits[1] != 0 || mul2.bits[2] != 0) {
    if (mul2.bits[0] & 1) {
      result_big = sum_big_decimal(mul1, result_big);
    }

    shift_right_big(&mul2);
    shift_left_big(&mul1);
  }

  exp = big_to_dec_exp(&result_big, exp);
  flag = convert_to_dec_fin(result_big, result, exp, sign1, sign2);

  return flag;
}