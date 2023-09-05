#include "string_test.h"

START_TEST(upper_1) {
  void *result1 = s21_to_upper("Hello world\0");
  ck_assert_str_eq((const char *)result1, "HELLO WORLD\0");
  free(result1);
}
START_TEST(upper_2) {
  void *result2 = s21_to_upper("world\0");
  ck_assert_str_eq((const char *)result2, "WORLD\0");
  free(result2);
}
START_TEST(upper_3) {
  void *result3 = s21_to_upper("a\n\0");
  ck_assert_str_eq((const char *)result3, "A\n\0");
  free(result3);
}
START_TEST(upper_4) {
  void *result4 = s21_to_upper(" \n\0");
  ck_assert_str_eq((const char *)result4, " \n\0");
  free(result4);
}
START_TEST(upper_5) {
  void *result5 = s21_to_upper("HELLO WORLD\0");
  ck_assert_str_eq((const char *)result5, "HELLO WORLD\0");
  free(result5);
}
START_TEST(upper_6) {
  void *result6 = s21_to_upper("\0");
  ck_assert_str_eq((const char *)result6, "\0");
  free(result6);
}
START_TEST(upper_7) {
  void *result6 = s21_to_upper("shrek");
  ck_assert_str_eq((const char *)result6, "SHREK");
  free(result6);
}

Suite *suite_upper() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_upper");
  tc = tcase_create("case_s21_upper");
  tcase_add_test(tc, upper_1);
  tcase_add_test(tc, upper_2);
  tcase_add_test(tc, upper_3);
  tcase_add_test(tc, upper_4);
  tcase_add_test(tc, upper_5);
  tcase_add_test(tc, upper_6);
  tcase_add_test(tc, upper_7);
  suite_add_tcase(s, tc);
  return s;
}