#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char ch;
    struct Node *next;
}Node;

void incerirElemento(Node **head, char ch_func);
void removerProximoNo(Node **head);
int buscarDiamante(Node **head); 
void imprimir(Node *head);


int main(){
    int N;

    scanf("%d\n", &N);

    for(int n = 0; n < N; n++){
        Node *headPilha = NULL;
        int count = 0;

        char ch;
        ch = getchar();

        while (ch != '\n') {
            if (ch != '.') {
               incerirElemento(&headPilha, ch); 
            }
            
            ch = getchar();
        }

        while (buscarDiamante(&headPilha) == 1) {
            count++;
        }

        printf("%d\n", count);
        
    }
    return 0;
}

void imprimir(Node *head) {
  while (head != NULL) {
    printf("%c", head->ch);
    head = head->next;
  }
  printf("\n");
}

void incerirElemento(Node **head, char ch_func){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->ch = ch_func;

    if (*head == NULL) {
        *head = novo;
        (*head)->next = NULL;
    } else {
        novo->next = *head;
        *head = novo;
    }
}

int buscarDiamante(Node** head) {
    Node *n = *head;
    Node *ant = NULL;
    Node *temp;

    while (n != NULL && n->next != NULL) {
        if (n->ch == '>' && n->next->ch == '<') {
            if(ant == NULL){
                temp = *head;
                *head = (*head)->next->next;
            } else {
                temp = n;
                ant->next = n->next->next;
                n = ant;
            }
            free(temp);
            return 1;
        }
        ant = n;
        n = n->next;
    }

    return 0;
}