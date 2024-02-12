#include "s21_calc.h"

int main() {
  double x = 2 + 3;
  printf("\nРезультат: %lf\n", x);
  x = convertToRPN(EXPRESSION);
  printf("\nРезультат: %lf\n", x);

  return 0;
}

double convertToRPN(char* expr) {
  char* current = expr;
  int res = 0;
  stack_rpn* outputStack = NULL;
  stack_rpn* operatorStack = NULL;
  double result = 0;
  int flag = 0;
  int flag2 = 0;

  res = s21_validate(current);

  if (res == 0) {
    while (*expr) {
      if (strchr(NUMBERS, *expr)) {
        char buff[256];
        expr += f2(expr, NUMBERS, buff);
        const char* atof_expr = buff;
        push(&outputStack, atof(atof_expr), 0, enum_number);
        if (flag == 1) {
          outputStack->value = -outputStack->value;
          flag = 0;
          if (operatorStack && operatorStack->type == enum_Lbracket) {
            pop(&operatorStack);
          }
        }
        flag2 = 0;
      } else if (strchr(LITE_LEXEMES, *expr)) {
        if (*expr == '-') {
          if ((operatorStack && operatorStack->type == enum_Lbracket &&
               flag2 == 1) ||
              (expr[0] == '-' && !outputStack)) {
            flag = 1;
          } else {
            while (operatorStack && operatorStack->priority >= 2) {
              push(&outputStack, 0, operatorStack->priority,
                   operatorStack->type);
              pop(&operatorStack);
            }
            push(&operatorStack, 0, 2, enum_minus);
          }
        } else if (*expr == '+') {
          while (operatorStack && operatorStack->priority >= 2) {
            push(&outputStack, 0, operatorStack->priority, operatorStack->type);
            pop(&operatorStack);
          }
          push(&operatorStack, 0, 2, enum_plus);
        } else if (*expr == '/') {
          while (operatorStack && operatorStack->priority >= 3) {
            push(&outputStack, 0, operatorStack->priority, operatorStack->type);
            pop(&operatorStack);
          }
          push(&operatorStack, 0, 3, enum_division);
        } else if (*expr == '*') {
          while (operatorStack && operatorStack->priority >= 3) {
            push(&outputStack, 0, operatorStack->priority, operatorStack->type);
            pop(&operatorStack);
          }
          push(&operatorStack, 0, 3, enum_multiply);
        } else if (*expr == '^') {
          while (operatorStack && operatorStack->priority >= 4) {
            push(&outputStack, 0, operatorStack->priority, operatorStack->type);
            pop(&operatorStack);
          }
          push(&operatorStack, 0, 4, enum_exponentiation);
        } else if (*expr == '(') {
          push(&operatorStack, 0, 1, enum_Lbracket);
          flag2 = 1;
        } else if (*expr == ')') {
          while (operatorStack && operatorStack->type != enum_Lbracket) {
            push(&outputStack, 0, operatorStack->priority, operatorStack->type);
            pop(&operatorStack);
          }
          if (operatorStack && operatorStack->type == enum_Lbracket) {
            pop(&operatorStack);
          }
        }
        expr++;
      }

      else if (strchr(HARD_LEXEMES, *expr)) {
        char buff[256];
        expr += f2(expr, HARD_LEXEMES, buff);
        if (strcmp(buff, "mod") == 0) {
          while (operatorStack && operatorStack->priority >= 3) {
            push(&outputStack, 0, operatorStack->priority, operatorStack->type);
            pop(&operatorStack);
          }
          push(&operatorStack, 0, 3, enum_modulo);
        } else if (strcmp(buff, "cos") == 0) {
          push(&outputStack, 0, 5, 8);
        } else if (strcmp(buff, "sin") == 0) {
          push(&outputStack, 0, 5, 9);
        } else if (strcmp(buff, "tan") == 0) {
          push(&outputStack, 0, 5, 10);
        } else if (strcmp(buff, "acos") == 0) {
          push(&outputStack, 0, 5, 11);
        } else if (strcmp(buff, "asin") == 0) {
          push(&outputStack, 0, 5, 12);
        } else if (strcmp(buff, "atan") == 0) {
          push(&outputStack, 0, 5, 13);
        } else if (strcmp(buff, "sqrt") == 0) {
          while (operatorStack && operatorStack->priority >= 5) {
            push(&outputStack, 0, operatorStack->priority, operatorStack->type);
            pop(&operatorStack);
          }
          push(&operatorStack, 0, 5, enum_sqrt);
        } else if (strcmp(buff, "ln") == 0) {
          push(&outputStack, 0, 5, 15);
        } else if (strcmp(buff, "log") == 0) {
          push(&outputStack, 0, 5, 16);
        }
      } else {
        expr++;
      }
    }

    while (operatorStack) {
      push(&outputStack, 0, operatorStack->priority, operatorStack->type);
      pop(&operatorStack);
    }

    reverseStack(&outputStack);
    // int x = s21_validate(&outputStack);
    // // printf("%d\n", x);
    // if (x == 1) {
    stack_rpn* resultStack = NULL;

    while (outputStack) {
      switch (outputStack->type) {
        case enum_number:
          push(&resultStack, outputStack->value, 0, enum_number);
          break;
        case enum_plus: {
          double operand2 = resultStack->value;
          pop(&resultStack);
          double operand1 = resultStack->value;
          pop(&resultStack);
          push(&resultStack, operand1 + operand2, 0, enum_number);
          break;
        }
        case enum_minus: {
          double operand2 = resultStack->value;
          pop(&resultStack);
          double operand1 = resultStack->value;
          pop(&resultStack);
          push(&resultStack, operand1 - operand2, 0, enum_number);
          break;
        }
        case enum_multiply: {
          double operand2 = resultStack->value;
          pop(&resultStack);
          double operand1 = resultStack->value;
          pop(&resultStack);
          push(&resultStack, operand1 * operand2, 0, enum_number);
          break;
        }
        case enum_division: {
          double operand2 = resultStack->value;
          pop(&resultStack);
          double operand1 = resultStack->value;
          pop(&resultStack);
          push(&resultStack, operand1 / operand2, 0, enum_number);
          break;
        }
        case enum_exponentiation: {
          double operand2 = resultStack->value;
          pop(&resultStack);
          double operand1 = resultStack->value;
          pop(&resultStack);
          if (operand1 == 0) {
            push(&resultStack, 0, 0, enum_number);
            break;
          }
          push(&resultStack, pow(operand1, operand2), 0, enum_number);
          break;
        }
        case enum_modulo: {
          double operand2 = resultStack->value;
          pop(&resultStack);
          double operand1 = resultStack->value;
          pop(&resultStack);
          push(&resultStack, fmod(operand1, operand2), 0, enum_number);
          break;
        }
        case enum_cos: {
          pop(&outputStack);
          double operand2 = outputStack->value;
          push(&resultStack, cos(operand2), 0, enum_number);
          break;
        }
        case enum_sin: {
          pop(&outputStack);
          double operand2 = outputStack->value;
          push(&resultStack, sin(operand2), 0, enum_number);
          break;
        }
        case enum_tan: {
          pop(&outputStack);
          double operand2 = outputStack->value;
          push(&resultStack, tan(operand2), 0, enum_number);
          break;
        }
        case enum_acos: {
          pop(&outputStack);
          double operand2 = outputStack->value;
          push(&resultStack, acos(operand2), 0, enum_number);
          break;
        }
        case enum_asin: {
          pop(&outputStack);
          double operand2 = outputStack->value;
          push(&resultStack, asin(operand2), 0, enum_number);
          break;
        }
        case enum_atan: {
          pop(&outputStack);
          double operand2 = outputStack->value;
          push(&resultStack, atan(operand2), 0, enum_number);
          break;
        }
        case enum_sqrt: {
          double operand2 = resultStack->value;
          pop(&resultStack);
          push(&resultStack, sqrt(operand2), 0, enum_number);
          break;
        }
        case enum_ln: {
          pop(&outputStack);
          double operand2 = outputStack->value;
          push(&resultStack, log(operand2), 0, enum_number);
          break;
        }
        case enum_log: {
          pop(&outputStack);
          double operand2 = outputStack->value;
          push(&resultStack, log10(operand2), 0, enum_number);
          break;
        }

        default:
          break;
      }
      pop(&outputStack);
    }

    if (resultStack) {
      result = resultStack->value;
      pop(&resultStack);
    }
    s21_clear_stack(&outputStack);
    s21_clear_stack(&operatorStack);
    s21_clear_stack(&resultStack);
    return result;
  }

  else {
    return 0;
  }
}

int f2(char* expr, char* def, char* buff) {
  int count = 0;
  if (*expr == '-') {
    buff[count] = *expr;
    count++;
    expr++;
  }
  while (*expr && strchr(def, *expr)) {
    buff[count] = *expr;
    count++;
    expr++;
    buff[count] = '\0';
  }
  return count;
}
