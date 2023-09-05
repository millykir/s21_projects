#include "string_test.h"

START_TEST(strpbrk_1) {
  char str1[] = "Hello World\0";
  char str2[] = "Wo\0";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  char str1[] = "";
  char str2[] = "";
  if (strpbrk(str1, str2) != s21_NULL && s21_strpbrk(str1, str2) != s21_NULL)
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
  else
    ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  char str1[] = "\0";
  char str2[] = "\0";
  if (strpbrk(str1, str2) != s21_NULL && s21_strpbrk(str1, str2) != s21_NULL)
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
  else
    ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  char str1[] = "H\0";
  char str2[] = "";
  if (strpbrk(str1, str2) != s21_NULL && s21_strpbrk(str1, str2) != s21_NULL)
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
  else
    ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  char str1[] = "W";
  char str2[] = "o";
  if (strpbrk(str1, str2) != s21_NULL && s21_strpbrk(str1, str2) != s21_NULL)
    ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
  else
    ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *suite_strpbrk() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRPBRK");
  tc = tcase_create("case_s21_strpbrk");
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  suite_add_tcase(s, tc);
  return s;
}
