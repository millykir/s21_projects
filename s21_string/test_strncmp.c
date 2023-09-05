#include "string_test.h"

START_TEST(test_strncmp_1) {
  char str_1[10] = "\0";
  char str_2[50] = "Per aspera ad astra";
  ck_assert_int_eq(strncmp(str_1, str_2, 0), s21_strncmp(str_1, str_2, 0));
}
END_TEST

START_TEST(test_strncmp_2) {
  char str_1[50] = "Per aspera ad astra";
  char str_2[50] = "Per aspera ad astra";
  ck_assert_int_eq(strncmp(str_1, str_2, 10), s21_strncmp(str_1, str_2, 10));
}
END_TEST

START_TEST(test_strncmp_3) {
  char str_1[50] = "Per aspera ad astra";
  char str_2[50] = "Per asp3era ad astra";
  ck_assert_int_eq(strncmp(str_1, str_2, 10), s21_strncmp(str_1, str_2, 10));
}
END_TEST

Suite *suite_strncmp() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRNCMP");
  tc = tcase_create("case_strncmp");
  tcase_add_test(tc, test_strncmp_1);
  tcase_add_test(tc, test_strncmp_2);
  tcase_add_test(tc, test_strncmp_3);
  suite_add_tcase(s, tc);
  return s;
}