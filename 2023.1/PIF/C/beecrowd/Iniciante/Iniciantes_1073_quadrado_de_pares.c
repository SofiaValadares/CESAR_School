#include <stdio.h>

int main(void){
    int nun = 2, valor;
    int quadrado;

    scanf("%d", &valor);

    while(nun<=valor){
        quadrado = nun*nun;
        printf("%d^2 = %d\n", nun, quadrado);

        nun += 2;
    }
}