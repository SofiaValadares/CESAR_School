#include <stdio.h>

int resto(int valor, int notas);
 
int main() {
    int valor, rest;
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};

    scanf("%d", &valor);

    if (valor>0 && valor<1000000){
        printf("%d\n", valor);

        for(int i=0; i<7; i++){
            rest = resto(valor, notas[i]);
            valor -= rest;
        }
    }

    return 0;
}

int resto(int valor, int notas){
    int count;

    count = valor/notas;
    printf("%d nota(s) de R$ %d,00\n", count, notas);

    return count*notas;
}