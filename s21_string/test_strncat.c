#include "string_test.h"

START_TEST(strncat_1) {
  char str_1[100] = "Hello";
  char str_2[100] = " Pavel";
  ck_assert_str_eq(strncat(str_1, str_2, 3), s21_strncat(str_1, str_2, 3));
}
END_TEST

START_TEST(strncat_2) {
  char str_1[100] = "\0";
  char str_2[100] = "i like pokemon";
  ck_assert_str_eq(strncat(str_1, str_2, 13), s21_strncat(str_1, str_2, 13));
}
END_TEST

START_TEST(strncat_3) {
  char str_1[100] = "\n";
  char str_2[100] = "p-\0-dogmen";
  ck_assert_str_eq(strncat(str_1, str_2, 9), s21_strncat(str_1, str_2, 9));
}
END_TEST

START_TEST(strncat_4) {
  char str_1[100] = "-\t-";
  char str_2[100] = "\0";
  ck_assert_str_eq(strncat(str_1, str_2, 2), s21_strncat(str_1, str_2, 2));
}
END_TEST

START_TEST(strncat_5) {
  char str_1[100] = " \b";
  char str_2[100] = "  15 \n";
  ck_assert_str_eq(strncat(str_1, str_2, 5), s21_strncat(str_1, str_2, 5));
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRNCAT");
  tc = tcase_create("case_strncat");
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  suite_add_tcase(s, tc);
  return s;
}