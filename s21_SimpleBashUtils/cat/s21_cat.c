#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flags {
  int b, e, n, s, t, v;
};

void check(int argc, char** argv, struct flags* home);
void flags(int argc, char** argv, struct flags home);

int main(int argc, char** argv) {
  struct flags home = {0, 0, 0, 0, 0, 0};
  check(argc, argv, &home);
  return 0;
}

void check(int argc, char** argv, struct flags* home) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      if (!strcmp(argv[i], "-n"))
        home->n = 1;
      else if (!strcmp(argv[i], "-b"))
        home->b = 1;
      else if (!strcmp(argv[i], "-e")) {
        home->e = 1;
        home->v = 1;
      } else if (!strcmp(argv[i], "-s"))
        home->s = 1;
      else if (!strcmp(argv[i], "-t")) {
        home->t = 1;
        home->v = 1;
      } else if (!strcmp(argv[i], "-v"))
        home->v = 1;
      else if (!strcmp(argv[i], "-E")) {
        home->e = 1;
      } else if (!strcmp(argv[i], "-T")) {
        home->t = 1;
      } else if (!strcmp(argv[i], "--squeeze-blank")) {
        home->s = 1;
      } else if (!strcmp(argv[i], "--number-nonblank")) {
        home->b = 1;
      } else if (!strcmp(argv[i], "--number")) {
        home->n = 1;
      }
    }
    if (home->b == 1) home->n = 0;
    flags(argc, argv, *home);
  }
}

void flags(int argc, char** argv, struct flags home) {
  FILE* fl;
  char ch = '\0', p = '\0';
  int count = 0, count_end = 0, right_up = 0, v_flag = 0;
  fl = fopen(argv[argc - 1], "r");
  if (fl != NULL) {
    int str = 1;
    while ((ch = fgetc(fl)) != EOF) {
      if (home.n) {
        if (str == 1) {
          printf("%6d\t", str);
          str++;
        }
      }
      if (home.b) {
        if (((p != ch) && p == '\n') || (ch != '\n' && count == 0)) {
          printf("%6d\t", str);
          str++;
        }
      }
      if (home.s) {
        if (ch == '\n') {
          count_end++;
          if (count == 0) count_end++;
        } else
          count_end = 0;
      }
      count++;
      if (home.n) {
        if (p == '\n' && count_end < 3) {
          printf("%6d\t", str);
          str++;
        }
      }
      if (home.e) {
        if (ch == '\n' && count_end < 3) {
          printf("%c", '$');
        }
      }
      if (home.t) {
        if (ch == '\t') {
          ch = '^';
          right_up = 1;
        } else
          right_up = 0;
      }
      if (home.v) {
        if ((ch < 32 || ch == 127) && ch != 9 && ch != 10) {
          if (ch == 127)
            printf("^%c", 63);
          else
            printf("^%c", ch + 64);
          v_flag = 1;
        } else
          v_flag = 0;
      }
      if (home.n) {
        if (count_end < 3 && v_flag == 0) {
          printf("%c", ch);
        }
      }
      if (home.n == 0 && count_end < 3 && v_flag == 0) printf("%c", ch);
      if (ch == '^' && right_up == 1) printf("I");
      p = ch;
    }
    fclose(fl);
  }
}
