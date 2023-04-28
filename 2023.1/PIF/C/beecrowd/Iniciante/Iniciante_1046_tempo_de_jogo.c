#include <stdio.h>


int main(void){
    int a, b;
    int temp;

    scanf("%d %d", &a, &b);

    if(a>b){
        temp = (24-a)+b;
    }else if(a<b){
        temp = b-a;
    }else{
        temp = 24;
    }
    
    printf("O JOGO DUROU %d HORA(S)\n", temp);
}