#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int flag = NO;
  same_scale(&value_1, &value_2);

  if (get_decimal_zero(value_1) && get_decimal_zero(value_2)) {
    return NO;
  }

  if (get_sign(&value_1) > get_sign(&value_2)) {
    return YES;
  }

  if (get_sign(&value_1) < get_sign(&value_2)) {
    return NO;
  }

  int bit = 95;

  for (; bit >= 0; bit--) {
    if ((get_bit(&value_1, bit)) > (get_bit(&value_2, bit))) {
      flag = NO;
      break;
    }
    if ((get_bit(&value_1, bit)) < (get_bit(&value_2, bit))) {
      flag = YES;
      break;
    }
  }

  if (get_sign(&value_1) && get_sign(&value_2) && !flag && bit != -1) {
    flag = YES;
  } else if (get_sign(&value_1) && get_sign(&value_2) && bit != -1) {
    flag = NO;
  }

  return flag;
}