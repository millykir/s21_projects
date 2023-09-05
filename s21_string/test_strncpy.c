#include "string_test.h"

START_TEST(strncpy_1) {
  char str_1[50] = "qwerty";
  char str_2[50] = "12345";
  ck_assert_str_eq(strncpy(str_1, str_2, 2 * 2),
                   s21_strncpy(str_1, str_2, 2 * 2));
}
END_TEST

START_TEST(strncpy_2) {
  char str_1[60] = "50 pdfh";
  char str_2[50] = "HELLO!\n5";
  ck_assert_str_eq(strncpy(str_1, str_2, 5 - 1),
                   s21_strncpy(str_1, str_2, 5 - 1));
}
END_TEST

START_TEST(strncpy_3) {
  char str_1[50] = "\n/f\f/n";
  char str_2[50] = "55/f/n\f\n";
  ck_assert_str_eq(strncpy(str_1, str_2, 0), s21_strncpy(str_1, str_2, 0));
}
END_TEST

START_TEST(strncpy_4) {
  char str_1[20] = "abracadabra ";
  char str_2[] = " 123";
  ck_assert_str_eq(strncpy(str_1, str_2, 10), s21_strncpy(str_1, str_2, 10));
}
END_TEST

START_TEST(strncpy_5) {
  char str_1[50] = "s_=+*&/te   ";
  char str_2[50] = "vosem'";
  ck_assert_str_eq(strncpy(str_1, str_2, 6), s21_strncpy(str_1, str_2, 6));
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRNCPY");
  tc = tcase_create("case_strncpy");
  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  suite_add_tcase(s, tc);
  return s;
}