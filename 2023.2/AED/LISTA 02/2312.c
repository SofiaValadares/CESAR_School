#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char nome[51];
    int ouro;
    int prata;
    int bronze;
    struct Node *prox;
    struct Node *ant;
} Node;

//typedef int (*Func)(Node*, Node*);

void addNode(Node **head);
void BobbleSort(Node **head);
void imprimirNode(Node *head);

int main() {
    int n;
    scanf("%d", &n);

    Node *head = NULL;

    for (int N = 0; N < n; N++) {
        addNode(&head);
    }

    BobbleSort(&head);

    imprimirNode(head);

    return 0;
}

Node *novoNode() {
    Node *novo = (Node*)malloc(sizeof(Node));

    scanf("%51s %d %d %d", novo->nome, &novo->ouro, &novo->prata, &novo->bronze);

    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

void addNode(Node **head) {
    Node *novo = novoNode();

    if (*head == NULL) {
        *head = novo;
    } else {
        novo->prox = *head;
        (*head)->ant = novo;
        *head = novo;
    }
}

int medalhas(Node *atual, Node *prox) {
    return atual->ouro < prox->ouro || 
    (atual->ouro == prox->ouro && atual->prata < prox->prata) || 
    (atual->ouro == prox->ouro && atual->prata == prox->prata && atual->bronze < prox->bronze) ||
    (atual->ouro == prox->ouro && atual->prata == prox->prata && atual->bronze == prox->bronze && (strcmp(atual->nome, prox->nome) > 0));
}

void BobbleSort(Node **head) {
    if (*head == NULL || (*head)->prox == NULL) {
        return; 
    }
    
    int troca;

    do {
        troca = 0;
        Node *atual = *head;
        Node *anterior = NULL;

        while (atual != NULL && atual->prox != NULL) {
            Node *prox = atual->prox;

            if (medalhas(atual, prox)) {
                if (anterior != NULL) {
                    anterior->prox = prox;
                } else {
                    *head = prox;
                }

                atual->prox = prox->prox;
                prox->prox = atual;
                prox->ant = anterior;
                atual->ant = prox;

                if (atual->prox != NULL) {
                    atual->prox->ant = atual;
                }

                troca = 1;
            }

            anterior = atual;
            atual = atual->prox;
        }
    } while(troca);
}

void imprimirNode(Node *head) {
    while (head != NULL) {
        printf("%s %d %d %d\n", head->nome, head->ouro, head->prata, head->bronze);
        head = head->prox;
    }
}