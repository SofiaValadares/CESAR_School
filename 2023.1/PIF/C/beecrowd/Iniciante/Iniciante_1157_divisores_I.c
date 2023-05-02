#include <stdio.h>

int main(void){
    int nun;
    int i;

    scanf("%d", &nun);

    for(i=1; i<=nun; i++){
        if(nun%i==0){
            printf("%d\n", i);
        }
    }
}