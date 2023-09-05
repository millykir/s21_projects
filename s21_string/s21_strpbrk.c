#include "s21_string.h"

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;

  for (const char *a = str1; *a; a++) {
    for (const char *b = str2; *b; b++) {
      if (*a == *b) {
        res = (char *)a;
        break;
      }
    }

    if (res) {
      break;
    }
  }

  return res;
}
/*
char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 1;
  char *result = s21_NULL;
  for (int i = 0; flag == 1 && str1[i]; i++) {
    for (int j = 0; flag == 1 && str2[j]; j++) {
      if ((str1[i] == str2[j])) {
        result = (char *)(str1 + i);
        flag = 0;
      }
    }
  }
  return result;
}
*/