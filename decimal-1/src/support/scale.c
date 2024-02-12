#include "../s21_decimal.h"

void same_scale(s21_decimal *current1, s21_decimal *current2) {
  int scale_dec1 = get_exp(current1), scale_dec2 = get_exp(current2);
  s21_decimal five = {{5, 0, 0, 0}};
  if (scale_dec1 < scale_dec2) {
    while (scale_dec1 < scale_dec2) {
      if ((hight_bit(current1) > 91) || scale_dec1 > 28) {
        if (scale_dec2 - scale_dec1 == 1) {
          add_major(*current2, five, current2);
          new_set_exp(current2, scale_dec2);
        }
        lower_scale(current2);
        scale_dec2 = get_exp(current2);
      } else {
        upper_scale(current1);
        scale_dec1 = get_exp(current1);
      }
    }
  } else if (scale_dec2 < scale_dec1) {
    while (scale_dec2 < scale_dec1) {
      if ((hight_bit(current2) > 91) || scale_dec2 > 28) {
        if (scale_dec1 - scale_dec2 == 1) {
          add_major(*current1, five, current1);
          new_set_exp(current1, scale_dec1);
        }
        lower_scale(current1);
        scale_dec1 = get_exp(current1);
      } else {
        upper_scale(current2);
        scale_dec2 = get_exp(current2);
      }
    }
  }
}

void lower_scale(s21_decimal *current) {
  int scale = get_exp(current) - 1;
  unsigned int sign = get_sign(current);
  s21_decimal ten = {{10, 0, 0, 0}};
  *current = div_no_scale(*current, ten);
  new_set_exp(current, scale);
  if (sign) {
    set_bit(current, 127);
  }
}

void upper_scale(s21_decimal *current) {
  unsigned int scale = get_exp(current);
  unsigned int sign = get_sign(current);

  mul_ten(current, 1);
  new_set_exp(current, (scale + 1));

  if (sign) {
    set_sign(current);
  }
}