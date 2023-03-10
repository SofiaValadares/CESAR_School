#include <stdio.h>
 
int main() {
 
    float notaA, notaB, notaC;
    float media;

    scanf("%f", &notaA);
    scanf("%f", &notaB);
    scanf("%f", &notaC);

    media = (notaA*2 + notaB*3 + notaC*5)/10;

    printf("MEDIA = %.1f\n", media);
 
    return 0;
}