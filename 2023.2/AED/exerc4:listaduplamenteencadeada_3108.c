#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor; //valor presente no elemento da lista
    struct Node *prox; //aponta para o proximo elemento da lista, se este for o ultimo aponta para NULL
    struct Node *ant; //aponta para o elemento anterior da lista, se este for o primeiro aponta para NULL
} Node; 

void countElementos(Node *head, int valor);
void addElemento(Node **head, int valor);
void removeElemento(Node **head);

void imprimir(Node *head) {
    while(head != NULL) {
      printf("%d -> ",head->valor);
      head = head->prox;
    }
    printf("NULL\n");
}

void imprimirInverso(Node *head) {
  Node *aux = head;
  while(aux->prox != NULL)
    aux=aux->prox;

  while(aux != NULL) {
    printf("%d ->",aux->valor);
    aux = aux->ant;
  }
  printf("NULL\n");
}

int main(){
    Node *head = NULL;

    addElemento(&head, 2);
    imprimir(head);

    addElemento(&head, 4);

    addElemento(&head, 3);

    addElemento(&head, 5);
    imprimir(head);


    countElementos(head, 2);
    countElementos(head, 4);
    countElementos(head, 3);
    countElementos(head, 5);

    removeElemento(&head);
    removeElemento(&head);
    imprimir(head);


    return 0;
}

void countElementos(Node *head, int valor){
    Node *head2 = NULL;
    int countAntes = 0;
    int countDepois = 0;

    if(head != NULL){
        while(head != NULL && head->valor != valor){
            head = head->prox;
        }

        head2 = head;
    }

    if(head != NULL){
        head = head->prox;
        while(head != NULL){
            countAntes++;
            head = head->prox;
        }
    }

    if(head2 != NULL){
        head2 = head2->ant;
        while(head2 != NULL){
            countDepois++;
            head2 = head2->ant;
        }
    }

    /*if(head != NULL){
        while(head != NULL && head->valor != valor){
            countAntes++;
            head = head->prox;
        }

        if(head != NULL){
            head = head->prox;

            while(head != NULL){
                countDepois++;
                head = head->prox;
            }            
        }

    }*/

    printf("Quantidade de valores antes: %d\n", countAntes);
    printf("Quantidade de valores depois: %d\n", countDepois);
}

void addElemento(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    Node *n = *head;

    novo->valor = valor;
    novo->prox = NULL;

    if(*head == NULL){
        *head = novo;
        (*head)->ant = NULL;
    }
    else{
        while(n->prox != NULL){
            n = n->prox;
        }
        novo->ant = n;
        n->prox = novo;
    }
}

void removeElemento(Node **head){
    Node *temp;
    Node *n = *head;

    if(*head != NULL){
        if((*head)->prox == NULL){
            free(*head);
            *head = NULL;
        }
        else{
            while(n->prox != NULL){
                n = n->prox;
            }

            temp = n;
            n = n->ant;
            n->prox = NULL;
            free(temp);
        }       
    }

}