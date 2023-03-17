#include <stdio.h>

int verificador(float a, float b, float c);
float calc(float a, float b, float c);

int main(void){
    float a, b, c;

    scanf("%f %f %f", &a, &b, &c);

    calc(a, b, c);

    return 0;
}

int verificador(float a, float b, float c){
    float valores[] = {a, b, c, a, b};
    int i, ver=0;
    float valor, diferenca;

    for(i=0; i<3; i++){
        valor = valores[i];
        diferenca = valores[i+1] - valores [i+2];

        if(diferenca<0){
            diferenca = -diferenca;
        }

        if(valor<=diferenca){
            ver++;
        }
    }
    return ver;
}

float calc(float a, float b, float c){
    int ver;
    float calc;

    ver = verificador(a, b, c);

    if(ver == 0){
        calc = a+b+c;
        printf("Perimetro = %.1f\n", calc);
    }
    else{
        calc = ((a+b)*c)/2;
        printf("Area = %.1f\n", calc);
    }

    return 0;
}