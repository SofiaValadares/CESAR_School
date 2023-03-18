#include <stdio.h>

int main(void){
    int n, x, y;

    scanf("%d", &n);

    while (n!=0){
        scanf("%d %d", &x, &y);

        if(y != 0){
            printf("%.1f\n", (float) x/y);
        }
        else{
            printf("divisao impossivel\n");
        }
        
        n -= 1;
    }
    
}