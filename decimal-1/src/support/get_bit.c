#include "../s21_decimal.h"

// Возвращает конкретный бит
int get_bit(s21_decimal *current, int bit_map) {
  return ((current->bits[map_array(bit_map)] & shift_one_bit(bit_map)) > 0
              ? YES
              : NO);
}

// Возвращает конкретный бит инта
int get_bit_int(int current, int bit_map) {
  return ((current & (ONE_UINT << bit_map)) > 0 ? YES : NO);
}

// смотрим знак
int get_sign(s21_decimal *current) {
  return ((current->bits[SCALE_OR_SIGN] & (ONE_UINT << ZERO_ARRAY_MAX)) > 0
              ? YES
              : NO);
}

// посмотреть степень
int get_exp(s21_decimal *current) {
  return ((current->bits[SCALE_OR_SIGN] & (MAX_EXP_SIZE << EXP_SHIFT)) >>
          EXP_SHIFT);
}

int hight_bit(s21_decimal *current) {
  int map = 95;
  for (; map > 0; map--) {
    if (get_bit(current, map)) {
      break;
    }
  }
  return map;
}

int get_decimal_zero(s21_decimal current) {
  int result = NO;
  if (!current.bits[ZERO_ARRAY] && !current.bits[ONE_ARRAY] &&
      !current.bits[TWO_ARRAY]) {
    result = YES;
  }
  return result;
}

// установить степень 10
s21_decimal get_power_of_ten(int exp) {
  s21_decimal result = {0};
  set_exp(0, &result);
  for (int i = 0; i < 96; ++i) {
    if (powers_ten_exp[exp][95 - i] == '1') {
      set_bit(&result, i);
    } else {
      unset_bit(&result, i);
    }
  }
  return result;
}

void copy(s21_decimal *current1, s21_decimal *current2) {
  for (int i = 0; i < 4; ++i) {
    current1->bits[i] = current2->bits[i];
  }
}