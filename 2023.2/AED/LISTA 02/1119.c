#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int nun;
    struct Node *ant;
    struct Node *hor;
} Node;

void addNode(Node **head, Node **tail,int N);
void vitimas(Node **head, Node **tail, int k, int m);
void imprimirNode(Node *head, int N);

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int N, k, m;

    while (1) {
        scanf("%d %d %d", &N, &k, &m);

        if (N == 0 && k == 0 && m == 0) {
            break;
        }

        addNode(&head, &tail, N);
       
        while (head != NULL && tail != NULL) {
            vitimas(&head, &tail, k, m);

            if (head != NULL && tail != NULL) {
                printf(",");
            } 
        }

        printf("\n");
    }

    return 0;
}

void addNode(Node **head, Node **tail,int N) {
    for (int i = 1; i <= N; i++) {
        Node *novo = (Node*)malloc(sizeof(Node));
        novo->nun = i;
        

        if (*head == NULL) {
            *head = novo;
            novo->hor = *head;
            novo->ant = *head;
            *tail = *head;
        } else {
            (*tail)->hor = novo;
            novo->ant = *tail;

            (*head)->ant = novo;
            novo->hor = *head;

            *tail = novo;
        }
    }
}

Node *horario(Node *head, int k) {
    for (int i = 1; i < k; i++) {
        head = head->hor;
    }

    return head;
}

Node *antiHoraio(Node *tail, int m) {
    for (int i = 1; i < m; i++) {
        tail = tail->ant;
    }

    return tail;
}

void removerNode(Node **head, Node *node) {
    *head = node->hor;
    
    if (*head == node) {
        free(node);
        *head = NULL;
        return;
    }

    node->hor->ant = node->ant;
    node->ant->hor = node->hor;
    free(node);
}

void vitimas(Node **head, Node **tail, int k, int m) {
    Node *horario_ = horario(*head, k);
    Node *anti_horario_ = antiHoraio(*tail, m);
    
    if (horario_ == anti_horario_) {
        printf("%3d", horario_->nun);
        removerNode(head, horario_);

        if (*head == NULL) {
            *tail = NULL;
            return;
        } 
        
        *tail = (*head)->ant;  
    } else {
        printf("%3d%3d", horario_->nun, anti_horario_->nun);
        removerNode(head, horario_);

        if (*head == NULL) {
            *tail = NULL;
            return;
        } 
            
        if (*head == anti_horario_) {
            *head = (*head)->hor;
        } 

        removerNode(tail, anti_horario_);
        
        if (*tail == NULL) {
            *head = NULL;
            return;
        } 
        
        *tail = (*tail)->ant; 
    }  
}

