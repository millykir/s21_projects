#include "string_test.h"

int main(void) {
  run_tests();
  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1) counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_memchr(),  suite_memcmp(),
                         suite_memcpy(),  suite_memset(),
                         suite_strncat(), suite_strchr(),
                         suite_strncmp(), suite_strncpy(),
                         suite_strcspn(), suite_strerror(),
                         suite_strlen(),  suite_strpbrk(),
                         suite_strrchr(), suite_strstr(),
                         suite_strtok(),  suite_sprintf(),
                         suite_sscanf(),  suite_insert(),
                         suite_trim(),    suite_lower(),
                         suite_upper(),   NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}