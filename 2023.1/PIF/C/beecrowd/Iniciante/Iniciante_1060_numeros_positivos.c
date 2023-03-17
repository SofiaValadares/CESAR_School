#include <stdio.h>

int main(void){
    float nun;
    int count = 0;
    int i;

    for(i=0; i<6; i++){
        scanf("%f", &nun);

        if(nun>0){
            count++;
        }

        nun = 0;
    }

    printf("%d valores positivos\n", count);
    return 0;
}