#include <stdio.h>

int main(void){
    int x, y;

    scanf("%d %d", &x, &y);

    while (x!=y){
        if(x<y){
            printf("Crescente\n");
        }
        else{
            printf("Decrescente\n");
        }

        scanf("%d %d", &x, &y);
    }
    
}