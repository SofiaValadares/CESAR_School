#include <stdio.h>

int main(void){
    int nun;
    int i;

    scanf("%d", &nun);

    if(nun%2 == 0){
        nun++;
    }

    for(i=0; i<6; i++){
        printf("%d\n", nun);
        nun += 2;
    }
}