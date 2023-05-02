#include <stdio.h>

int main(void){
    int x, z;
    int count=1;
    int soma;
    int nun;

    scanf("%d", &x);

    scanf("%d", &z);
    while(z<=x){
        scanf("%d", &z);
    }

    soma = x;
    nun = x+1;

    while(soma<=z){
        soma += nun;
        nun++;
        count++;
    }

    printf("%d\n", count);
}