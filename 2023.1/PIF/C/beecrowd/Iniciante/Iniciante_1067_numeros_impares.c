#include <stdio.h>

int main(void){
    int nun, count = 1;

    scanf("%d", &nun);

    while(count<=nun){
        printf("%d\n", count);
        count+=2;
    }
    
}