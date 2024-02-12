#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = 0;
  if (isnan(src) || isinf(src) || !dst) {
    return 1;
  }

  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
  int sign = 0;

  if (src < 0) {
    sign = 1;
    src = -(src);
  }

  int tmp = (int)src;
  int exp = 0;
  while (src - ((float)tmp / (int)(pow(10, exp))) != 0) {
    exp++;
    tmp = src * (int)(pow(10, exp));
  }
  s21_from_int_to_decimal(tmp, dst);

  if (sign) {
    s21_negate(*dst, dst);
  }
  dst->bits[3] += exp << 16;

  return result;
}