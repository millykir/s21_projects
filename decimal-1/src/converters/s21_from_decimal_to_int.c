#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (((src.bits[SCALE_OR_SIGN] & NO_USE_BIT_3_ARRAY) !=
       src.bits[SCALE_OR_SIGN])) {  // Биты с 0-15 и 24-30 свободны
    return FALSE;
  }

  if (dst == NULL) {
    return FALSE;
  }

  int flag = TRUE;
  int sign = 1;
  int dst1 = (int)*dst;
  long double a = (long double)*dst;

  if (get_sign(&src)) {
    sign = -1;
    src.bits[SCALE_OR_SIGN] &= ~(1 << 31);
  }

  long double div = powl(10.0, (long double)(src.bits[3] >> 16));

  if (!src.bits[ONE_ARRAY] && !src.bits[TWO_ARRAY]) {
    div = (div == 0 ? 1 : div);
    dst1 = (src.bits[ZERO_ARRAY] / div) * sign;
    a = (src.bits[ZERO_ARRAY] / div);
  } else {
    for (int i = 0; i < D_SIZE; i++) {
      a += (get_bit(&src, i) * powl(2.0, (long double)i));
    }

    a /= div;

    dst1 = (int)a * sign;
  }

  *dst = dst1;

  if (*dst == -SIGN_IN_INT && a > SIGN_IN_INT) {
    *dst = 0;
    flag = FALSE;
  }

  return flag;
}
