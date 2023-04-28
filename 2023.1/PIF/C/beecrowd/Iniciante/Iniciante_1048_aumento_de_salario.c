#include <stdio.h>

int main(void){
    float sal, reag;
    int porc;

    scanf("%f", &sal);

    if(sal <= 400){
        porc = 15;
    }else if(sal <= 800){
        porc = 12;
    }else if(sal <= 1200){
        porc = 10;
    }else if(sal <= 2000){
        porc = 7;
    }else{
        porc = 4;
    }

    reag = (sal*porc)/100;

    printf("Novo salario: %.2f\n", sal+reag);
    printf("Reajuste ganho: %.2f\n", reag);
    printf("Em percentual: %d %%\n", porc);    
}