#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  clear(dst);
  if (src < 0) {
    src *= -1;
    set_sign(dst);
  }
  dst->bits[ZERO_ARRAY] = src;
  return OK_RET;
}
