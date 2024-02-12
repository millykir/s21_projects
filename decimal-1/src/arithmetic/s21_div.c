#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  clear(result);
  int flag = OK_RET;
  int exp1 = get_exp(&value_1);
  int exp2 = get_exp(&value_2);
  int sign1 = get_sign(&value_1);
  int sign2 = get_sign(&value_2);
  s21_decimal zero = {0};

  if (s21_is_equal(value_2, zero)) {
    return NAN_RET;
  } else if (s21_is_equal(value_1, zero)) {
    return flag;
  }

  s21_big_decimal divisible = {0}, divider = {0}, temp_divider = {0};
  s21_big_decimal result_big = {0};
  s21_big_decimal zero_big = {0};

  dec_to_big(&divisible, &value_1);
  dec_to_big(&divider, &value_2);
  scale_norm_big(&divisible, &divider, exp1, exp2);

  int exp_all = 0;
  copy_big(&temp_divider, &divider);

  while (not_equal_big(divisible, zero_big) && exp_all < 28) {
    while ((less_big(divisible, divider)) && exp_all < 28) {
      mul_ten_big(&divisible);
      if (not_equal_big(result_big, zero_big)) {
        mul_ten_big(&result_big);
      }
      exp_all++;
    }
    div_big_on_int(&result_big, &divisible, &divider, temp_divider,
                   (s21_big_decimal){0});
  }

  exp_all = big_to_dec_exp(&result_big, exp_all);
  flag = convert_to_dec_fin(result_big, result, exp_all, sign1, sign2);

  return flag;
}