#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  char num1[] = "154789";
  char num2[] = "243678";

  printf("First number: %s\n", num1);
  printf("Second number: %s\n", num2);

  char newNumber[] = "";

  for (int i=0; i < strlen(num1); i++) {
    newNumber = num1[i];
    printf("%s \n", newNumber);
  }
}