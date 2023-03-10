#include <stdio.h>
 
int main() {
    float x, y, valor;

    scanf("%f", &x);
    scanf("%f", &y);

    valor = x/y;

    printf("%.3f km/l\n", valor);
    return 0;
}