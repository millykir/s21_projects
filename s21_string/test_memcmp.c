#include "string_test.h"

START_TEST(memcmp_1) {
  char *str1 = "hello";
  char *str2 = "hello";
  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str1)),
                   memcmp(str1, str2, strlen(str1)));
  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str2)),
                   memcmp(str1, str2, strlen(str2)));
}
END_TEST

START_TEST(memcmp_2) {
  char *str1 = "hello";
  char *str2 = "world";
  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str1)),
                   memcmp(str1, str2, strlen(str1)));
  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str2)),
                   memcmp(str1, str2, strlen(str2)));
}
END_TEST

START_TEST(memcmp_3) {
  char *str1 = "hello";
  char *str2 = "he";
  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str1)),
                   s21_memcmp(str1, str2, strlen(str1)));
  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str2)),
                   memcmp(str1, str2, strlen(str2)));
}
END_TEST

START_TEST(memcmp_4) {
  char *str1 = "hello";
  char *str2 = "world";
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

START_TEST(memcmp_5) {
  char *str1 = "hell";
  char *str2 = "wrld";
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
}
END_TEST

Suite *suite_memcmp() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_MEMCMP");
  tc = tcase_create("case_s21_memcmp");
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  suite_add_tcase(s, tc);
  return s;
}