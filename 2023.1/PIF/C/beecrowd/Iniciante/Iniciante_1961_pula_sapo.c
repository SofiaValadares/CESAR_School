#include <stdio.h>
 
int main() {
    int p, n;
    int nun1, nun2;
    int i, dif, maior_dif=0;

    scanf("%d %d", &nun1, &nun2);

    if(nun1>=1 && nun1<=5){
        p = nun1;
    }
    if(nun2>=2 && nun2<=100){
        n = nun2;
    }
 
    int pulos[n];

    for(i=0; i<n; i++){
        scanf("%d", &nun1);
        if(nun1<=10){
            pulos[i] = nun1;
        }
    }

    for(i=1; i<n; i++){
        dif = pulos[i] - pulos[i-1];

        if(dif<0){
            dif = -dif;
        }

        if(dif>maior_dif){
            maior_dif = dif;
        }
    }

    if(maior_dif>p){
        printf("GAME OVER\n");
    }
    else{
        printf("YOU WIN\n");
    }

    return 0;
}