#include "s21_string.h"

// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *temp1 = (char *)dest;
  char *temp2 = (char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    *temp1 = *temp2;
    temp1++;
    temp2++;
  }
  return dest;
}