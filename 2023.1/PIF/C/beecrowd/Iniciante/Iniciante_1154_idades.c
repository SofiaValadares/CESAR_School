#include <stdio.h>

int main(void){
    int nun;
    int soma=0;
    float count=0, media;

    scanf("%d", &nun);

    while(nun>=0){
        soma+=nun;
        count++;
        scanf("%d", &nun);
    }

    media = soma/count;

    printf("%.2f\n", media);
}