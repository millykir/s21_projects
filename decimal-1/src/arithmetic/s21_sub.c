#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  clear(result);
  int flag_inf = 0, flag = OK_RET;
  int sign1 = get_sign(&value_1);
  int sign2 = get_sign(&value_2);
  same_scale(&value_1, &value_2);

  s21_decimal comparison_value1 = value_1;
  s21_decimal comparison_value2 = value_2;

  if (!sign1 && !sign2) {
    value_2 = reverse(value_2);
    add_major(value_1, value_2, result);
  }

  if (sign1 && sign2) {
    value_1 = reverse(value_1);
    add_major(value_1, value_2, result);
  }

  if ((!sign1 && !sign2 &&
       (s21_is_less((comparison_value1), no_sign(&comparison_value2)))) ||
      (sign2 && sign1 &&
       (s21_is_greater(no_sign(&comparison_value1),
                       no_sign(&comparison_value2))))) {
    *result = reverse(*result);
    set_sign(result);
  }

  if (!sign1 && sign2) {
    flag_inf = add_major(value_1, value_2, result);
  }

  if (sign1 && !sign2) {
    flag_inf = add_major(value_1, value_2, result);
    set_bit(result, 127);
  }

  if (flag_inf) {
    clear(result);
    flag = S21_INF_DEC;
  }

  return flag;
}