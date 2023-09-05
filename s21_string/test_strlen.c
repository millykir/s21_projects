#include "string_test.h"

START_TEST(strlen_1) {
  char str1[] = "Hello World\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

Suite *suite_strlen() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRLEN");
  tc = tcase_create("case_s21_strlen");
  tcase_add_test(tc, strlen_1);
  suite_add_tcase(s, tc);
  return s;
}