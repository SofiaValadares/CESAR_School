#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
} Node;

void addNumFila(Node **head, Node **tail, int num);
void addNumPilha(Node **headPilha, Node *head);
void printFila(Node *head);

int main(){
    Node *headFila1 = NULL;
    Node *tailFila1 = NULL;

    Node *headFila2 = NULL;
    Node *tailFila2 = NULL;

    Node *headPilha = NULL;

    addNumFila(&headFila1, &tailFila1, 4);
    addNumFila(&headFila1, &tailFila1, 6);
    addNumFila(&headFila1, &tailFila1, 13);
    addNumFila(&headFila1, &tailFila1, 11);
    addNumFila(&headFila1, &tailFila1, 7);
    addNumFila(&headFila1, &tailFila1, 5);
    addNumFila(&headFila1, &tailFila1, 3);
    addNumFila(&headFila1, &tailFila1, 15);
    addNumFila(&headFila1, &tailFila1, 16);
    addNumFila(&headFila1, &tailFila1, 21);

    addNumFila(&headFila2, &tailFila2, 14);
    addNumFila(&headFila2, &tailFila2, 16);
    addNumFila(&headFila2, &tailFila2, 23);
    addNumFila(&headFila2, &tailFila2, 21);
    addNumFila(&headFila2, &tailFila2, 17);
    addNumFila(&headFila2, &tailFila2, 15);
    addNumFila(&headFila2, &tailFila2, 13);
    addNumFila(&headFila2, &tailFila2, 25);
    addNumFila(&headFila2, &tailFila2, 26);
    addNumFila(&headFila2, &tailFila2, 31);

    addNumPilha(&headPilha, headFila1);
    addNumPilha(&headPilha, headFila2);
    printFila(headFila1);
    printFila(headFila2);
    printFila(headPilha);
    return 1;
}

void printFila(Node *head) {
  while (head != NULL) {
    printf("%d-> ", head->num);
    head = head->next;
  }
  printf("NULL \n");
}

void addNumFila(Node **head, Node **tail, int num){
    Node *novo = (Node*)malloc(sizeof(Node));

    if (novo != NULL) {
        novo->num = num;
        novo->next = NULL;
    }

    if (*head == NULL) {
        *head = novo;
        *tail = novo;
    } else {
        (*tail)->next = novo;
        *tail = novo;
    }
}

void addNumPilha(Node **headPilha, Node *head){
    Node *n = head;

    while(n != NULL){
        Node *novo = (Node*)malloc(sizeof(Node));
        if (novo != NULL) {
            novo->num = n->num;
            novo->next = *headPilha; 
            *headPilha = novo; 
        }
        
        n = n->next;
    }
}
