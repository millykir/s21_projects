#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  clear(result);
  int exp = get_exp(&value);
  int sign = get_sign(&value);
  value.bits[SCALE_OR_SIGN] = 0;

  if (exp) {
    for (; exp != 1; exp--) {
      value = division_by_ten_integer(value);
    }
    s21_add(value, (s21_decimal){{5, 0, 0, 0}}, result);
    *result = division_by_ten_integer(*result);
    s21_truncate(*result, result);
  } else {
    *result = value;
  }

  if (sign) {
    set_sign(result);
  }

  return OK_RET;
}