#include <stdio.h>

int main(void){
    int inter, gremio, partidas=1;
    int opcao = 0;
    int inter_vit = 0, gremio_vit = 0, empate=0;

    scanf("%d %d", &inter, &gremio);

    while(opcao != 2){
        opcao = 0;

        if(inter>gremio){
            inter_vit ++;
        }
        else if(gremio>inter){
            gremio_vit ++;
        }
        else{
            empate ++;
        }

        inter = 0;
        gremio = 0;
        
        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &opcao);

        if(opcao==1){
            scanf("%d %d", &inter, &gremio);
            partidas++;
        }
    }

    printf("%d grenais\n", partidas);
    printf("Inter:%d\n", inter_vit);
    printf("Gremio:%d\n", gremio_vit);
    printf("Empates:%d\n", empate);

    if(inter_vit>gremio_vit){
        printf("Inter venceu mais\n");
    }
    else if(gremio_vit>inter_vit){
        printf("Gremio venceu mais\n");
    }
    else{
        printf("Nao houve vencedor\n");
    }
}