#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int flag = NO;
  same_scale(&value_1, &value_2);

  if ((get_sign(&value_1) == get_sign(&value_2) &&
       (value_1.bits[TWO_ARRAY]) == (value_2.bits[TWO_ARRAY]) &&
       (value_1.bits[ONE_ARRAY]) == (value_2.bits[ONE_ARRAY]) &&
       (value_1.bits[ZERO_ARRAY]) == (value_2.bits[ZERO_ARRAY])) ||
      (get_decimal_zero(value_1) && get_decimal_zero(value_2))) {
    flag = YES;
  }

  return flag;
}