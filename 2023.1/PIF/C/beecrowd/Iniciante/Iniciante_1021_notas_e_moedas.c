#include <stdio.h>

float resto(float valor, float notas);
float rest2(float valor, float notas);
 
int main() {
    float valor, rest;
    float notas[6] = {100, 50, 20, 10, 5, 2};
    float moedas[6] = {1, 0.5, 0.25, 0.1, 0.05, 0.01};

    scanf("%f", &valor);

    if (valor>0 && valor<1000000){
        printf("NOTAS:\n");

        for(int i=0; i<6; i++){
            rest = resto(valor, notas[i]);
            valor -= rest;
        }

        printf("MOEDAS:\n");

        for(int i=0; i<5; i++){
            rest = rest2(valor, moedas[i]);
            valor -= rest;
        }

        printf("%.0f moeda(s) de R$ 0.01\n", valor*100);
    }

    return 0;
}

float resto(float valor, float notas){
    int count;

    count = valor/notas;
    printf("%d nota(s) de R$ %.2f\n", count, notas);

    return count*notas;
}

float rest2(float valor, float notas){
    int count;

    count = valor/notas;
    printf("%d moeda(s) de R$ %.2f\n", count, notas);

    return count*notas;
}