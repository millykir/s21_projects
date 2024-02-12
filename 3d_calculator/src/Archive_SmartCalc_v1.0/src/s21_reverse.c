#include "s21_calc.h"

void reverseStack(stack_rpn** stack) {
  stack_rpn* temp1 = NULL;
  stack_rpn* temp2 = NULL;
  double value = 0;
  int priority = 0;
  int type = 0;

  while (!isEmpty(stack)) {
    value = (*stack)->value;
    priority = (*stack)->priority;
    type = (*stack)->type;
    push(&temp1, value, priority, type);
    pop(stack);
  }

  while (!isisEmpty(temp1)) {
    value = temp1->value;
    priority = temp1->priority;
    type = temp1->type;
    push(&temp2, value, priority, type);
    pop(&temp1);
  }

  while (!isisEmpty(temp2)) {
    value = temp2->value;
    priority = temp2->priority;
    type = temp2->type;
    push(stack, value, priority, type);
    pop(&temp2);
  }
}
