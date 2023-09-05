#include "string_test.h"

START_TEST(strchr_1) {
  char str[] = "Hello world";
  int c = 3;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  char str[] = "Hello world\0";
  int c = 5;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  char str[] = "Hello world";
  int c = 12;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_4) {
  char str[] = "Hello world";
  int c = '\0';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_5) {
  char str[] = "";
  int c = 0;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRCHR");
  tc = tcase_create("case_strchr");
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  suite_add_tcase(s, tc);
  return s;
}