#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t size = 0;
  while (str[size]) {  // пока индекс строки действителен
    ++size;            // увеличиваем счетчик размера
  }
  return size;  // возвращаем размер
}