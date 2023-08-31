#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    char nome [30];
    struct Node *prox;
} Node;

void enqueue(Node **head, Node **tail, int n, char nome[30]);
int dequeue(Node **head, Node **tail);
void printFila(Node *head);
int tamanho(Node *head);

int main() {

  Node *head = NULL;
  Node *tail = NULL;

  enqueue(&head, &tail, 44, "Sofia");
  enqueue(&head, &tail, 87, "Matheus");
  enqueue(&head, &tail, 23, "Diogo");

  printFila(head);

  printf("\nTamanho da fila: %d\n", tamanho(head));

  int n = dequeue(&head, &tail);
  printf("\nO valor retirado foi %d\n\n", n);

  printFila(head);

  return 0;
}

// enfileira nó
void enqueue(Node **head, Node **tail, int n, char nome[30]) {
  Node *novo = (Node *)malloc(sizeof(Node));

  if (novo != NULL) {
    novo->id = n;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    
    if (*head == NULL) {
      *head = novo;
      *tail = novo;
    } else {
      (*tail)->prox = novo;
      *tail = novo;
    }
  } 
}

// retira elemento da fila
int dequeue(Node **head, Node **tail) {
  Node *aux;
  int n = 0;
  if ((*head) != NULL) {
    n = (*head)->id;
    
    aux = *head;
    *head = (*head)->prox;
    free(aux);

    if ((*head) == NULL) 
      *tail = NULL;
  }
  return n;
}

// imprime a fila
void printFila(Node *head) {
  while (head != NULL) {
    printf("%d-> ", head->id);
    head = head->prox;
  }
  printf("NULL \n");
}

// retorna o tamanho da fila
int tamanho(Node *head) {
  int cont = 0;
  while (head != NULL) {
    cont++;
    head = head->prox;
  }
  return cont;
}