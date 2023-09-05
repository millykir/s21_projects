#include "string_test.h"

START_TEST(memchr_1) {
  char str[] = "Hello World\0";
  void *ptr1 = s21_memchr(str, 'H', strlen(str));
  void *ptr2 = memchr(str, 'H', strlen(str));
  if (ptr1 && ptr2) {
    ck_assert_ptr_eq(ptr1, ptr2);
  }
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "Hello World\0";
  void *ptr1 = s21_memchr(str, 'o', strlen(str));
  void *ptr2 = memchr(str, 'o', strlen(str));
  if (ptr1 && ptr2) {
    ck_assert_ptr_eq(ptr1, ptr2);
  }
}
END_TEST

START_TEST(memchr_3) {
  char str[] = "Hello-World\0";
  //  finding 'H' in the string
  void *ptr1 = s21_memchr(str, '-', strlen(str));
  void *ptr2 = memchr(str, '-', strlen(str));
  if (ptr1 && ptr2) {
    ck_assert_ptr_eq(ptr1, ptr2);
  }
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "Hello, wo\0rld!H";
  void *ptr1 = s21_memchr(str, '\0', strlen(str));
  void *ptr2 = memchr(str, '\0', strlen(str));
  if (ptr1 && ptr2) {
    ck_assert_ptr_eq(ptr1, ptr2);
  }
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "Hello, Hello, world!";
  void *ptr1 = s21_memchr(str, 'H', strlen(str));
  void *ptr2 = memchr(str, 'H', strlen(str));
  if (ptr1 && ptr2) {
    ck_assert_ptr_eq(ptr1, ptr2);
  }
}
END_TEST

Suite *suite_memchr() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_MEMCHR");
  tc = tcase_create("case_s21_memchr");
  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);

  suite_add_tcase(s, tc);
  return s;
}