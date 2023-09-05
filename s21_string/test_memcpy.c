#include "string_test.h"

START_TEST(memcpy_1) {
  char src[20] = "hello world";
  char dest1[20] = {0};
  char dest2[20] = {0};
  s21_memcpy(dest1, src, 11);
  memcpy(dest2, src, 11);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_2) {
  char src[20] = "hello world";
  char dest1[20] = {0};
  char dest2[20] = {0};
  s21_memcpy(dest1, src, 0);
  memcpy(dest2, src, 0);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_3) {
  char src[20] = "hel\0lo world";
  char dest1[20] = {0};
  char dest2[20] = {0};
  s21_memcpy(dest1, src, 8);
  memcpy(dest2, src, 8);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_4) {
  char src[20] = "helloworld";
  char dest1[20] = {0};
  char dest2[20] = {0};
  s21_memcpy(dest1, src, 0);
  memcpy(dest2, src, 0);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_5) {
  char src[20] = "hel\0world";
  char dest1[20] = {0};
  char dest2[20] = {0};
  s21_memcpy(dest1, src, 8);
  memcpy(dest2, src, 8);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *suite_memcpy() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_MEMCPY");
  tc = tcase_create("case_s21_memcpy");
  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  suite_add_tcase(s, tc);
  return s;
}