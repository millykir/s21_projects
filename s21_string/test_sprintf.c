#include <string.h>

#include "string_test.h"

char buf_for_sprintf[70];
char buf_for_s21_sprintf[70];

// SPRINTF TESTS START
START_TEST(test_d_sprintf) {
  int x1 = 234;
  int x2 = -345;
  char *format_string1 = "love %+d % d love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long int x3 = 2323454;
  short int x4 = -3;
  char *format_string2 = "love %20.10ld %05hd love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  int x5 = 2342;
  int x6 = -345;
  char *format_string3 = "love %+10d %-10d love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  int x7 = 0;
  char *format_string4 = "%.0d love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string4, x7),
                   sprintf(buf_for_sprintf, format_string4, x7));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_u_sprintf) {
  unsigned int x1 = 234;
  unsigned int x2 = 345;
  char *format_string1 = "love %u %u love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long unsigned int x3 = 2323454;
  short unsigned int x4 = 3;
  char *format_string2 = "love %lu %hu love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  unsigned int x5 = 2342;
  unsigned int x6 = 345;
  char *format_string3 = "love % 10u %10u love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);
  format_string3 = "love %-+ 10u %1.0u love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);
  format_string3 = "love %-8.3u %+ 10.2u love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);
  format_string3 = "love %*.*u %-+ .3u love";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string3, x4, x4, x5, x6),
      sprintf(buf_for_sprintf, format_string3, x4, x4, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_f_sprintf) {
  float x1 = 234.123;
  float x2 = -345.678;
  char *format_string1 = "love %.f %+f love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long double x3 = 21234.23434;
  long double x4 = -3234.56788;
  char *format_string2 = "love %10.2Lf %+.4Lf love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  double x5 = 0.2341;
  double x6 = -12345;
  char *format_string3 = "love %#f %010f love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_c_sprintf) {
  char x1 = 'i';
  char x2 = 's';
  char *format_string1 = "love %-10c%10c love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  unsigned long x3 = L'Ȭ';
  unsigned long x4 = L'ƾ';
  char *format_string2 = "love %10lc%-10lc love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_s_sprintf) {
  char *x1 = "you";
  char *x2 = "peer";
  char *format_string1 = "%10.2s my favourite %-10s";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));

  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  char *x5 = "t";  // s21_NULL;
  char *format_string3 = "%10.2s my favourite";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5),
                   sprintf(buf_for_sprintf, format_string3, x5));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  wchar_t *x3 = L"шайн";
  wchar_t *x4 = L"ƾȬ";
  char *format_string2 = "%10.2ls брайт %-10ls";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  wchar_t *x7 = L"шайн";
  wchar_t *x8 = L"ƾȬ";
  char *format_string5 = "%ls брайт %ls";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string5, x7, x8),
                   sprintf(buf_for_sprintf, format_string5, x7, x8));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  char *x15 = s21_NULL;
  char *format_string13 = "%s";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string13, x15),
                   sprintf(buf_for_sprintf, format_string13, x15));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  char *x16 = "s21_NULL";
  char *format_string14 = "%s------";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string14, x16),
                   sprintf(buf_for_sprintf, format_string14, x16));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  float d = 5.99999;
  char *format_string20 = "%.2f";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string20, d),
                   sprintf(buf_for_sprintf, format_string20, d));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  float d1 = 5.9;
  char *format_string21 = "%+.0f";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string21, d1),
                   sprintf(buf_for_sprintf, format_string21, d1));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  float d2 = -5.5;
  char *format_string22 = "%+*.*f";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string22, 10, 2, d2),
                   sprintf(buf_for_sprintf, format_string22, 10, 2, d2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  int dd = 0;
  char *format_string23 = "%d";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string23, dd),
                   sprintf(buf_for_sprintf, format_string23, dd));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  char ch9 = 'p';
  char *format_string25 = "%*.*c";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string25, 1, 1, ch9),
                   sprintf(buf_for_sprintf, format_string25, 1, 1, ch9));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  char *ch99 = "pprintf";
  char *format_string26 = "%*.*s";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string26, 10, 10, ch99),
      sprintf(buf_for_sprintf, format_string26, 10, 10, ch99));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  char *ch100 = s21_NULL;
  char *format_string27 = "%*.*s";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string27, 10, 10, ch100),
      sprintf(buf_for_sprintf, format_string27, 10, 10, ch100));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_x_sprintf) {
  int x1 = 234234;
  int x2 = 345123;
  int input = 15;
  int count;
  char *format_string1 = "love %.10x %*X %nlove";
  s21_sprintf(buf_for_s21_sprintf, format_string1, x1, input, x2, &count);
  sprintf(buf_for_sprintf, format_string1, x1, input, x2, &count);
  // printf("---------------->\n%s \n%s\n", buf_for_s21_sprintf,
  // buf_for_sprintf);

  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string1, x1, input, x2, &count),
      sprintf(buf_for_sprintf, format_string1, x1, input, x2, &count));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long int x3 = 23423423;
  long int x4 = 3451231;
  char *format_string2 = "love %#lx %#lX love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_o_sprintf) {
  int x1 = 234234;
  unsigned short x2 = 34;
  int input = 15;
  int count;
  char *format_string1 = "love %20o %*ho %n love";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string1, x1, input, x2, &count),
      sprintf(buf_for_sprintf, format_string1, x1, input, x2, &count));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long int x3 = 23423423;
  long int x4 = 345123123;
  char *format_string2 = "love %020lo %#-15lo love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_p_sprintf) {
  int x1 = 234;
  int x2 = 345;
  char *format_string1 = "love %10p %-10p love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, &x1, &x2),
                   sprintf(buf_for_sprintf, format_string1, &x1, &x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_g_sprintf) {
  double x1 = 123.2341;
  double x2 = -0.341;
  char *format_string1 = "love % g %10g love";
  // s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2);
  // sprintf(buf_for_sprintf, format_string1, x1, x2);
  // printf("---------------->\n%s \n%s\n", buf_for_s21_sprintf,
  // buf_for_sprintf);

  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long double x3 = 12345.2341;
  long double x4 = -0.00000341;
  char *format_string2 = "love %+.2Lg %10.LG love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  double x5 = -12345;
  double x6 = 0.23453;
  char *format_string3 = "love %#g %-10g love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_e_sprintf) {
  double x1 = 12345.2345;
  double x2 = -0.341;
  int input = 5;
  char *format_string1 = "love %*.*e % E love";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string1, input, input, x1, x2),
      sprintf(buf_for_sprintf, format_string1, input, input, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long double x3 = 12345.2345;
  long double x4 = -0.0000345;
  char *format_string2 = "love %+.2Le %10.LE love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  double x5 = 12.098;
  double x6 = -12345;
  char *format_string3 = "love %#e %010e love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

START_TEST(test_i_sprintf) {
  long int x3 = 2323454;
  short int x4 = 3;
  char *format_string2 = "love %-3li %+03hi love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  int x1 = 0x234;
  int x2 = 0x345;
  int input = 10;
  char *format_string1 = "love %*i %i love";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string1, input, x1, x2),
      sprintf(buf_for_sprintf, format_string1, input, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}
END_TEST

Suite *suite_sprintf() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_SPRINTF");
  tc = tcase_create("case_s21_sprintf");
  tcase_add_test(tc, test_d_sprintf);
  tcase_add_test(tc, test_u_sprintf);
  tcase_add_test(tc, test_f_sprintf);
  tcase_add_test(tc, test_c_sprintf);
  tcase_add_test(tc, test_s_sprintf);
  tcase_add_test(tc, test_x_sprintf);
  tcase_add_test(tc, test_o_sprintf);
  tcase_add_test(tc, test_p_sprintf);
  tcase_add_test(tc, test_g_sprintf);
  tcase_add_test(tc, test_e_sprintf);
  tcase_add_test(tc, test_i_sprintf);

  suite_add_tcase(s, tc);
  return s;
}