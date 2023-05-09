#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char voo[6];
    struct node *next;
};

void add(struct node **head, struct node **tail, char voo[6]);
void espaco(int z);
void imprimir(struct node*a, struct node*b, struct node*c, struct node*d);

int main(void){
    struct node *oeste = NULL;
    struct node *norte = NULL;
    struct node *sul = NULL;
    struct node *leste = NULL;

    struct node *oeste_tail = NULL;
    struct node *norte_tail = NULL;
    struct node *sul_tail = NULL;
    struct node *leste_tail = NULL;
    
    int nun;
    char voo[6];

    while(1){        
        scanf("%d", &nun);
        if(nun == 0){
            break;
        }

        while(scanf("A%s", voo) == 1){
            if(nun == -1){
                add(&oeste, &oeste_tail, voo);
            }else if(nun == -2){
                add(&norte, &norte_tail, voo);
            }else if(nun == -3){
                add(&sul, &sul_tail, voo);
            }else{
                add(&leste, &leste_tail, voo);
            }
        }

    }

    imprimir(oeste, sul, norte, leste);
}

void add(struct node **head, struct node **tail, char voo[6]){
    struct node *novo = (struct node*)malloc(sizeof(struct node));
    strcpy(novo->voo, voo);
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
        *tail = novo;
    }else{
        (*tail)->next = novo;
        *tail = novo;
    }
}

void espaco(int z){
    if(z!=0){
        printf(" ");
    }
}

void imprimir(struct node*a, struct node*b, struct node*c, struct node*d){
    struct node *n = a;
    struct node *m = b;
    struct node *l = c;
    struct node *k = d;
    int z = 0;

    while(n != NULL || m != NULL || l != NULL || k != NULL){
        if(n!=NULL){
            espaco(z);
            printf("A%s", n->voo);
            n = n->next;
            z++;
        }
        if(m!=NULL){
            espaco(z);
            printf("A%s", m->voo);
            m = m->next;
            z++;
        }
        if(l!=NULL){
            espaco(z);
            printf("A%s", l->voo);
            l = l->next;
            z++;
        }
        if(k!=NULL){
            espaco(z);
            printf("A%s", k->voo);
            k = k->next;
            z++;
        }
    }
    printf("\n");
}
