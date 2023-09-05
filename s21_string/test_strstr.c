#include "string_test.h"

START_TEST(strstr_1) {
  char str[] = "Techie Delight – Ace the Technical Interviews";
  char str1[] = "Ace";
  ck_assert_str_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_2) {
  char str[] = " \n\0\0";
  char str1[] = " a\n\0";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_3) {
  char str[] = "\0";
  char str1[] = " schhol21\0";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_4) {
  char str[] = "i am\nproger";
  char str1[] = " a\n\0";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_5) {
  char str[] = "Hello World";
  char str1[] = "Hell";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

Suite *suite_strstr() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRSTR");
  tc = tcase_create("case_strstr");
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  suite_add_tcase(s, tc);
  return s;
}