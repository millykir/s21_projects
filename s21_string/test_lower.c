#include "string_test.h"

START_TEST(lower_1) {
  void *result1 = s21_to_lower("Hello world\0");
  ck_assert_str_eq((const char *)result1, "hello world\0");
  free(result1);
}
START_TEST(lower_2) {
  void *result2 = s21_to_lower("world\0");
  ck_assert_str_eq((const char *)result2, "world\0");
  free(result2);
}
START_TEST(lower_3) {
  void *result3 = s21_to_lower("A\n\0");
  ck_assert_str_eq((const char *)result3, "a\n\0");
  free(result3);
}
START_TEST(lower_4) {
  void *result4 = s21_to_lower(" \n\0");
  ck_assert_str_eq((const char *)result4, " \n\0");
  free(result4);
}
START_TEST(lower_5) {
  void *result5 = s21_to_lower("hello world\0");
  ck_assert_str_eq((const char *)result5, "hello world\0");
  free(result5);
}
START_TEST(lower_6) {
  void *result6 = s21_to_lower("\0");
  ck_assert_str_eq((const char *)result6, "\0");
  free(result6);
}
START_TEST(lower_7) {
  void *result6 = s21_to_lower("SHREK");
  ck_assert_str_eq((const char *)result6, "shrek");
  free(result6);
}

Suite *suite_lower() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_LOWER");
  tc = tcase_create("case_s21_lower");
  tcase_add_test(tc, lower_1);
  tcase_add_test(tc, lower_2);
  tcase_add_test(tc, lower_3);
  tcase_add_test(tc, lower_4);
  tcase_add_test(tc, lower_5);
  tcase_add_test(tc, lower_6);
  tcase_add_test(tc, lower_7);
  suite_add_tcase(s, tc);
  return s;
}