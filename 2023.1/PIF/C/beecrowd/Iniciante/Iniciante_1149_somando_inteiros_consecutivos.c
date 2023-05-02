#include <stdio.h>

int main(void){
    int a, n;
    int soma=0;

    scanf("%d", &a);

    scanf("%d", &n);
    while(n<=0){
        scanf("%d", &n);
    }

    for(int i = 0; i<=n-1; i++){
        soma += a+i;
    }

    printf("%d\n", soma);
}