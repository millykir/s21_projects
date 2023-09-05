#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flags {
  int e, i, v, c, l, n, h, s, o;
};

void check(int argc, char** argv, struct flags* home);
void flags_one(int argc, char** argv, struct flags home, int regexx);
void flags_more(int argc, char** argv, struct flags home, int regexx);

int main(int argc, char** argv) {
  struct flags home = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  check(argc, argv, &home);
  return 0;
}

void check(int argc, char** argv, struct flags* home) {
  int regexx = 0, flag = 0;
  if (argc > 1) {
    for (int i = 1; i != argc; i++) {
      for (int j = 0; argv[i][j] != '\0'; j++) {
        if (argv[i][0] == '-' && i == 1) {
          if (argv[i][j] == 'e')
            home->e = 1;
          else if (argv[i][j] == 'i')
            home->i = 1;
          else if (argv[i][j] == 'v')
            home->v = 1;
          else if (argv[i][j] == 'c')
            home->c = 1;
          else if (argv[i][j] == 'l')
            home->l = 1;
          else if (argv[i][j] == 'n')
            home->n = 1;
          else if (argv[i][j] == 'h')
            home->h = 1;
          else if (argv[i][j] == 's')
            home->s = 1;
          else if (argv[i][j] == 'o')
            home->o = 1;
          flag = 1;
          regexx = 2;
        } else
          break;
      }
    }
    if (!flag) regexx = 1;
    if (regexx > 0) {
      if (argc > 4 || (argc > 3 && !flag))
        flags_more(argc, argv, *home, regexx);
      else if (argc == 4 || (argc == 3 && !flag))
        flags_one(argc, argv, *home, regexx);
    }
  }
}

void flags_one(int argc, char** argv, struct flags home, int regexx) {
  FILE* fl;
  char* line = NULL;
  size_t line_count = 0;
  regex_t lineread;
  int have = 0, check_comp = 0, count_c = 0, count_l = 0, count_n = 0;
  fl = fopen(argv[argc - 1], "r");
  if (fl != NULL) {
    if (home.i)
      check_comp = regcomp(&lineread, argv[regexx], REG_ICASE);
    else
      check_comp = regcomp(&lineread, argv[regexx], REG_EXTENDED);
    if (!check_comp) {
      fl = fopen(argv[argc - 1], "r");
      while (getline(&line, &line_count, fl) != EOF) {
        count_n++;
        have = regexec(&lineread, line, 0, NULL, 0);
        if (home.v) have = !have;
        if (!have) {
          if (!home.c && !home.l)
            if (home.n)
              printf("%d:%s", count_n, line);
            else
              printf("%s", line);
          else if (home.c)
            count_c++;
          count_l++;
          if (line[strlen(line) - 1] != '\n' && !home.l && !home.c)
            printf("\n");
        }
      }
      if (home.c)
        printf("%d\n", count_c);
      else if (home.l && count_l > 0)
        printf("%s\n", argv[argc - 1]);
    }
    fclose(fl);
    free(line);
  } else {
    if (!home.s)
      fprintf(stderr, "grep: %s: No such file or directory", argv[argc - 1]);
  }
  regfree(&lineread);
}

void flags_more(int argc, char** argv, struct flags home, int regexx) {
  FILE* fl;
  char* line = NULL;
  size_t line_count = 0;
  regex_t lineread;
  int have = 0, check_comp = 0, count_c = 0, count_l = 0, count_n = 0;
  if (home.i)
    check_comp = regcomp(&lineread, argv[regexx], REG_ICASE);
  else
    check_comp = regcomp(&lineread, argv[regexx], REG_EXTENDED);
  for (int i = regexx + 1; i != argc; i++) {
    count_c = 0;
    count_n = 0;
    count_l = 0;
    fl = fopen(argv[i], "r");
    if (fl != NULL) {
      if (!check_comp) {
        while (getline(&line, &line_count, fl) != EOF) {
          count_n++;
          have = regexec(&lineread, line, 0, NULL, 0);
          if (home.v) have = !have;
          if (!have) {
            if (!home.c && !home.l && !home.h) {
              if (home.n) {
                printf("%s:%d:%s", argv[i], count_n, line);
              } else {
                printf("%s:%s", argv[i], line);
              }
            } else if (!home.c && !home.l && home.h) {
              if (home.n)
                printf("%d:%s", count_n, line);
              else
                printf("%s", line);
            } else if (home.c)
              count_c++;
            count_l++;
            if (line[strlen(line) - 1] != '\n' && !home.l && !home.c)
              printf("\n");
          }
        }
        if (home.c && !home.h)
          printf("%s:%d\n", argv[i], count_c);
        else if (home.c && home.h)
          printf("%d\n", count_c);
        else if (home.l && count_l > 0)
          printf("%s\n", argv[i]);
      }
      fclose(fl);
    } else {
      if (!home.s) {
        fprintf(stderr, "grep: %s: No such file or directory", argv[argc - 1]);
        printf("\n");
      }
    }
  }
  regfree(&lineread);
  free(line);
}
