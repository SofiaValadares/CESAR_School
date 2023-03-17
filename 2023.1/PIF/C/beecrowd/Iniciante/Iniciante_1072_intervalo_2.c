#include <stdio.h>

int main(void){
    int n, x, i;
    int dentro = 0, fora = 0;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &x);

        if(x>=10 && x<=20){
            dentro++;
        }
        else{
            fora++;
        }
    }

    printf("%d in\n", dentro);
    printf("%d out\n", fora);
}