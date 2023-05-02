#include <stdio.h>

int main(void){
    float i=0, j=1;

    while(i<=2.1){
        while (j<=3){
            printf("I=%g J=%g\n", i, j+i);
            j ++;
        }
        i += 0.2;
        j=1;
    }
}