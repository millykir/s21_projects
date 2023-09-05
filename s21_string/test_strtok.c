#include "string_test.h"

START_TEST(strtok_1) {
  char str_24[15] = "This,is,my,way";
  char str_25[2] = ",";
  ck_assert_pstr_eq(strtok(str_24, str_25), s21_strtok(str_24, str_25));
}
END_TEST

START_TEST(strtok_2) {
  char str1[6] = "delim";
  char str2[2] = "f";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_3) {
  char str[50] = "Per, :aspera;ad astra";
  char str1[10] = " ,:\n\0";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_4) {
  char str[50] = "Per, :aspera;ad. astra";
  char str1[10] = ",:\n\0";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_5) {
  char str[50] = "Per :aspn::::::era;ad. ast::::ra:";
  char str1[10] = ":";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_6) {
  char str[50] = "AadacAdxa";
  char str1[10] = "a";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_7) {
  char str[] = "A";
  char str1[] = "\0";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(strtok_8) {
  char str_24[15] = "This,is,my,way";
  char str_25[2] = ",";
  ck_assert_pstr_eq(strtok(str_24, str_25), s21_strtok(str_24, str_25));
}
END_TEST

START_TEST(strtok_9) {
  char str1[6] = "delim";
  char str2[2] = "f";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_10) {
  char str1[] = "qwerty";
  char str2[] = "1234";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_11) {
  char str1[22] = "Per, :aspera;ad astra";
  char str2[3] = " ";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_12) {
  char str1[] = "check/Me/Out\\";
  char str2[] = "check/Me/Out\\";
  char simbols[] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str1, simbols);
  nstr_2 = s21_strtok(str2, simbols);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, simbols);
    nstr_2 = s21_strtok(s21_NULL, simbols);
  }
}
END_TEST

START_TEST(strtok_13) {
  char str1[] =
      "Особенности национальной рыбалки - художественный, комедийный фильм.";
  char str2[] =
      "Особенности национальной рыбалки - художественный, комедийный фильм.";
  char simbols[5] = " ,.-";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str1, simbols);
  nstr_2 = s21_strtok(str2, simbols);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, simbols);
    nstr_2 = s21_strtok(s21_NULL, simbols);
  }
}
END_TEST

START_TEST(strtok_14) {
  char str4_1[] = "testing with original string.h";
  char str4_2[] = "testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_15) {
  char *str1 = s21_NULL;
  char *str2 = "a";
  ck_assert_ptr_null(s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_16) {
  char str1[22] = "";
  char str2[3] = "";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

// START_TEST(strtok_17) {
//   char *str1 = s21_NULL;
//   char str2[3] = "\0";
//   ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
// }
// END_TEST

START_TEST(strtok_18) {
  char str1[] = "adfdffd;;hdjsghkjh:jsdfbjk";
  char *str2 = ";::?";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_STRTOK");
  tc = tcase_create("case_strtok");
  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);
  tcase_add_test(tc, strtok_8);
  tcase_add_test(tc, strtok_9);
  tcase_add_test(tc, strtok_10);
  tcase_add_test(tc, strtok_11);
  tcase_add_test(tc, strtok_12);
  tcase_add_test(tc, strtok_13);
  tcase_add_test(tc, strtok_14);
  tcase_add_test(tc, strtok_15);
  tcase_add_test(tc, strtok_16);
  // tcase_add_test(tc, strtok_17);
  tcase_add_test(tc, strtok_18);
  suite_add_tcase(s, tc);
  return s;
}