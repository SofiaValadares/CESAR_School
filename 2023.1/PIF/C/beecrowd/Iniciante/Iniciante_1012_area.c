#include <stdio.h>
 
int main() {
    double a, b, c, pi;
    double triangulo, circulo, trapezio, quadrado, retangulo;

    scanf("%lf %lf %lf", &a, &b, &c);
    pi = 3.14159;

    triangulo = (a*c)/2;
    circulo = pi*(c*c);
    trapezio = ((a+b)*c)/2;
    quadrado = b*b;
    retangulo = a*b;

    printf("TRIANGULO: %.3lf\n", triangulo);
    printf("CIRCULO: %.3lf\n", circulo);
    printf("TRAPEZIO: %.3lf\n", trapezio);
    printf("QUADRADO: %.3lf\n", quadrado);
    printf("RETANGULO: %.3lf\n", retangulo);
    return 0;
}