#include "string_test.h"

START_TEST(trim_1) {
  char *str1 = "WoW, I love it!";
  char *ptr1 = "W";
  char *res1 = (char *)s21_trim(str1, ptr1);
  ck_assert_str_eq(res1, "oW, I love it!");
  free(res1);
}
START_TEST(trim_2) {
  char *str2 = "WoW\0, I love it!";
  char *ptr2 = "W";
  char *res2 = (char *)s21_trim(str2, ptr2);
  ck_assert_str_eq(res2, "o");
  free(res2);
}
START_TEST(trim_3) {
  char *str3 = "WoW, I love it!";
  char *ptr3 = "Wo!";
  char *res3 = (char *)s21_trim(str3, ptr3);
  ck_assert_str_eq(res3, ", I love it");
  free(res3);
}
START_TEST(trim_4) {
  char *str4 = "WoW, I love it!";
  char *ptr4 = "P";
  char *res4 = (char *)s21_trim(str4, ptr4);
  ck_assert_str_eq(res4, "WoW, I love it!");
  free(res4);
}
START_TEST(trim_5) {
  char *str5 = "abc";
  char *ptr5 = "abc";
  char *res5 = (char *)s21_trim(str5, ptr5);
  ck_assert_str_eq(res5, "");
  free(res5);
}
START_TEST(trim_6) {
  char *str6 = "     HELLO    ";
  char *ptr6 = " ";
  char *res6 = (char *)s21_trim(str6, ptr6);
  ck_assert_str_eq(res6, "HELLO");
  free(res6);
}
START_TEST(trim_7) {
  char *str7 = "HELLO";
  char *ptr7 = s21_NULL;
  char *res7 = (char *)s21_trim(str7, ptr7);
  ck_assert_str_eq(res7, "HELLO");
  free(res7);
}

Suite *suite_trim() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_TRIM");
  tc = tcase_create("case_s21_trim");
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  tcase_add_test(tc, trim_6);
  tcase_add_test(tc, trim_7);
  suite_add_tcase(s, tc);
  return s;
}