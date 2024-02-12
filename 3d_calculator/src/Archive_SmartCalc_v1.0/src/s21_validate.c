#include <math.h>

#include "s21_calc.h"

int s21_validate(char* current) {
  stack_rpn* runner;
  int error = EXIT_SUCCESS;
  int first = 1;

  while (*current) {
    if (strchr(NUMBERS, *current)) {
      char buff[256];
      current += f2(current, NUMBERS, buff);
      const char* atof_expr = buff;
      push(&runner, atof(atof_expr), 0, enum_number);
    } else if (strchr(LITE_LEXEMES, *current)) {
      if (*current == '-') {
        push(&runner, 0, 2, enum_plus);
      } else if (*current == '+') {
        push(&runner, 0, 2, enum_plus);
      } else if (*current == '/') {
        push(&runner, 0, 3, enum_plus);
      } else if (*current == '*') {
        push(&runner, 0, 3, enum_plus);
      } else if (*current == '^') {
        push(&runner, 0, 4, enum_x);
      } else if (*current == '(') {
        push(&runner, 0, 1, enum_minus);
      } else if (*current == ')') {
        push(&runner, 0, 1, enum_multiply);
      }
      current++;
    } else if (strchr(HARD_LEXEMES, *current)) {
      char buff[256];
      current += f2(current, HARD_LEXEMES, buff);
      if (strcmp(buff, "mod") == 0) {
        push(&runner, 0, 3, enum_plus);
      } else if (strcmp(buff, "cos") == 0) {
        push(&runner, 0, 5, enum_x);
      } else if (strcmp(buff, "sin") == 0) {
        push(&runner, 0, 5, enum_x);
      } else if (strcmp(buff, "tan") == 0) {
        push(&runner, 0, 5, enum_x);
      } else if (strcmp(buff, "acos") == 0) {
        push(&runner, 0, 5, enum_x);
      } else if (strcmp(buff, "asin") == 0) {
        push(&runner, 0, 5, enum_x);
      } else if (strcmp(buff, "atan") == 0) {
        push(&runner, 0, 5, enum_x);
      } else if (strcmp(buff, "sqrt") == 0) {
        push(&runner, 0, 5, enum_x);
      } else if (strcmp(buff, "ln") == 0) {
        push(&runner, 0, 5, enum_x);
      } else if (strcmp(buff, "log") == 0) {
        push(&runner, 0, 5, enum_x);
      }
    } else {
      current++;
    }
  }
  reverseStack(&runner);

  while (runner != NULL) {
    if (first) {
      if (runner->type == enum_number || runner->type == enum_minus ||
          runner->type == enum_x)
        error |= EXIT_SUCCESS;
      else
        error |= EXIT_FAILURE;
      first = 0;
    }

    if (runner->type == enum_number) {
      if (runner->NEXT == NULL)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_number)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_x)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_plus)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_minus)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_multiply)
        error |= EXIT_SUCCESS;
    }

    else if (runner->type == enum_x) {
      if (runner->NEXT == NULL)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_number)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_x)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_plus)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_minus)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_multiply)
        error |= EXIT_FAILURE;
    }

    else if (runner->type == enum_plus) {
      if (runner->NEXT == NULL)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_number)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_x)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_plus)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_minus)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_multiply)
        error |= EXIT_FAILURE;
    }

    else if (runner->type == enum_minus) {
      if (runner->NEXT == NULL)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_number)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_x)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_plus)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_minus)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_multiply)
        error |= EXIT_FAILURE;
    }

    else if (runner->type == enum_multiply) {
      if (runner->NEXT == NULL)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_number)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_x)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_plus)
        error |= EXIT_SUCCESS;
      else if ((runner->NEXT)->type == enum_minus)
        error |= EXIT_FAILURE;
      else if ((runner->NEXT)->type == enum_multiply)
        error |= EXIT_SUCCESS;
    }
    runner = runner->NEXT;
  }

  int bracket = 0;
  while (runner != NULL) {
    if (runner->type == enum_minus)
      bracket++;
    else if (runner->type == enum_multiply)
      bracket--;
    if (bracket < 0) error |= EXIT_FAILURE;
    runner = runner->NEXT;
  }
  if (bracket != 0) error = EXIT_FAILURE;
  s21_clear_stack(&runner);
  return error;
}
