#include <stdio.h>

int main(void){
    int nun, i;
    int par = 0, impar = 0, positivo = 0, negativo = 0;

    for(i=0; i<5; i++){
        scanf("%d", &nun);

        if(nun%2 == 0){
            par ++;
        }
        else{
            impar++;
        }

        if(nun>0){
            positivo ++;
        }
        else if(nun<0){
            negativo++;
        }
    }

    printf("%d valor(es) par(es)\n", par);
    printf("%d valor(es) impar(es)\n", impar);
    printf("%d valor(es) positivo(s)\n", positivo);
    printf("%d valor(es) negativo(s)\n", negativo);
}