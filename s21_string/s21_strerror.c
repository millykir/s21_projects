#include "s21_string.h"

// Возвращает указатель на строку с ошибкой

char *s21_strerror(int errnum) {
  static char *list_error[] = ERR_LIST;
  char *error = s21_NULL;
  static char error_none[100];
  char *unknow = "Unknown error";
  if (errnum >= 0 && errnum < N) {
    error = list_error[errnum];
  } else {
    if (std) {
      s21_sprintf(error_none, "%s: %d", unknow, errnum);
    } else {
      s21_sprintf(error_none, "%s %d", unknow, errnum);
    }
  }
  return error != s21_NULL ? (char *)error : (char *)error_none;
}