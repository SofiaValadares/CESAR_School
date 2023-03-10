#include <stdio.h>

float media(int a);
float porcentagem(int a, float b);

int main(){
    int c, n, i;
    float porc, med;

    scanf("%d", &c);

    for(i=0; i<c; i++){
        scanf("%d", &n);

        med = media(n);
        porc = porcentagem(n, med);

        printf("%.3f%%\n", porc);

    }

    return 0;
}

float media(int a){
    int i, sun = 0;
    int count = 0;
    int notas[a];
    float media;

    for(i=0; i<a; i++){
        scanf("%d", &notas[i]);
        sun+= notas[i];
    }

    media = sun/a;

    for(i=0; i<a; i++){
        if(notas[i]>media){
            count++;
        }
    }

    return count;
}

float porcentagem(int a, float b){
    return(100*b)/a;
}
