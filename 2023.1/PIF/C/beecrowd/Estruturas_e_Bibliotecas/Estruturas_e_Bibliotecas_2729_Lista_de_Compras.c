#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char compra[21];
    struct node *next;
};

void adicionar_node(struct node **lista, char str2[21]);
int buscar_node(struct node *lista, char str2[21]);
void imprimir_node(struct node *lista);
void delete(struct node *lista);

int main(void){
    int N, n;
    char str[20000], str2[21];
    int i, k, z;
    int str_len;
    int p;
    int temp;

    struct node *lista = NULL;

    lista = (struct node*)malloc(sizeof(struct node));
    strcpy(lista->compra, "aaaa");
    lista->next = NULL;


    scanf("%d", &N);

    for(n=0; n<N; n++){
        lista = (struct node*)malloc(sizeof(struct node));
        strcpy(lista->compra, "aaaa");
        lista->next = NULL;

        scanf("\n");
        scanf("%[^\n]s", str);

        p = 0;

        str_len = strlen(str);
        for(i=0; i<str_len; i++){
            if(str[i] == ' '){
                p++;
            }
        }
        i=0;
        p++;

        k = 0;
        for(i=0; i<p; i++){
            z = 0;

            while(str[k] != ' '){
                str2[z] = str[k];
                z++;
                k++;
            }
            str2[z] = '\0';
            k++;

            temp = buscar_node(lista, str2);
            if(temp == 0){
                adicionar_node(&lista, str2);
            }
            temp = 0;   

            str2[0] = '\0';
        }

        imprimir_node(lista);

        str[0] = '\0';
    }
}

void adicionar_node(struct node **lista, char str2[21]){
    struct node *n = *lista;
    struct node *novo = (struct node*)malloc(sizeof(struct node));

    char atual[21];

    strcpy(novo->compra, str2);

    if(*lista==NULL){
        *lista = novo;
        novo->next = NULL;
    }else{
        if(n->next!=NULL){
            strcpy(atual, n->next->compra);
        }
        while(n->next!= NULL && strcmp(str2, atual)>0){
            n = n->next;
            if(n->next!= NULL){
                strcpy(atual, n->next->compra);
            }
        }

        if(n->next == NULL){
            novo->next = NULL;
            n->next = novo;
        }else{
            novo->next = n->next;
            n->next = novo;
        }
    }
}

int buscar_node(struct node *lista, char str2[21]){
    struct node *n = lista;
    int temp = 0;
    char strn[21];

    while(n!= NULL){
        strcpy(strn, n->compra);
        if(strcmp(strn, str2) == 0){
            temp++;
        }

        n = n ->next;
        strn[0] = '\0';
    }
    return temp;
}

void imprimir_node(struct node *lista){
    struct node *n = lista;
    struct node *del;
    
    n = n->next;

    while(n->next!=NULL){
        printf("%s ", n->compra);
        del = n;
        n = n->next;
        free(del);
    }

    printf("%s\n", n->compra);
}