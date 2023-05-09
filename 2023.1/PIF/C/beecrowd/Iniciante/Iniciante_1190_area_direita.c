#include <stdio.h>
#include <string.h>

float soma(float matriz[12][12]);

int main(void){
    float matriz[12][12];
    char opracao;
    float rels;

    scanf("%c", &opracao);

    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            scanf("%f", &matriz[i][j]);
        }
    }

    rels = soma(matriz);

    if(opracao == 'M'){
        rels = rels/30;
    }

    printf("%.1f\n", rels);
}

float soma(float matriz[12][12]){
    float calc = 0;

    for(int i=0; i<5; i++){
        for(int j=i+1; j<11-i; j++){
            calc += matriz[j][11-i];
        }
    }

    return calc;
}
