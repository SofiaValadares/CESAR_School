#include <stdio.h>
#include <stdlib.h>

struct node {
    char ch;
    struct node *next;
};

void add(struct node **head, char ch);
char remover(struct node **head);

int main(void){
    struct node *head = NULL;
    char ch;

    while((ch = getchar()) != EOF){
        while(ch != '\n'){
            if(ch == '('){
                add(&head, ch);
            }else if(ch == ')'){
                if(head == NULL || remover(&head) != '('){
                    add(&head, 'a');
                }
            }
            ch = getchar();
        }

        if(head == NULL){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }

        while(head != NULL){
            remover(&head);
        }
    }
}

void add(struct node **head, char ch){
    struct node *novo= (struct node *)malloc(sizeof(struct node));

    novo->ch = ch;
    novo->next = *head;
    *head = novo;
}

char remover(struct node **head){
    struct node *temp = *head;

    char ch = temp->ch;
    *head = (*head)->next;
    free(temp);

    return ch;
}