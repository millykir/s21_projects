#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  clear(result);
  int flag = OK_RET;
  int sign1 = get_sign(&value_1);
  int sign2 = get_sign(&value_2);
  same_scale(&value_1, &value_2);

  s21_decimal temp_value_1 = value_1;
  s21_decimal temp_value_2 = value_2;

  if (sign1 && !sign2) {
    temp_value_1 = reverse(value_1);
  } else if (!sign1 && sign2) {
    temp_value_2 = reverse(value_2);
  }

  int more_flag = add_major(temp_value_1, temp_value_2, result);

  if (sign1 && sign2) {
    set_sign(result);
    if (more_flag) {
      clear(result);
      flag = NEG_INF_RET;
    }
  } else if (!sign1 && !sign2) {
    if (more_flag) {
      clear(result);
      flag = INF_RET;
    }
  } else if ((sign1 && !sign2 &&
              (s21_is_less(no_sign(&value_2), no_sign(&value_1)))) ||
             (sign2 && !sign1 &&
              (s21_is_less(no_sign(&value_1), no_sign(&value_2))))) {
    *result = reverse(*result);
    set_sign(result);
  }

  return flag;
}