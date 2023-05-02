#include <stdio.h>

int calc(int x, int y);

int main(void){
    int n, x, y;
    int soma;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        soma = calc(x, y);
        printf("%d\n", soma);
    }

}

int calc(int a, int b){
    int nun;
    int soma =0;

    if(a%2==0){
        nun = a+1;
    }else{
        nun = a;
    }

    for(int j=0; j<b; j++){
        soma += nun + (2*j);
    }

    return soma;
}