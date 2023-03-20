#include <stdio.h>

int calc(int x, int y);

int main(void){
    int x, y, soma;

    scanf("%d", &x);
    scanf("%d", &y);

    soma = calc(x, y);

    printf("%d\n", soma);
}

int calc(int x, int y){
    int nun;
    int soma = 0;
    int a, b;

    if(x>y){
        a = y;
        b = x;
    }
    else{
        a = x;
        b = y;
    }

    nun = a;

    while(nun<=b){
        if(nun%13 != 0){
            soma += nun;
        }

        nun++;
    }

    return soma;
}