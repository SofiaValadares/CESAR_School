#include <stdio.h>

int main(void){
    int nun = 0;
    int alcool = 0;
    int gasolina = 0;
    int diesel = 0;

    while (nun != 4){
        nun = 0;
        scanf("%d", &nun);

        if(nun == 1){
            alcool++;
        }
        else if(nun == 2){
            gasolina++;
        }
        else if(nun == 3){
            diesel ++;
        }
    }

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", alcool);
    printf("Gasolina: %d\n", gasolina);
    printf("Diesel: %d\n", diesel);
    
}