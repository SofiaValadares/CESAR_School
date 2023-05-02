#include <stdio.h>

int main(void){
    int t, n[1000];
    int a = 0;

    scanf("%d", &t);

    for(int i=0; i<1000; i++){
        if(a==t){
            a = 0;
        }

        n[i] = a;
        a++;
    }

    for(int i=0; i<1000; i++){
        printf("N[%d] = %d\n", i, n[i]);
    }
}