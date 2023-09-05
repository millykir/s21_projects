#include "s21_string.h"

// Возвращает новую строку, в которой удаляются все начальные
// и конечные вхождения набора заданных символов (trim_chars) из данной строки
// (src). В случае какой-либо ошибки следует вернуть значение NULL

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src) {
    if (!trim_chars) {
      trim_chars = "";
    }
    char *ptr_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    for (; *ptr_str && s21_strchr(trim_chars, *ptr_str); ptr_str++)
      ;
    for (; end_str != ptr_str && s21_strchr(trim_chars, *(end_str - 1));
         end_str--)
      ;
    result = (char *)calloc(end_str - ptr_str + 1, sizeof(char));
    if (result) {
      s21_strncpy(result, ptr_str, end_str - ptr_str);
      *(result + (end_str - ptr_str)) = '\0';
    }
  }
  return result;
}
