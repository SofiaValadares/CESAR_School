#include <stdio.h>

int main(){
    int valores[3], ordem[3];
    int i;

    for(i=0;i<3;i++){
        scanf("%i", &valores[i]);
    }

    ordem[2] = valores[0];
    ordem[0] = valores[0];

    for(i=1; i<3;i++){
        if(valores[i]>ordem[2]){
            ordem[2] = valores[i]; 
        }
        else if(valores[i]<ordem[0]){
            ordem[0] = valores[i];
        }
    }

    for(i=0; i<3; i++){
        if(valores[i]!=ordem[0] && valores[i]!=ordem[2]){
            ordem[1] = valores[i];
        }
    }
    
    for(i=0; i<3; i++){
        printf("%d\n", ordem[i]);
    }
    printf("\n");
    
    for(i=0; i<3; i++){
        printf("%d\n", valores[i]);
    }

}