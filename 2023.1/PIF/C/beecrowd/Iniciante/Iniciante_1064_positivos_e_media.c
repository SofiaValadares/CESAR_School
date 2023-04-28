#include <stdio.h>

int main(void){
    int count=0;
    float nun, soma=0;

    for(int i=0; i<6; i++){
        scanf("%f", &nun);

        if(nun>0){
            count++;
            soma+=nun;
        }
    }

    printf("%d valores positivos\n", count);
    printf("%.1f\n", soma/count);
}