#include "../s21_decimal.h"

s21_big_decimal sum_big_decimal(s21_big_decimal current1,
                                s21_big_decimal current2) {
  int carry = 0;
  s21_big_decimal result = {0};
  for (int i = 0; i < FIVE_ARRAY_MAX; i++) {
    int res = get_bit_big(current1, i) + get_bit_big(current2, i) + carry;
    if (res == 0) {
      carry = 0;
    } else if (res == 1) {
      carry = 0;
      set_bit_big(&result, i);
    } else if (res == 2) {
      carry = 1;
    } else if (res == 3) {
      carry = 1;
      set_bit_big(&result, i);
    }
  }
  return result;
}

s21_big_decimal division_big_on_ten(s21_big_decimal current) {
  s21_big_decimal big_ten = {{10}}, result = {0}, msk = {{1}}, cur = {0};
  int check = 0;
  while (greater_or_equal_big(current, big_ten)) {
    copy_big(&cur, &big_ten);
    shift_left_big(&cur);
    if (get_bit_big(cur, 191)) check = 1;
    if (greater_or_equal_big(current, cur) && check == 0) {
      shift_left_big(&big_ten);
      shift_left_big(&msk);
    } else {
      result = sum_big_decimal(result, msk);
      current = sub_big(current, big_ten);
      clear_big(&big_ten);
      big_ten.bits[0] = 10;
      clear_big(&msk);
      msk.bits[0] = 1;
      check = 0;
    }
  }
  return result;
}

void mul_ten_big(s21_big_decimal *current) {
  s21_big_decimal res;
  copy_big(&res, current);

  for (int i = 0; i < 3; i++) shift_left_big(&res);
  shift_left_big(current);
  *current = sum_big_decimal(res, *current);
}

s21_big_decimal sub_big(s21_big_decimal current1, s21_big_decimal current2) {
  s21_big_decimal res = {0};
  big_reverse(&current2);
  res = sum_big_decimal(current1, current2);
  return res;
}

void div_big_on_int(s21_big_decimal *res_big, s21_big_decimal *current1,
                    s21_big_decimal *current2, s21_big_decimal tmp,
                    s21_big_decimal tmp_current2) {
  int check = 0;
  s21_big_decimal msk = {{1}};

  while (greater_or_equal_big(*current1, *current2)) {
    copy_big(&tmp_current2, &tmp);
    shift_left_big(&tmp_current2);
    if (get_bit_big(tmp_current2, 191)) check = 1;
    if (greater_or_equal_big(*current1, tmp_current2) && check == 0) {
      shift_left_big(&tmp);
      shift_left_big(&msk);
    } else {
      *res_big = sum_big_decimal(*res_big, msk);
      *current1 = sub_big(*current1, tmp);
      clear_big(&tmp);
      copy_big(&tmp, current2);
      clear_big(&msk);
      msk.bits[0] = 1;
      check = 0;
    }
  }
}