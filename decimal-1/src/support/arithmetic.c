#include "../s21_decimal.h"

s21_decimal div_no_scale(s21_decimal dividend, s21_decimal divisor) {
  s21_decimal quotient = {0}, dec_null = {0};
  dividend.bits[3] = 0;
  if (s21_is_equal(dividend, divisor)) {
    quotient.bits[0] = 1;  // деление друг на друга = 1
  } else if (s21_is_equal(dividend, dec_null)) {
    clear(&quotient);
  } else {
    s21_decimal mask = {{1, 0, 0, 0}};
    s21_decimal temp = divisor;
    int flag = 0;
    while (s21_is_greater_or_equal(no_sign(&dividend), no_sign(&divisor))) {
      s21_decimal t_divisor = divisor;
      shift_left(&t_divisor);
      if (get_bit(&t_divisor, 95)) flag = 1;
      if (s21_is_greater_or_equal(dividend, t_divisor) &&
          s21_is_greater(t_divisor, dec_null) && flag == 0) {
        shift_left(&divisor);
        shift_left(&mask);
      } else {
        add_major(quotient, mask, &quotient);
        s21_sub(dividend, divisor, &dividend);
        divisor = temp;
        clear(&mask);
        mask.bits[0] = 1;
        flag = 0;
      }
    }
  }
  return quotient;
}

s21_decimal division_by_ten_integer(s21_decimal current) {
  s21_decimal copy_dividend = equate(current), power_of_ten = {0}, zero = {0},
              result = {0};
  int sign = get_sign(&copy_dividend), scale = get_exp(&copy_dividend);
  set_exp(0, &copy_dividend);
  unset_bit(&copy_dividend, 127);
  while (s21_is_less(zero, copy_dividend)) {  // 9 - chislo
    int degree = 0, equal_flag = 0;
    while (degree <= 28) {
      power_of_ten = get_power_of_ten(degree);  // 10 - del
      if (s21_is_less(copy_dividend, power_of_ten)) {
        break;
      }
      if (s21_is_equal(copy_dividend, power_of_ten)) {
        equal_flag = 1;
        break;
      }
      degree++;
    }
    if (equal_flag == 1 || s21_is_less(power_of_ten, copy_dividend)) {
      if (degree > 28) {
        degree = 28;
      }
      s21_sub(copy_dividend, power_of_ten, &copy_dividend);
    } else {
      degree--;  // stay 100 -> 10
      s21_sub(copy_dividend, get_power_of_ten(degree), &copy_dividend);
    }
    if (degree > 0) {
      s21_add(result, get_power_of_ten(degree - 1), &result);
    }
  }
  if (scale) {  // понижение степени
    scale--;
    set_exp(scale, &result);
  }
  if (sign) {
    set_sign(&result);
  }
  return result;
}

// перекинуть в арифметику как хелп арифметика
int add_major(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int carry = 0;
  clear(result);
  for (int i = 0; i <= TWO_ARRAY_MAX; i++) {
    int bit = get_bit(&value_1, i) + get_bit(&value_2, i) + carry;
    carry = bit / 2;
    if ((bit % 2) == 1) {
      set_bit(result, i);
    }
  }
  new_set_exp(result, get_exp(&value_1));
  return carry;
}

// Умножаем на 10
void mul_ten(s21_decimal *current, int exp) {
  s21_decimal add_in = {0}, add_out = {0}, result = {0};
  s21_decimal *mull_sum = &result;

  clear(mull_sum);

  add_in = *current;
  add_out = *current;

  for (int i = 0; i < exp; i++) {
    for (int j = 1; j < 10; j++) {
      add_major(add_in, add_out, mull_sum);
      add_in = *mull_sum;
    }
    add_out = *mull_sum;
  }
  *current = *mull_sum;
}