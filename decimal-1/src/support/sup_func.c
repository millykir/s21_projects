#include "../s21_decimal.h"

void clear(s21_decimal *current) {
  for (int i = 0; i < 4; i++) {
    current->bits[i] = 0;
  }
}

s21_decimal no_sign(s21_decimal *current) {
  unset_bit(current, 127);
  return *current;
}

s21_decimal equate(s21_decimal current) { return current; }

s21_decimal reverse(s21_decimal current) {
  s21_decimal res = {0}, result = {0}, one = {0};
  set_bit(&one, 0);
  for (int i = 0; i <= 95; i++) {
    if (get_bit(&current, i) == 0) set_bit(&result, i);
  }
  add_major(result, one, &res);
  new_set_exp(&res, get_exp(&current));
  //
  return res;
}
