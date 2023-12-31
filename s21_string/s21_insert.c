#include "s21_string.h"

// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL

char *s21_strcat(char *dest, const char *src) {
  char *p = dest;
  while (*p != '\0') p++;
  while (*src != '\0') *p++ = *src++;
  *p = '\0';
  return dest;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *cpy = s21_NULL;
  if (src && str)
    cpy = (char *)calloc((s21_strlen(src) + s21_strlen(str)) + 1, sizeof(char));
  char *tmp = cpy;
  if (cpy) {
    if (s21_strlen(src) >= start_index) {
      s21_strncpy(cpy, src, start_index);
      cpy += start_index;
      s21_strcat(cpy, str);
      s21_strcat(cpy, src + start_index);
    } else {
      free(cpy);
      tmp = s21_NULL;
    }
  }
  return tmp;
}