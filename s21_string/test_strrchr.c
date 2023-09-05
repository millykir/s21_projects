#include "string_test.h"

START_TEST(strrchr_1) {
  char str[] = "Techie Delight – Ace the Technical Interviews";
  int c = 'D';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_2) {
  char str[] = "Hello World";
  int c = 'e';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_3) {
  char str[] = "Hello World";
  int c = 'a';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_4) {
  char str[] = "Hello World";
  int c = 0;
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_5) {
  char str[] = "";
  int c = 'a';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

Suite *suite_strrchr() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRRCHR");
  tc = tcase_create("case_strrchr");
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  suite_add_tcase(s, tc);
  return s;
}