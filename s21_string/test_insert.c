#include "string_test.h"

START_TEST(insert_1) {
  char *str1 = "Aboba";
  char *in1 = "kek";
  char *result1 = s21_NULL;
  result1 = s21_insert(str1, in1, 2);
  ck_assert_str_eq(result1, "Abkekoba");
  free(result1);
}
START_TEST(insert_2) {
  char *str2 = "Aboba";
  char *in2 = "kek";
  char *result2 = s21_NULL;
  result2 = s21_insert(str2, in2, 5);
  ck_assert_str_eq(result2, "Abobakek");
  free(result2);
}
START_TEST(insert_3) {
  char *str3 = "";
  char *in3 = "k ek";
  char *result3 = s21_insert(str3, in3, 0);
  ck_assert_str_eq(result3, "k ek");
  free(result3);
}
START_TEST(insert_4) {
  char *str4 = "Aboba   ";
  char *in4 = "k ek";
  char *result4 = s21_insert(str4, in4, 0);
  ck_assert_str_eq(result4, "k ekAboba   ");
  free(result4);
}
START_TEST(insert_7) {
  char *str7 = "Aboba   ";
  char *in7 = "k ek";
  char *result7 = s21_insert(str7, in7, -1);
  ck_assert_ptr_eq(result7, s21_NULL);
  free(result7);
}

Suite *suite_insert() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_INSERT");
  tc = tcase_create("case_s21_insert");
  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_7);
  suite_add_tcase(s, tc);
  return s;
}