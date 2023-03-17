#include <stdio.h>

int main(void){
    int i, nun;

    scanf("%d", &nun);

    for(i=1; i<=10; i++){
        printf("%d x %d = %d\n", i, nun, i*nun);
    }
}