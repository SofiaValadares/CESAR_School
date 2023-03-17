#include <stdio.h>

int main(void){
    int nun, i;
    int count =0;

    for(i=0; i<5; i++){
        scanf("%d", &nun);

        if(nun%2 == 0){
            count++;
        }
    }

    printf("%d valores pares\n", count);
}