#include <stdio.h>

int rafael(int a, int b);
int bento(int a, int b);
int carlos(int a, int b);
int maior(int a, int b);

int main() {
    int n, i, x, y;
    int vencedor;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d %d", &x, &y);

        vencedor = maior(x,y);
        if(vencedor == 1){
            printf("Rafael ganhou\n");
        }
        else if(vencedor == 2){
            printf("Beto ganhou\n");
        }
        else{
            printf("Carlos ganhou\n");
        }
    }
    
    return 0;
}

int maior(int a, int b){
    int resl, vencedor;

    resl = rafael(a, b);
    vencedor = 1;

    if(bento(a, b)>resl){
        resl = bento(a, b);
        vencedor = 2;
    }

    if(carlos(a, b)>resl){
        vencedor = 3;
    }
    return vencedor;
}

int rafael(int a, int b){       
    return (((3*a)*(3*a)) + b*b);
}

int bento(int a, int b){
    return (2*(a*a) + (5*b)*(5*b));
}

int carlos(int a, int b){
    return (-100*a + b*b*b);
}