#include <stdio.h>

int rafael(int a, int b);
int bento(int a, int b);
int carlos(int a, int b);
 
int main() {
    int x, y, maior, vencedor;

    maior = rafael(x, y);
    vencedor = 1;

    if(bento(x,y)>maior){
        maior = bento(x,y);
        vencedor = 2;
    }
    else if(carlos(x,y)>maior){
        maior = carlos(x, y);
        vencedor = 3;
    }

    if(vencedor == 1){
        printf("Rafael ganhou\n");
    }
    else if(vencedor == 2){
        printf("Beto ganhou\n");
    }
    else{
        printf("Carlos ganhou\n");
    }
    return 0;
}

int rafael(int a, int b){
    int resl;
    resl = ((3*a)*(3*a)*(3*a)) + b*b;
        
    return resl;
}

int bento(int a, int b){
    int resl;
    resl = 2*(a*a) + (5*b)*(5*b);

    return resl;
}

int carlos(int a, int b){
    int resl;
    resl = -100*a + b*b*b;

    return resl;
}