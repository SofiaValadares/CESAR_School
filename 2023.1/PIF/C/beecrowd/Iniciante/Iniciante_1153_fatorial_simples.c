#include <stdio.h>

int fatorial(int n);

int main(void){
    int nun;
    int fat;

    scanf("%d", &nun);

    fat = fatorial(nun);

    printf("%d\n", fat);
}

int fatorial(int n){
    int rels = n;

    for(int i=1; i<n; i++){
        rels = rels*(n-i);
    }

    return rels;
}