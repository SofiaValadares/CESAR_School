#include <stdio.h>

int main(void){
    int nun;

    scanf("%d", &nun);

    for(int i=1; i<=10000; i++){
        if(i%nun==2){
            printf("%d\n", i);
        }
    }
}