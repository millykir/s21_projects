#include "s21_calc.h"

stack_rpn *createNode(double value, int priority, type_t type) {
  stack_rpn *node = (stack_rpn *)malloc(sizeof(stack_rpn));
  if (node == NULL) {
    exit(1);
  }
  node->value = value;
  node->priority = priority;
  node->type = type;
  node->NEXT = NULL;
  return node;
}

void push(stack_rpn **stack, double value, int priority, type_t type) {
  stack_rpn *newNode = createNode(value, priority, type);
  newNode->NEXT = *stack;
  *stack = newNode;
}

void pop(stack_rpn **stack) {
  stack_rpn *tmp = *stack;
  *stack = tmp->NEXT;
  free(tmp);
}

int isEmpty(stack_rpn **stack) { return *stack == NULL; }
int isisEmpty(stack_rpn *stack) { return stack == NULL; }

void s21_clear_stack(stack_rpn **stack) {
  stack_rpn *current = *stack;
  stack_rpn *next;

  while (current != NULL) {
    next = current->NEXT;
    free(current);
    current = next;
  }

  *stack = NULL;
}
