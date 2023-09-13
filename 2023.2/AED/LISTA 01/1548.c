#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int media;
    struct Node *prox;
    struct Node *ant;
}Node;

void addAlunoNode(Node **head, int mediaAluno);
int* reordenarFila(Node *head, int M);
int compara(Node *head, int *ordem);

int main () {
    int N;
    scanf("%d", &N);

    for (int n = 0; n < N; n++){
        Node *head = NULL;

        int M;
        scanf("%d", &M);

        for (int m = 0; m < M; m++) {
            int mediaAluno;
            scanf("%d", &mediaAluno);

            addAlunoNode(&head, mediaAluno);
            
        }

        int *lista_reordenada = reordenarFila(head, M);

        int count = compara(head, lista_reordenada);
        printf("%d\n", count);
    }

    return 0;
}

void addAlunoNode(Node **head, int mediaAluno) {
    Node *novo = (Node*)malloc(sizeof(Node));
    Node *n = *head;

    novo->media = mediaAluno;
    novo->prox = NULL;
    
    if (*head == NULL) {
        *head = novo;
        (*head)->ant = NULL;
    } else {
        while (n->prox != NULL) {
            n = n->prox;
        }

        novo->ant = n;
        n->prox = novo;
    }
}

int* reordenarFila(Node *head, int M) {
    if (head == NULL) {
        return NULL;
    }

    int *array = (int*)malloc(M * sizeof(int));

    int i = 0;

    while (head != NULL) {
        array[i] = head->media;
        
        head = head->prox;
        i++;
    }

    for (i = 0; i < M; i++) {
        for (int j = i+1; j < M; j++) {
            if (array[i] < array[j]) {
                int temp;

                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }

    }

    return array;
}

int compara(Node *head, int *ordem) {
    int count = 0;
    int i = 0;

    while (head != NULL) {
        if (head->media == ordem[i]) {
            count++;
        }

        head = head->prox;
        i++;
    }

    return count;
}