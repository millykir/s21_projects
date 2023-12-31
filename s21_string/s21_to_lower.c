#include "s21_string.h"

// Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL

void *s21_to_lower(const char *str) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    int y = 0;
    result = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
    if (!result) exit(0);
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] >= 65 && str[i] <= 91) {
        result[i] = str[i] + 32;
      } else {
        result[i] = str[i];
      }
      ++y;
    }
    result[y] = '\0';
  }
  return result;
}
