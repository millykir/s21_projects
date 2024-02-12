#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  clear(result);
  int sign = get_sign(&value);

  if (!get_decimal_zero(value)) {
    s21_truncate(value, result);
    if (sign && get_exp(&value)) {
      s21_sub(*result, (s21_decimal){{1, 0, 0, 0}}, result);
    }
  }

  if (sign) {
    set_sign(result);
  }

  return OK_RET;
}