#include <stdio.h>

int main(void){
    int i=1, j=7, j_salvo = 5;

    while(i<=9){
        while (j>=j_salvo){
            printf("I=%d J=%d\n", i, j);
            j -= 1;
        }
        i += 2;
        j_salvo += 2;
        j = j_salvo+2;
    }
}