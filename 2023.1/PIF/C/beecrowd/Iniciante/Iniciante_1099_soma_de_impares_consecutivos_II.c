#include <stdio.h>

int calc(int x, int y, int nun);

int main(void){
    int n, i, x, y, nun;
    int soma = 0;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        nun = x;
        nun = calc(x, y, nun);

        if(x!=y && nun!=y){
            while(nun!=y){
                if(nun%2!=0){
                    soma+= nun;
                }
                nun = calc(x, y, nun);
            }
        }

        printf("%d\n", soma);
        soma = 0;
    }
}
int calc(int x, int y, int nun){
    if(x<y){
        nun ++;
    }
    else if(x>y){
        nun -= 1;
    }

    return nun;
}

