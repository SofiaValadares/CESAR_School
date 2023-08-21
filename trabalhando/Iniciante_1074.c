#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pilhas {
    char letra;
    struct pilhas *next;
};

void novo(struct pilhas **comeco, char letra);
char remover(struct pilhas **comeco);

int main(void){
    struct pilhas *comeco = NULL;
    char *conta;
    char letra;

    while((letra = getchar()) == 1){
      scanf('&s', conta);

      for(int i; conta[i]!='\0'; i++){
        if(conta[i] =='('){
          novo(&comeco, conta[i]);
        }else if(conta[i]==')'){
          if(comeco == NULL || remover(&comeco) != '('){
            novo(&comeco, conta[i]);
          }
        }
      }
        if(comeco == NULL){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }

        while(comeco != NULL){
            remover(&comeco);
        }
    }
}

void novo(struct pilhas **comeco, char letra){
    struct pilhas *novo= (struct pilhas*)malloc(sizeof(struct pilhas));

    novo->letra = letra;
    novo->next =comeco;
    comeco = novo;
}

char remover(struct pilhas **comeco){
    struct pilhas *temp = *comeco;

    char letra = temp->letra;
    comeco = (*comeco)->next;
    free(temp);

    return letra;
}