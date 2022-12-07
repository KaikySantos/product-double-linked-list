#include <stdio.h>
#include <stdlib.h>

typedef struct List_{
  struct List_ *prev;
  int value;
  struct List_ *next;
}List;

List* makeNode(int value){
  List *n = malloc(sizeof(List));
  n->prev = NULL;
  n->value = value;
  n->next = NULL;
  return n;
}

List *makeNum(List *num, int value){
  List *tmp = makeNode(value);
  tmp->next = num;
  num->prev = tmp;
  return tmp;
}

int main(void){
  List *num, *tmp;
  List *uni = makeNode(958);
  
  num = uni;
  num = makeNum(num, 979);
  num = makeNum(num, 41);
  num = makeNum(num, 20);

  tmp = num;

  while(tmp){
    printf("%03d \n", tmp->value);
    tmp = tmp->next;
  }

  printf("\n");
}