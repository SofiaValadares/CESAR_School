#include <stdio.h>


int main(void){
    float nun, soma = 0;
    int i = 0;

    while (i<2){
        scanf("%f", &nun);

        if(nun>=0 && nun<=10){
            soma += nun;
            i++;
        }
        else{
            printf("nota invalida\n");
        }

        nun = 0;
    }
    
    printf("media = %.2f\n", soma/2);
}