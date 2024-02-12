#include "../s21_decimal.h"

int greater_or_equal_big(s21_big_decimal current1, s21_big_decimal current2) {
  int res = 0;
  if (equal_big(current1, current2)) {
    res = 1;
  } else {
    for (int i = 192; i >= 0; --i) {
      int bit1 = get_bit_big(current1, i), bit2 = get_bit_big(current2, i);
      if (bit1 == bit2) continue;
      res = get_bit_big(current1, i) > get_bit_big(current2, i) ? 1 : 0;
      break;
    }
  }
  return res;
}

int equal_big(s21_big_decimal current1, s21_big_decimal current2) {
  int res = YES;
  for (int i = 0; i < 6; i++) {
    if (current1.bits[i] != current2.bits[i]) res = 0;
  }
  return res;
}

int not_equal_big(s21_big_decimal current1, s21_big_decimal current2) {
  return !equal_big(current1, current2) ? 1 : 0;
}

int less_big(s21_big_decimal current1, s21_big_decimal current2) {
  return !greater_or_equal_big(current1, current2) ? 1 : 0;
}
