#include "string_test.h"

START_TEST(strerror_1) {
  for (int i = -5; i < 140;
       i++)  //{printf("%s   %s\n", strerror(i), s21_strerror(i));
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  //}
}
END_TEST

START_TEST(strerror_2) {
  int i = -1260541703;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_3) {
  int i = 80;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_4) {
  int i = 777;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_5) {
  int i = 797606797;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
  if (!std) free(strerror(i));
}
END_TEST

Suite *suite_strerror() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRERROR");
  tc = tcase_create("case_s21_strerror");
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  tcase_add_test(tc, strerror_5);
  suite_add_tcase(s, tc);
  return s;
}