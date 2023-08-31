#include <stdio.h>

void calcular_media(int *A, int *B);

int main(){
    int A, B;

    scanf("%d", &A);
    scanf("%d", &B);

    calcular_media(&A, &B);

    printf("A = %d\n", A);
    printf("B = %d\n", B);

    return 0;
}

void calcular_media(int *A, int *B){
    int soma;

    soma = (*A + *B);
    
    if(*A > *B){
        *A = soma%2;
        *B = soma/2;
    }
    else {
        *A = soma/2;
        *B = soma%2;
    }
}