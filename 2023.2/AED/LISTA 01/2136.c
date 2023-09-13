#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char nome[51];
    struct Node* next;
} Node;

typedef struct Fila {
    Node *head;
    Node *tail;
} Fila;

int lerOpcao();
void addNode(Fila **fila, char nome[51]);
int verificarPresenca(Fila *fila, char nome[51]);
void imprimir(Fila *fila);

int main() {
    Fila *filaYES = NULL;
    Fila *filaNO = NULL;

    char amigo_habay[51]; 
    amigo_habay[0] ='\0';
    
    while (1) {
        char nome[51];
        scanf("%s", nome);

        if (strcmp("FIM", nome) == 0) {
            break;
        }

        int opcao = lerOpcao();

        if (opcao) {
            if (verificarPresenca(filaYES, nome)) {
                addNode(&filaYES, nome);

                if (amigo_habay[0] == '\0' || strlen(nome) > strlen(amigo_habay)) {
                    amigo_habay[0] = '\0';
                    strcpy(amigo_habay, nome);
                }                      
            }
        } else {
            addNode(&filaNO, nome);
        }
    }

    imprimir(filaYES);
    imprimir(filaNO);

    if (amigo_habay[0] != '\0') {
        printf("\nAmigo do Habay:\n");
        printf("%s\n", amigo_habay);
    }

    return 0;
}

int lerOpcao(){
    char opcaoLinha[4];

    scanf(" %[^\n]", opcaoLinha);

    if (strcmp("YES", opcaoLinha) == 0) {
        return 1;
    } else if (strcmp("NO", opcaoLinha) == 0) {
        return 0;
    } else {
        return 2;
    }
}

void addNode(Fila **fila, char nome[51]) {
    Node *novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->nome, nome);
    novo->next = NULL;


    if (*fila == NULL) {
        *fila = (Fila*)malloc(sizeof(Fila));
        (*fila)->head = novo;
        (*fila)->tail = (*fila)->head;
    } else {
        Node *anterior = NULL;
        Node *atual = (*fila)->head;

        while (atual != NULL && (strcmp(novo->nome, atual->nome) > 0 || (strcmp(novo->nome, atual->nome) == 0))) {
            anterior = atual;
            atual = atual->next;
        }

        if (anterior == NULL) {
            novo->next = (*fila)->head;
            (*fila)->head = novo;
        } else {
            anterior->next = novo;
            novo->next = atual;
        }
    }
}

int verificarPresenca(Fila *fila, char nome[51]) {
    if (fila == NULL) {
        return 1;
    }

    Node *head = fila->head;

    while (head != NULL) {
        if (strcmp(head->nome, nome) == 0) {
            return 0;
        }
        head = head->next;
    }

    return 1;
}

void imprimir(Fila *fila) {
    if (fila != NULL) {
        Node *head = fila->head;

        while (head != NULL) {
            printf("%s\n", head->nome);
            head = head->next;
        }
    }
}
