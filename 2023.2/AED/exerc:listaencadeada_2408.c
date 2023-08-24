#include <stdio.h>
#include <stdlib.h>

struct node{
    int nun;
    struct node *next;
};

int valor_na_lista(struct node *head, int valor);
void inserir_valor(struct node **head, int valor);
void remover_ultimo_valor(struct node **head);

void imprimir_node(struct node *lista){
    struct node *n = lista;


    while(n!=NULL){
        printf("%d ", n->nun);
        n = n->next;
    }
    printf("\n");

}


int main(){
    struct node *head = NULL;

    inserir_valor(&head, 1);

    imprimir_node(head);

    inserir_valor(&head, 2);

    imprimir_node(head);

    inserir_valor(&head, 3);

    imprimir_node(head);

    int a = valor_na_lista(head, 3);
    int b = valor_na_lista(head, 5);

    printf("%d %d\n", a, b);

    remover_ultimo_valor(&head);

    imprimir_node(head);

    remover_ultimo_valor(&head);

    imprimir_node(head);

    remover_ultimo_valor(&head);

    imprimir_node(head);


}

int valor_na_lista(struct node *head, int valor){
    struct node *n = head;

    if(head==NULL){
        return 0;
    }

    while(n != NULL){
        if(n->nun == valor){
            return 1;
        }
        n = n->next;
    }

    return 0;
}

void inserir_valor(struct node **head, int valor){
    struct node *novo= (struct node *)malloc(sizeof(struct node));
    struct node *n = *head;

    novo->nun=valor;
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
    }
    else{
        while(n->next != NULL){
            n = n->next;
        }
        n->next = novo;
    }
};

void remover_ultimo_valor(struct node **head){
    struct node *n = *head;
    struct node *temp;

    if(*head!=NULL){
        if(n->next==NULL){
            free(n);
            *head = NULL;
        }
        else{
            while(n->next->next != NULL){
                n = n->next;
            }
            temp = n->next;
            n->next = NULL;
            free(temp);            
        }

    }
}