#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  clear(result);
  get_sign(&value) == 1 ? unset_bit(&value, 127) : set_sign(&value);
  *result = value;
  return OK_RET;
}
