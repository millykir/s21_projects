#include "s21_string.h"
// Сравнивает первые n байтов str1 и str2

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  unsigned char* p1 = (unsigned char*)str1;
  unsigned char* p2 = (unsigned char*)str2;
  if (n != 0) {
    do {
      if (*p1++ != *p2++) return (*--p1 - *--p2);
    } while (--n != 0);
  }
  return (0);
}