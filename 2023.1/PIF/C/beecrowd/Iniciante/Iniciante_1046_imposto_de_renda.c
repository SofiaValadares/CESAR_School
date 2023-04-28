#include <stdio.h>

int main(void){
    float renda, impos = 0.0;
    float count, menos = 1000;
    float porc = 0.08;

    scanf("%f", &renda);
    

    if(renda<=2000){
        printf("Isento\n");
    }else{
        count = renda - 2000;

        for(int i=0; i<3; i++){

            if(count>menos && i<2){
                impos += menos*porc;
                count -= menos;
                menos += 500;
                porc += 0.1;
            }else{
                impos += count*porc;
                break;
            }
        }

        printf("R$ %.2f\n", impos);
    }

}
