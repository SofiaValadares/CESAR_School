#include <stdio.h>

int main(void){
    int n[10];

    scanf("%d", &n[0]);

    for(int i=1; i<10; i++){
        n[i] = n[i-1]*2;
    }

    for(int i=0; i<10; i++){
        printf("N[%d] = %d\n", i, n[i]);
    }
}