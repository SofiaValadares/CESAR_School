#include <stdio.h>
 
int main() {
    int tempo, velocidade, cont;
    float distancia, gasto;

    scanf("%d", &tempo);
    scanf("%d", &velocidade);
    cont = 12;

    distancia = tempo*velocidade;
    gasto = distancia/cont;

    printf("%.3f\n", gasto);
    return 0;
}