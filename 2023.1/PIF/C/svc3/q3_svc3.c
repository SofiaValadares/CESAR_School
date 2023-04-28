#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char nome[31];
    struct node *next;
};

int tamanho(char str[2000]);
void criar_lista(struct node **lista, char str[31]);
void adicionar(struct node **lista, char str[31], char ind[31]);
void imprimir(struct node *lista);

int main(void){
    struct node *lista = (struct node*)malloc(sizeof(struct node));
    strcpy(lista->nome, "aaaa");
    lista->next = NULL;

    char str_lista[2000];
    char str_nome[31], str_amigo[31];
    
    int tan, k;
    int i=0, j;

    scanf("%[^\n]s", str_lista);

    tan = tamanho(str_lista);
    for(k=0; k<tan; k++){
        j = 0;

        while(str_lista[i] != ' '){
            str_nome[j] = str_lista[i];
            j++;
            i++;
        }
        str_nome[j] = '\0';
        i++;
        
        criar_lista(&lista, str_nome);
        str_nome[0] = '\0';
    }

    str_lista[0] = '\0';
    i = 0;
    tan = 0;

    scanf("\n");
    scanf("%[^\n]s", str_lista);
    scanf("\n");
    scanf("%s", str_amigo);

    tan = tamanho(str_lista);
    for(k=0; k<tan; k++){
        j = 0;

        while(str_lista[i] != ' '){
            str_nome[j] = str_lista[i];
            j++;
            i++;
        }
        str_nome[j] = '\0';
        i++;

        adicionar(&lista, str_nome, str_amigo);

        str_nome[0] = '\0';
    }
    
    imprimir(lista);
}

int tamanho(char str[2000]){
    int len = strlen(str);
    int tan = 0;

    for(int i=0; i<len; i++){
        if(str[i]==' '){
            tan++;
        }
    }

    return tan+1;
}

void criar_lista(struct node **lista, char str[31]){
    struct node *n = *lista;
    struct node *novo = (struct node*)malloc(sizeof(struct node));
    strcpy(novo->nome, str);

    if(*lista == NULL){
        *lista = novo;
        novo->next = NULL;
    }else{
        while(n->next != NULL){
            n = n->next;
        }

        novo->next = NULL;
        n->next = novo;        
    }
}

void imprimir(struct node *lista){
    struct node *n = lista;
    struct node *del;
    n = n->next;

    while(n!= NULL){
        printf("%s", n->nome);
        del = n;
        if(n->next != NULL){
            printf(" ");
        }
        n = n->next;
        free(del);
    }
    printf("\n");
}

void adicionar(struct node **lista, char str[31], char ind[31]){
    struct node *n = *lista;
    struct node *novo = (struct node*)malloc(sizeof(struct node));
    strcpy(novo->nome, str);
    novo->next = NULL;
    
    if (strcmp(ind, "nao") == 0) {
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = novo;
    }else{
        while (n->next!= NULL) {
            if (strcmp(n->next->nome, ind) == 0) {
                break;
            }
            n = n->next;
        }

        if(n->next == NULL && strcmp(n->nome, ind) == 0){
            n->next = novo;
        }else{
            novo->next = n->next;
            n->next = novo;
        }
    }
}