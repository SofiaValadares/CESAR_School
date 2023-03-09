#include <stdio.h>

int main(){

    int lanche, quantidade;
    float valor;

    scanf("%d %d", &lanche, &quantidade);

    if(lanche == 1){
        valor = quantidade*4;
    }
    else if(lanche == 2){
        valor = quantidade*4.5;
    }
    else if(lanche == 3){
        valor = quantidade*5;
    }
    else if(lanche == 4){
        valor = quantidade*2;
    }
    else{
        valor = quantidade*1.5;
    }

    printf("Total: R$ %.2f\n", valor);
    
    return 0;
}