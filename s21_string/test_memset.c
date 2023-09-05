#include "string_test.h"

START_TEST(memset_1) {
  char str[10] = "987654321";
  ck_assert_str_eq(memset(str, 'p', 3), s21_memset(str, 'p', 3));
}
END_TEST

START_TEST(memset_2) {
  char str1[15] = "1111167890";
  char str2[15] = "2222267890";
  int c = 'p';
  int n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_3) {
  char str1[15] = "pavel_hello";
  char str2[15] = "pavel_hello";
  int c = '\0';
  int n = 8;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_4) {
  char str1[15] = "privet_andrey";
  char str2[15] = "privet_andrey";
  int c = '\n';
  int n = 9;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_5) {
  char s1[15] = "FAIL";
  ck_assert_pstr_eq(memset(s1, 8, 6), s21_memset(s1, 8, 6));
}
END_TEST

Suite *suite_memset(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_MEMSET");
  tc = tcase_create("case_memset");
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  suite_add_tcase(s, tc);
  return s;
}