#include <stdio.h>

int main(void){
    int i=1, j=7;

    while(i<=9){
        while (j>=5){
            printf("I=%d J=%d\n", i, j);
            j -= 1;
        }
        i += 2;
        j = 7;
    }
}