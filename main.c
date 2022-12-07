#include <stdio.h>
#include <stdlib.h>

typedef struct List_ {
  struct List_ *prev;
  int value;
  struct List_ *next;
} List;

List* makeNode(int value) {
  List *n = malloc(sizeof(List));
  n->prev = NULL;
  n->value = value;
  n->next = NULL;
  return n;
}

List *makeNum(List *num, int value) {
  List *tmp = makeNode(value);
  tmp->next = num;
  num->prev = tmp;
  return tmp;
}

int main(void) {
  List *num1, *tmp1, *num2, *tmp2;

  List *uni1 = makeNode(8);
  num1 = uni1;
  num1 = makeNum(num1, 9);
  tmp1 = num1;

  List *uni2 = makeNode(5);
  num2 = uni2;
  num2 = makeNum(num2, 4);
  tmp2 = num2;

  printf("One: \n");
  while (tmp1) {
    printf("%d \n", tmp1->value);
    tmp1 = tmp1->next;
  }

  printf("Two: \n");
  while (tmp2) {
    printf("%d \n", tmp2->value);
    tmp2 = tmp2->next;
  }

  printf("\n");
}