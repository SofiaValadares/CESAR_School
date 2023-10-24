#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char nome[31];
    int nun;
    struct Node *ant;
    struct Node *hor;
} Node;

void addNode(Node **head);
int sent(int nun);
int removeNode(Node **head, int nun);

int main() {
    while (1) {
        Node *head = NULL;

        int N;
        scanf("%d", &N);

        if (!N) {
            break;
        }

        for (int i = 0; i < N; i++) {
            addNode(&head);
        }

        int nun = head->nun;
        
        if (sent(nun)) {
            head = head->hor;
        } else {
            head = head->ant;
        }

        for (int i = 0; i < N-1; i++) {
            nun = removeNode(&head, nun);
        }

        printf("Vencedor(a): %s\n", head->nome);
    }
}

void addNode(Node **head) {
    Node *novo = (Node*)malloc(sizeof(Node));

    scanf("%31s %d", novo->nome, &novo->nun);
    
    if (*head == NULL) {
        *head = novo;
        novo->ant = *head;
        novo->hor = *head;
    } else {
        Node *tail = (*head)->ant;
        tail->hor = novo;
        novo->ant = tail;
        novo->hor = *head;
        (*head)->ant = novo;
    }
}

int sent(int nun) {
    return !(nun % 2);
}

Node *horario(Node *head, int nun) {
    for (int i = 0; i < nun; i++) {
        head = head->hor;
    }

    return head;
}

Node *antHorario(Node *head, int nun) {
    for (int i = 0; i < nun; i++) {
        head = head->ant;
    }

    return head;
}

int removeNode(Node **head, int nun) {
    Node *remove = NULL;

    if (sent(nun)) {
        remove = horario(*head, nun);
    } else {
        remove = antHorario(*head, nun);
    }

    Node *hor = remove->hor;
    Node *ant = remove->ant;

    hor->ant = ant;
    ant->hor = hor;

    nun = remove->nun;
    
    if (sent(nun)) {
        *head = hor;
    } else {
        *head = ant;
    }

    free(remove);

    return nun;
}