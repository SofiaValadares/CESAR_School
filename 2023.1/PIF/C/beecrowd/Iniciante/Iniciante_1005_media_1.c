#include <stdio.h>
 
int main() {
 
    float notaA, notaB;
    double media;

    scanf("%f", &notaA);
    scanf("%f", &notaB);

    media = (notaA*3.5 + notaB*7.5)/11;

    printf("MEDIA = %.5f\n", media);
 
    return 0;
}