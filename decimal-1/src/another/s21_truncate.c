#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  clear(result);
  int exp = get_exp(&value);
  int sign = get_sign(&value);

  *result = value;
  result->bits[SCALE_OR_SIGN] = 0;

  for (; exp != 0; exp--) {
    *result = division_by_ten_integer(*result);
  }

  if (sign) {
    set_sign(result);
  }

  return OK_RET;
}