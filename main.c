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
  int i, aux, fim, tam = strlen(vet);
  char *novo = malloc((tam + 1) * sizeof(char));

  fim = tam - 1; // índice do último caracter
  for(i = 0; i < tam; i++){
      novo[fim] = vet[i];
      fim--;
  }
  novo[i] = '\0'; // finaliza a nova string
  return novo;
}

int main(void) {
  char num1[] = "1123456789";
  char num2[] = "243678";

  printf("First number: %s\n", num1);
  // printf("Second number: %s\n", num2);

  List *num, *tmp;

  List *uni = makeNode(num1[strlen(num1) - 1]-'0');
  num = uni;

  char numberAux[4] = "";
  for (int i=strlen(num1)-1; i >= 0; i--) {
    if (strlen(numberAux) < 3) {
      numberAux[strlen(numberAux)] = num1[i];
    }

    if (strlen(numberAux) == 3 || i == 0) {
      printf("- %s \n", reverseString(numberAux));
      memset(numberAux, 0, sizeof(numberAux));
    }
  }

  // tmp = num;
  // while(tmp) {
  //   printf("%d->", tmp->value);
  //   tmp = tmp->next;
  // }
  // printf("\n");
}