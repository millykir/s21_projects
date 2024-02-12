#include "../s21_decimal.h"

void clear_big(s21_big_decimal *current) {
  for (int i = 0; i < 6; i++) {
    current->bits[i] = 0;
  }
}

void set_bit_big(s21_big_decimal *current, int bit_map) {
  current->bits[map_array(bit_map)] |= shift_one_bit(bit_map);
}

int get_bit_big(s21_big_decimal current, int bit_map) {
  return ((current.bits[map_array(bit_map)] & shift_one_bit(bit_map)) > 0 ? YES
                                                                          : NO);
}

void dec_to_big(s21_big_decimal *current1, s21_decimal *current2) {
  for (int i = 0; i < 3; ++i) {
    current1->bits[i] = current2->bits[i];
  }
}

void big_to_dec(s21_decimal *current1, s21_big_decimal *current2) {
  for (int i = 0; i < 3; ++i) {
    current1->bits[i] = current2->bits[i];
  }
}

int big_to_dec_exp(s21_big_decimal *current, int exp) {
  s21_big_decimal five_big = {{5}};
  while ((current->bits[3] != 0 || current->bits[4] != 0 ||
          current->bits[5] != 0) ||
         exp > 28) {
    *current = sum_big_decimal(*current, five_big);
    *current = division_big_on_ten(*current);
    exp--;
  }
  return exp;
}

void copy_big(s21_big_decimal *current1, s21_big_decimal *current2) {
  for (int i = 0; i < 6; ++i) {
    current1->bits[i] = current2->bits[i];
  }
}

void shift_right_big(s21_big_decimal *current) {
  current->bits[0] >>= 1;
  if (get_bit_big(*current, 32)) set_bit_big(current, 31);
  current->bits[1] >>= 1;
  if (get_bit_big(*current, 64)) set_bit_big(current, 63);
  current->bits[2] >>= 1;
  if (get_bit_big(*current, 96)) set_bit_big(current, 95);
  current->bits[3] >>= 1;
  if (get_bit_big(*current, 128)) set_bit_big(current, 127);
  current->bits[4] >>= 1;
  if (get_bit_big(*current, 160)) set_bit_big(current, 159);
}

void shift_left_big(s21_big_decimal *current) {
  current->bits[5] <<= 1;
  if (get_bit_big(*current, 159)) set_bit_big(current, 160);
  current->bits[4] <<= 1;
  if (get_bit_big(*current, 127)) set_bit_big(current, 128);
  current->bits[3] <<= 1;
  if (get_bit_big(*current, 95)) set_bit_big(current, 96);
  current->bits[2] <<= 1;
  if (get_bit_big(*current, 63)) set_bit_big(current, 64);
  current->bits[1] <<= 1;
  if (get_bit_big(*current, 31)) set_bit_big(current, 32);
  current->bits[0] <<= 1;
}

void big_reverse(s21_big_decimal *current) {
  s21_big_decimal first = {{1}};
  for (int i = 0; i < 6; ++i) {
    current->bits[i] = ~current->bits[i];
  }
  *current = sum_big_decimal(*current, first);
}

int scale_norm_big(s21_big_decimal *current1, s21_big_decimal *current2,
                   int exp1, int exp2) {
  while (exp1 < exp2) {
    mul_ten_big(current1);
    exp1++;
  }
  while ((exp2) < exp1) {
    mul_ten_big(current2);
    exp2++;
  }
  return exp1;
}

int convert_to_dec_fin(s21_big_decimal current, s21_decimal *result,
                       int scale_result, int sign1, int sign2) {
  int res = OK_DEC;
  if ((current.bits[3] == 0 && current.bits[4] == 0 && current.bits[5] == 0) &&
      (scale_result >= 0 && scale_result <= 28)) {
    big_to_dec(result, &current);
    new_set_exp(result, scale_result);
    if (sign1 ^ sign2) set_bit(result, 127);
  } else {
    if (sign1 ^ sign2) {
      res = S21_NEG_INF_DEC;
    } else {
      res = S21_INF_DEC;
    }
    clear(result);
  }
  return res;
}
