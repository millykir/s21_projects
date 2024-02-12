#include "../s21_decimal.h"

unsigned int map_array(int bit_map) { return (bit_map / SIZE_INT); }

unsigned int shift_one_bit(int bit_map) {
  return ONE_UINT << (bit_map % SIZE_INT);
}

// Усттанавливает конкретный бит
void set_bit(s21_decimal *current, int bit_map) {
  current->bits[map_array(bit_map)] |= shift_one_bit(bit_map);
}

// Удаляет конкретный бита
void unset_bit(s21_decimal *current, int bit_map) {
  current->bits[map_array(bit_map)] &= ~(shift_one_bit(bit_map));
}

// установка знака
void set_sign(s21_decimal *current) {
  current->bits[SCALE_OR_SIGN] |= (ONE_UINT << ZERO_ARRAY_MAX);
}

// устновка степени
int set_exp(int exp, s21_decimal *current) {
  int result = OK_RET;

  if (exp > EXP_MAX && exp < EXP_MIN) {
    result = INF_RET;
  } else {
    current->bits[SCALE_OR_SIGN] |= (exp << EXP_SHIFT);
  }

  return result;
}

void new_set_exp(s21_decimal *current, int exp) {
  current->bits[SCALE_OR_SIGN] &= ~(MAX_EXP_SIZE << EXP_SHIFT);
  current->bits[SCALE_OR_SIGN] |= (exp << EXP_SHIFT);
}

void shift_left(s21_decimal *current) {
  current->bits[TWO_ARRAY] <<= 1;

  if (get_bit(current, ONE_ARRAY_MAX)) {
    set_bit(current, 64);
  }

  current->bits[ONE_ARRAY] <<= 1;

  if (get_bit(current, ZERO_ARRAY_MAX)) {
    set_bit(current, 32);
  }

  current->bits[ZERO_ARRAY] <<= 1;
}
