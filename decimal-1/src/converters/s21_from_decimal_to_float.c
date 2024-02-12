#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0.0;  // обнуляем
  double dst_double = *dst;
  int exp = get_exp(&src);

  for (int i = 0; i < 96; i++) {
    if (get_bit(&src, i)) {
      dst_double += pow(2.0, i);
    }
  }

  for (; exp > 0; exp--) {
    dst_double /= 10;
  }

  if (get_sign(&src)) {
    dst_double *= -1.0;
  }

  *dst = dst_double;
  return OK_RET;
}
