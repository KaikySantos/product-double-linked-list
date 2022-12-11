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

char* reverseString(char vet[]){
  int i, aux, end, length = strlen(vet);
  char *new = malloc((length + 1) * sizeof(char));

  end = length - 1;
  for(i = 0; i < length; i++){
      new[end] = vet[i];
      end--;
  }
  new[i] = '\0';
  return new;
}

List *makeList(char number[]) {
  List *num, *tmp;
  List *uni = NULL;
  
  char numberAux[2] = "";
  for (int i=strlen(number)-1; i >= 0; i--) {
    if (strlen(numberAux) < 1) {
      numberAux[strlen(numberAux)] = number[i];
    }

    if (strlen(numberAux) == 1 || i == 0) {
      int newNumber = atoi(reverseString(numberAux));

      if (uni == NULL) {
        uni = makeNode(newNumber);  
        num = uni;
      } else {
        num = makeNum(num, newNumber);
      }

      memset(numberAux, 0, sizeof(numberAux));
    }
  }

  return num;
}

void printList(List *list) {
  List *tmp;
  tmp = list;
  while(tmp) {
    printf("%d", tmp->value);
    tmp = tmp->next;

    if (tmp != NULL) {
      printf(" <-> ");
    }
  }
  printf("\n");
}

int multiplyTwoLists(List* list1, List* list2) {
  int n1 = 0, n2 = 0;

  while (list1 || list2) {
    if (list1) {
      n1 = list1->value + ((n1)*10);
      list1 = list1->next;
    }

    if (list2) {
      n2 = list2->value + ((n2)*10);
      list2 = list2->next;
    }
  }

  return n1 * n2;
}

int main(void) {
  char result[] = "";
  char num1[] = "13";
  char num2[] = "67";

  List *number1, *number2, *res;

  printf("First number: ");
  number1 = makeList(num1);
  printList(number1);

  printf("Second number: ");
  number2 = makeList(num2);
  printList(number2);

  int product = multiplyTwoLists(number1, number2);
  sprintf(result, "%d", product);
  printf("Result: ");
  res = makeList(result);
  printList(res);
}